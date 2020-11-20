#include "Camera.h"
#include <GLFW/glfw3.h>;
using namespace ARP;

ARP::Camera::Camera() {
	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
}

void ARP::Camera::move(glm::vec3 target){
	position = target;
}

void ARP::Camera::rotate(glm::vec3 target){
	rotation = target;
}
