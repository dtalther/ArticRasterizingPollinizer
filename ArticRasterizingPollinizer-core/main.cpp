#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "window.h"
#include "Loader.h"//Loader
#include "BasicRenderer.h"//BasicRenderer
#include "BasicShader.h"//BasicShader
#include "Texture.h"//Texture
#include "TexturedModel.h"//TextureModel
#include "Entity.h"//Entity
#include "glm.hpp"
#include "Player.h"
int main() {
	using namespace ARP;
	using namespace HellsKitchen;
	
	Window window("ARP", 1280, 720);
	glewExperimental = GL_TRUE;
	glewInit();
	Loader loader;
	BasicShader shader("resources/shaders/vertexShader.txt", "resources/shaders/fragmentShader.txt");
	BasicRenderer renderer;
	Texture texture(loader.loadTexture("resources/textures/original.png"));
	shader.bindAttribute(0,"position");
	shader.bindAttribute(1,"texture");
	
	float r = 0.8f, b = 0.2f, g = 0.3f;
	float count = 0.0f;
	int const vertlength = 15;
	int const indiceslength = 9;
	float vertices[] = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f

	};

	float textureCoords[] = {

			0,0,
			0,1,
			1,1,
			1,0,
			0,0,
			0,1,
			1,1,
			1,0,
			0,0,
			0,1,
			1,1,
			1,0,
			0,0,
			0,1,
			1,1,
			1,0,
			0,0,
			0,1,
			1,1,
			1,0,
			0,0,
			0,1,
			1,1,
			1,0
	};

	int indices[] = {
			0,1,3,
			3,1,2,
			4,5,7,
			7,5,6,
			8,9,11,
			11,9,10,
			12,13,15,
			15,13,14,
			16,17,19,
			19,17,18,
			20,21,23,
			23,21,22

	};

	/*float vertices[12] = {
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
		0.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,
		1.0f,1.0f
	};*/
	RawModel model = loader.loadtoVAO(vertices,textureCoords,sizeof(vertices)/sizeof(float),
		indices,sizeof(indices)/sizeof(int), sizeof(textureCoords)/sizeof(int));
	TexturedModel texModel(model,texture);
	Entity entity(texModel,glm::vec3(0,0,10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	Player player(window.window);
	int timeloc = shader.getUniformLocation("time");
	glClearColor(0.8f, 0.3f, 0.2f, 1.0f);
	

	while (!window.closed()) {
		//entity.increasePosition(glm::vec3(0.0, 0.0, 1));
		entity.increaseRotation(glm::vec3(0.0, 0.02,-0.02));
		//entity.increaseScale(glm::vec3(0.001, 0.001, 0.002));
		window.update();
		player.move(0.1);
		glClearColor(0.3f - sin(count), 0.3f + cos(count), 0.2f + sin(1.5*count), 1.0f);
		window.clear();
		renderer.prepare();
		shader.start();
		shader.loadFloat(timeloc,count/2);
		renderer.render(entity,shader,window.getwidth(),window.getheight(),shader,player);
		shader.stop();
	
		count += 0.01f;


	}
	//system("PAUSE");
	return 0;
}