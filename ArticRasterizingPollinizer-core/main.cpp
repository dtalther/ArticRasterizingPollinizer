#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "window.h"
#include "WheresTheLambSauce.h"
#include "YoureCookingInABurnedPanYouEffingDick.h"
#include "CookTheSpinachToOrderYouLazyCow.h"
#include "EffingDonkey.h"
#include "AnEffingRawDonkey.h"
#include "Dish.h"
#include "glm.hpp"
int main() {
	using namespace ARP;
	using namespace HellsKitchen;
	
	Window window("ARP", 1280, 720);
	glewExperimental = GL_TRUE;
	glewInit();
	WheresTheLambSauce sauce;
	YourCookingInABurnedPanYouEffingDick pan;
	CookTheSpinachToOrderYouLazyCow spinach("resources/shaders/vertexShader.txt", "resources/shaders/fragmentShader.txt");
	EffingDonkey donkey(sauce.whatIsThat("resources/textures/original.png"));
	spinach.bindAttribute(0,"position");
	spinach.bindAttribute(1,"texture");
	
	float r = 0.8f, b = 0.2f, g = 0.3f;
	float count = 0.0f;
	int const vertlength = 15;
	int const indiceslength = 9;

	float vertices[12] = {
	    -0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f, 0.5f, 0.0f//3
	  //0.5f,1.0f,0.0f//4
	};

	int indices[6] = {
	  0,1,3,
	  3,1,2,
	  //4,0,3
	};
	float textureCoords[8] = {
		0.0f,0.0f,
		0.0f,-1.0f,
		1.0f,1.0f,
		1.0f,0.0f
	};
	ItsEffingRaw lamb = sauce.loadtoVAO(vertices,textureCoords,vertlength,indices,indiceslength);
	AnEffingRawDonkey rawDonkey(lamb,donkey);
	Dish plate(rawDonkey,glm::vec3(-1,0,0), glm::vec3(1, 0, count), glm::vec3(1, 1, 1));
	int loc = spinach.getUniformLocation("transformationMatrix");
	glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
	

	while (!window.closed()) {
		Dish plate(rawDonkey, glm::vec3(0, 0, 0), glm::vec3(1, count*-1, count), glm::vec3(1, 1, 1));
		glClearColor(0.3f - sin(count), 0.3f + cos(count), 0.2f + sin(1.5*count), 1.0f);
		window.clear();
		pan.prepare();
		spinach.start();
		pan.youreBurningThe(plate,spinach,loc);
		spinach.stop();
		window.update();
		count += 0.01f;

	}
	//system("PAUSE");
	return 0;
}