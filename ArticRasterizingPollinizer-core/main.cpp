#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <vector>
#include "window.h"
#include "Loader.h"//Loader
#include "BasicRenderer.h"//BasicRenderer
#include "BasicShader.h"//BasicShader
#include "Texture.h"//Texture
#include "TexturedModel.h"//TextureModel
#include "Entity.h"//Entity
#include "glm.hpp"
#include "Player.h"
#include "BasicShapes.h"
#include "Util.h"
#include "Obstacle.h"

/*
* ------------------------------ Citations ------------------------------
* The vast majority of the HellsKitchen namespace was done following a openGL youtube tutorial by ThinMatrix.
* The first video can be found here: https://www.youtube.com/watch?v=VS8wlS9hF8E&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP
* 
* ------------------------------ Tasks ------------------------------
* Task 1: I spawn 100+ cubes. The createCube function in BasicShapes.cpp creates an entity with cube graphics. 
* I made a RandomGenerator class in utils.cpp to produce the random numbers for the spawn. 
* The movement is done in the packTactics() function that completes task 2.
* 
* Task 2: The packTactics() function in entity.cpp is responsible for the movement of the cube entities.
* 
* Task 3: The collision I used was done with sphere colliders which can be found in SphereCollider.cpp. 
* I found the bounce vector and changed the entities forward vector to the normalized bounce vector.
*/
int main() {
	using namespace ARP;
	using namespace HellsKitchen;
	
	Window window("ARP", 1280, 720);
	glewExperimental = GL_TRUE;
	glewInit();
	Loader loader;
	BasicShader shader("resources/shaders/vertexShader.txt", "resources/shaders/fragmentShader.txt");
	BasicShader obstacleShader("resources/shaders/vertexShader.txt", "resources/shaders/fragmentSolid.txt");
	BasicRenderer renderer;
	Texture texture(loader.loadTexture("resources/textures/white.png"));
	shader.bindAttribute(0,"position");
	shader.bindAttribute(1,"texture");
	obstacleShader.bindAttribute(0, "position");
	obstacleShader.bindAttribute(1, "texture");



	
	
	float r = 0.8f, b = 0.2f, g = 0.3f;
	float count = 0.0f;
	//Entity cube = createCube(&loader, "resources/textures/white.png", glm::vec3(0,0,0));
	Player player(window.window);
	int timeloc = shader.getUniformLocation("time");
	int playerPos = shader.getUniformLocation("pos");
	Utilites::RandomGenerator generator = Utilites::RandomGenerator();
	//Background color
	//glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
	glClearColor(0,0,0, 1.0f);

	
	
	std::vector<Entity> agents;
	std::vector<Obstacle> obstacles;
	for(int i = 0;i<200;i++){

		glm::vec3 spawnPoint = glm::vec3(generator.generateRandomNumber(100), generator.generateRandomNumber(100), generator.generateRandomNumber(100));
		agents.push_back(createCube(&loader, "resources/textures/white.png",spawnPoint));
		agents[i].attachCollider();
	}
	for (int j = 0; j < 100; j++) {
		glm::vec3 spawnPoint = glm::vec3(generator.generateRandomNumber(100), generator.generateRandomNumber(100), generator.generateRandomNumber(100));
		obstacles.push_back(Obstacle(createCube(&loader, "resources/textures/original.png", spawnPoint)));
		obstacles[j].setScale(glm::vec3(3.0, 3.0, 3.0));
		obstacles[j].attachCollider();
	}
	

	while (!window.closed()) {
		//entity.increaseScale(glm::vec3(0.001, 0.001, 0.002));
		window.update();
	
		

		//glClearColor(0.4f - sin(count), 0.3f + cos(count), 0.2f + sin(1.5*count), sin(count*1.0f));

		window.clear();
		renderer.prepare();
		player.move(0.3);
		
		for (auto &ent : agents) {
			shader.start();
			shader.loadFloat(timeloc, count / 2);
			ent.packTactics(agents);
			ent.updateCollider();
			shader.loadFloat(playerPos, Utilites::playerEntityDistance(player.playerCam.position, ent.getPosition())/50);
			renderer.render(ent, shader, window.getwidth(), window.getheight(), player);
			shader.stop();
		}
		for (auto& obs : obstacles) {
			obs.detectCollision(&agents);
		}
		
		//renderer.render(bigBox, shader, window.getwidth(), window.getheight(), player);
		//obstacleShader.start();
		for (auto& obst : obstacles) {
			renderer.render(obst, obstacleShader, window.getwidth(), window.getheight(), player);
		}
		//obstacleShader
	
		count += 0.01f;

	}
	//system("PAUSE");
	return 0;
}