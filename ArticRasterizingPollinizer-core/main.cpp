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

int main() {
	using namespace ARP;
	using namespace HellsKitchen;
	
	Window window("ARP", 1280, 720);
	glewExperimental = GL_TRUE;
	glewInit();
	Loader loader;
	BasicShader shader("resources/shaders/vertexShader.txt", "resources/shaders/fragmentShader.txt");
	BasicRenderer renderer;
	Texture texture(loader.loadTexture("resources/textures/white.png"));
	shader.bindAttribute(0,"position");
	shader.bindAttribute(1,"texture");
	
	
	float r = 0.8f, b = 0.2f, g = 0.3f;
	float count = 0.0f;
	//Entity cube = createCube(&loader, "resources/textures/white.png");
	Player player(window.window);
	int timeloc = shader.getUniformLocation("time");
	glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
	std::vector<Entity> ents;
	std::vector<Entity*> entities;
	for(int i = 0;i<4;i++){
		ents.push_back(createCube(&loader, "resources/textures/white.png"));
	}
	for (auto ent : ents) {
		entities.push_back(&ent);
	}

	

	while (!window.closed()) {
		//entity.increasePosition(glm::vec3(0.0, 0.0, 1));
		for (auto entity : entities) {
			(*entity).increasePosition(glm::vec3(0.0, -0.02, 0.02));
			(*entity).increaseRotation(glm::vec3(0.0, -0.02, 0.02));
		}
		//entity.increaseScale(glm::vec3(0.001, 0.001, 0.002));
		window.update();
		player.move(0.1);
		//glClearColor(0.4f - sin(count), 0.3f + cos(count), 0.2f + sin(1.5*count), sin(count*1.0f));

		window.clear();
		renderer.prepare();
		shader.start();
		shader.loadFloat(timeloc,count/2);
		renderer.render(entities,shader,window.getwidth(),window.getheight(),player);
		shader.stop();
	
		count += 0.01f;

	}
	//system("PAUSE");
	return 0;
}