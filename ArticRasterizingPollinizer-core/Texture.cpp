#include "Texture.h"//Texture
using namespace ARP::HellsKitchen;

Texture::Texture(int textureID) {
	this->textureID = textureID;
}
int Texture::getTextureID() {
	return textureID;
}
