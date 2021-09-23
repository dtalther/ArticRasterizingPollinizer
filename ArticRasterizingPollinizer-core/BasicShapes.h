#pragma once
#include <stdlib.h>
#include "Entity.h"
#include "RawModel.h"
#include "Loader.h"
#include "Texture.h"
#include "TexturedModel.h"
namespace ARP {
	int stagger = 0;
	Entity createCube(HellsKitchen::Loader* loader, std::basic_string<char> textureSrc) {
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
		HellsKitchen::Texture texture((*loader).loadTexture(textureSrc));
		HellsKitchen::RawModel model = (*loader).loadtoVAO(vertices, textureCoords, sizeof(vertices) / sizeof(float),
			indices, sizeof(indices) / sizeof(int), sizeof(textureCoords) / sizeof(int));
		HellsKitchen::TexturedModel texModel(model, texture);
		Entity entity(glm::vec3(0+stagger, 0, 10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), texModel);
		std::cout << stagger;
		stagger++;
		return entity;


	}
}