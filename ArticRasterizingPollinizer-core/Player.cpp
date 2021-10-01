#include "Player.h"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace ARP;

ARP::Player::Player(GLFWwindow* window){
	playerCam = Camera();
	this->window = window;
	int startx, starty;
	glfwGetWindowSize(window,&startx, &starty);
	//glfwSetKeyCallback(window.window, keyCallBack);
}

void ARP::Player::move(float speed){
	int w = glfwGetKey(window, GLFW_KEY_W);
	int a = glfwGetKey(window, GLFW_KEY_A);
	int s = glfwGetKey(window, GLFW_KEY_S);
	int d = glfwGetKey(window, GLFW_KEY_D);
	int jump = glfwGetKey(window, GLFW_KEY_SPACE);
	int descend = glfwGetKey(window, GLFW_KEY_C);
	int turnright = glfwGetKey(window, GLFW_KEY_RIGHT);
	int turnleft = glfwGetKey(window, GLFW_KEY_LEFT);
	int turnup = glfwGetKey(window, GLFW_KEY_UP);
	int turndown = glfwGetKey(window, GLFW_KEY_DOWN);
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
	if (descend == GLFW_PRESS) {
		playerCam.move(playerCam.position + glm::vec3(0.0, -speed, 0.0));
	}
	/*if (turnright == GLFW_PRESS) {
		playerCam.rotate(playerCam.rotation + glm::vec3(0, 0, -0.07));
	}
	if (turnleft == GLFW_PRESS) {
		playerCam.rotate(playerCam.rotation + glm::vec3(0, 0, 0.07));
	}
	if (turnup == GLFW_PRESS) {
		playerCam.rotate(playerCam.rotation + glm::vec3(0.1,0.0, 0));
	}
	if (turndown == GLFW_PRESS) {
		playerCam.rotate(playerCam.rotation + glm::vec3(-0.1, 0.0, 0));
	}*/
}

/*void ARP::Player::update(float speed)
{
	int w = glfwGetKey(window, GLFW_KEY_W);
	int a = glfwGetKey(window, GLFW_KEY_A);
	int s = glfwGetKey(window, GLFW_KEY_S);
	int d = glfwGetKey(window, GLFW_KEY_D);
	int jump = glfwGetKey(window, GLFW_KEY_SPACE);
	int descend = glfwGetKey(window, GLFW_KEY_C);
	if (w == GLFW_PRESS) {
		playerGraphics->increasePosition(glm::vec3(0.0,0.0,-speed));
	}
	if (a == GLFW_PRESS) {
		playerGraphics->increasePosition(glm::vec3(speed, 0.0, 0.0));
	}
	if (s == GLFW_PRESS) {
		playerGraphics->increasePosition(glm::vec3(0.0, 0.0,speed));
	}
	if (d == GLFW_PRESS) {
		playerGraphics->increasePosition(glm::vec3(-speed, 0.0, 0.0));
	}
	if (jump == GLFW_PRESS) {
		playerGraphics->increasePosition(glm::vec3(0.0, speed, 0.0));
	}
	if (descend == GLFW_PRESS) {
		playerGraphics->increasePosition(glm::vec3(0.0, -speed, 0.0));
	}
}*/
