#include "Player.h"
#include <GLFW/glfw3.h>

using namespace ARP;
ARP::Player::Player(GLFWwindow* window){
	playerCam = Camera();
	this->window = window;
	//glfwSetKeyCallback(window.window, keyCallBack);
}

void ARP::Player::move(float speed){
	int w = glfwGetKey(window,GLFW_KEY_W);
	int a = glfwGetKey(window, GLFW_KEY_A);
	int s = glfwGetKey(window, GLFW_KEY_S);
	int d = glfwGetKey(window, GLFW_KEY_D);
	int jump = glfwGetKey(window, GLFW_KEY_SPACE);
	if (w == GLFW_PRESS) {
		playerCam.move(playerCam.position + glm::vec3(0.0,0.0,-speed));
	}
	if (a == GLFW_PRESS) {
		playerCam.move(playerCam.position + glm::vec3(-speed, 0.0, 0.0));
	}
	if (s == GLFW_PRESS) {
		playerCam.move(playerCam.position + glm::vec3(0.0, 0.0,speed));
	}
	if (d == GLFW_PRESS) {
		playerCam.move(playerCam.position + glm::vec3(speed, 0.0, 0.0));
	}
	if (jump == GLFW_PRESS) {
		playerCam.move(playerCam.position + glm::vec3(0.0, speed, 0.0));
	}
}

/*void keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W) {
		
	}
	if (key == GLFW_KEY_A) {

	}
	if (key == GLFW_KEY_D) {

	}
	if (key == GLFW_KEY_S) {

	}
}*/
