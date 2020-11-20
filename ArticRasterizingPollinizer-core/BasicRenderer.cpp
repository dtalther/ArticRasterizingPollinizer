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
void BasicRenderer::render(Entity plate, BasicShader &spinach,int width,int height, BasicShader &shader, Player &player) {
	TexturedModel rawdonkey = plate.getDonkey();
	RawModel food = rawdonkey.raw;
	int tloc = shader.getUniformLocation("transformationMatrix");
	int ploc = shader.getUniformLocation("projectionMatrix");
	int vloc = shader.getUniformLocation("viewMatrix");
	glm::mat4 vmatrix = ARP::Utilites::createTransformMatrix(-player.playerCam.position,-player.playerCam.rotation,-(glm::vec3(1,1,1)));
	glm::mat4 pmatrix = createProjectionMatrix(width, height);
	spinach.loadMatrix(vloc, vmatrix);
	spinach.loadMatrix(ploc, pmatrix);
	glBindVertexArray(food.getvaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glm::mat4 transformationMatrix = ARP::Utilites::createTransformMatrix(plate.getPosition(),plate.getRotation(),plate.getScale());
	spinach.loadMatrix(tloc,transformationMatrix);
	//printf("%d\n", rawdonkey.donkey.getTextureID());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, rawdonkey.donkey.getTextureID());

	glDrawElements(GL_TRIANGLES,food.getvertexcount(),GL_UNSIGNED_INT,0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}