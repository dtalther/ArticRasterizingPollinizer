#define GLEW_STATIC
#include "Loader.h"//Loader
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace ARP::HellsKitchen;

Loader::~Loader() {
	for (GLuint vao : vaolist)
		glDeleteVertexArrays(1, &vao);
	for (GLuint vbo : vbolist)
		glDeleteBuffers(1, &vbo);
	for (GLuint texture : textures) {
		glDeleteTextures(1,&texture);
	}
}
RawModel Loader::loadtoVAO(float* positions, float* textureCoords, int length, int* indices, int ilength, int tlength) {
	int vaoID = createVAO();
	bindIndicesBuffer(indices, ilength);
	storeDataInAttributeList(0,positions,length,3);
	storeDataInAttributeList(1, textureCoords, tlength, 2);
	unbindVAO();
	RawModel sauce(vaoID, ilength);
	return sauce;

}
int ARP::HellsKitchen::Loader::loadTexture(std::string filename)
{//texture loader
	int width, height, channels;
	GLuint textureID;
	unsigned char* image = stbi_load(filename.c_str(), &width, &height, &channels, 3);

	//printf("%p",image);
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glBindTexture(GL_TEXTURE_2D, 0);
	free(image);
	return (int)textureID;

}
int Loader::createVAO() {
	GLuint vaoID = 0;
	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);
	this->vaolist.push_back(vaoID);
	return vaoID;
}
void Loader::storeDataInAttributeList(int number, float *data, int length, int coordSize) {
	GLuint vboID = 0;
	//printf("Hellllllo\n");
	//printf("%p\n", &vboID);
	glGenBuffers(1,&vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
	glBufferData(GL_ARRAY_BUFFER,length*sizeof(float),data,GL_STATIC_DRAW);
	glVertexAttribPointer(number,coordSize,GL_FLOAT,GL_FALSE,0,0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	this->vbolist.push_back(vboID);

}
void Loader::bindIndicesBuffer(int* indicies, int length) {
	GLuint vboID = 0;
	glGenBuffers(1,&vboID);
	this->vbolist.push_back(vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(int), indicies, GL_STATIC_DRAW);
}

void Loader::unbindVAO() {
	glBindVertexArray(0);
}