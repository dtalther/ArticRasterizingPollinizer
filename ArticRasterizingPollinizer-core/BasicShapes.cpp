#include "BasicShapes.h"
#include "Util.h"
using namespace ARP;
Entity ARP::createCube(HellsKitchen::Loader* loader, std::basic_string<char> textureSrc, glm::vec3 spawn)
{
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
		Utilites::RandomGenerator gen = Utilites::RandomGenerator();
		float x, y, z;
		x = gen.generateRandomNumber(200);
		y = gen.generateRandomNumber(200);
		z = gen.generateRandomNumber(200);
		Entity entity(spawn, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1),glm::normalize(glm::vec3(x,y,z)), texModel, 0.3);
		return entity;

}
