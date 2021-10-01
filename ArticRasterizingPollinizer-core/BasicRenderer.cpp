#define GLEW_STATIC
#include "BasicRenderer.h"//BasicRenderer
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "glm.hpp"
#include "Util.h"


using namespace ARP::HellsKitchen;
using namespace ARP;

glm::mat4 ARP::HellsKitchen::BasicRenderer::createProjectionMatrix(int width, int height){
	glm::mat4 pmat = glm::perspective<float>(FOV,((float)width/(float)height),NEAR_PLANE,FAR_PLANE);
	return pmat;
}

void BasicRenderer::prepare() {
	//glClearColor(1,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}
void BasicRenderer::render(Entity entity, BasicShader &shader,int width,int height, Player &player) {

		TexturedModel textureModel = entity.getTexture();
		RawModel rawModel = textureModel.raw;
		shader.start();

		int tloc = shader.getUniformLocation("transformationMatrix");
		int ploc = shader.getUniformLocation("projectionMatrix");
		int vloc = shader.getUniformLocation("viewMatrix");

		glm::mat4 vmatrix = ARP::Utilites::createTransformMatrix(-player.playerCam.position, -player.playerCam.rotation, -(glm::vec3(1, 1, 1)));
		glm::mat4 pmatrix = createProjectionMatrix(width, height);

		shader.loadMatrix(vloc, vmatrix);
		shader.loadMatrix(ploc, pmatrix);

		glBindVertexArray(rawModel.getvaoID());
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glm::mat4 transformationMatrix = ARP::Utilites::createTransformMatrix(entity.getPosition(), entity.getRotation(), entity.getScale());
		shader.loadMatrix(tloc, transformationMatrix);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureModel.texture.getTextureID());

		glDrawElements(GL_TRIANGLES, rawModel.getvertexcount(), GL_UNSIGNED_INT, 0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindVertexArray(0);
		shader.stop();
}

void ARP::HellsKitchen::BasicRenderer::renderCollection(std::vector<Entity> entities, BasicShader& shader, int width, int height, Player& player)
{
	for (auto &entity : entities) {
		render(entity, shader, width, height, player);
	}
}
