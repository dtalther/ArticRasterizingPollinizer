#include "Dish.h"
using namespace ARP;
ARP::Dish::Dish(HellsKitchen::AnEffingRawDonkey donkey, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : donkey(donkey){
	//this->donkey = donkey;
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}

void ARP::Dish::increasePosition(glm::vec3 pos){
	this->position += pos;
}

void ARP::Dish::increaseRotation(glm::vec3 rot){
	this->rotation += rot;
}

HellsKitchen::AnEffingRawDonkey ARP::Dish::getDonkey()
{
	return donkey;
}

glm::vec3 ARP::Dish::getPosition()
{
	return position;
}

glm::vec3 ARP::Dish::getRotation()
{
	return rotation;
}

glm::vec3 ARP::Dish::getScale()
{
	return scale;
}
