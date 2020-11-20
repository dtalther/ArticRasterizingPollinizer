#include "Entity.h"//Entity
using namespace ARP;
ARP::Entity::Entity(HellsKitchen::TexturedModel donkey, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : donkey(donkey){
	//this->donkey = donkey;
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

void ARP::Entity::increasePosition(glm::vec3 pos){
	this->position += pos;
}

void ARP::Entity::increaseRotation(glm::vec3 rot){
	this->rotation += rot;
}

void ARP::Entity::increaseScale(glm::vec3 scale){
	this->scale += scale;
}

HellsKitchen::TexturedModel ARP::Entity::getDonkey()
{
	return donkey;
}

glm::vec3 ARP::Entity::getPosition()
{
	return position;
}

glm::vec3 ARP::Entity::getRotation()
{
	return rotation;
}

glm::vec3 ARP::Entity::getScale()
{
	return scale;
}
