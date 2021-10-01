#include "Entity.h"//Entity
#include <iostream>
using namespace ARP;
ARP::Entity::Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, glm::vec3 forward, HellsKitchen::TexturedModel texture, float velocity) : texture(texture){
	//this->texture = texture;
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	this->forward = forward;
	this->velocity = velocity;
}

void ARP::Entity::increasePosition(glm::vec3 pos){
	this->position += pos;
}

void ARP::Entity::increaseRotation(glm::vec3 rot){
	this->rotation += rot;
}

void ARP::Entity::setScale(glm::vec3 scale){
	this->scale = scale;
}

void ARP::Entity::setForward(glm::vec3 forward)
{
	this->forward = forward;
}

HellsKitchen::TexturedModel ARP::Entity::getTexture()
{
	return texture;
}

glm::vec3 Entity::getPosition()
{
	return position;
}

glm::vec3 Entity::getRotation()
{
	return rotation;
}

glm::vec3 Entity::getScale()
{
	return scale;
}

glm::vec3 ARP::Entity::getForward()
{
	return this->forward;
}

void ARP::Entity::setVelocity(float speed)
{
	this->velocity = speed;
}

SphereCollider ARP::Entity::getCollider()
{
	return this->collider;
}

void Entity::update()
{
	this->increasePosition(forward * velocity);
}

float distance(glm::vec3 myPosition, glm::vec3 theirPosition) {
	float dist = sqrt(pow((theirPosition[0] - myPosition[0]), 2.0) + pow((theirPosition[1] - myPosition[1]), 2.0) + pow((theirPosition[2] - myPosition[2]), 2.0));
	return dist;
}
void Entity::packTactics(std::vector<Entity> pack)
{
	float distanceClose = 10.0f;
	float distanceFar = 200.0f;
	glm::vec3 sumInfluence = glm::vec3(0,0,0);
	for (auto member : pack) {
		float dist = distance(this->getPosition(), member.getPosition());
		if (dist > distanceFar) {//If they are greater than this far out they should be drawn together.
			sumInfluence += (glm::normalize(member.getPosition() - this->getPosition()));
		}
		if (dist < distanceClose && dist != 0) {
			sumInfluence += (glm::normalize(this->getPosition() - member.getPosition()));
		}
	}
	if (sumInfluence != glm::vec3(0, 0, 0)) {
		glm::vec3 fw = glm::normalize(sumInfluence);
		this->forward = fw;
		this->increasePosition(this->forward * velocity);
		this->increaseRotation(this->forward * 0.1f);
	}
	else {
		this->increasePosition(this->forward * velocity);
		this->increaseRotation(this->forward * 0.1f);
	}
	


}

void ARP::Entity::attachCollider()
{
	float radius = this->scale[0];
	this->collider = SphereCollider(this->getPosition(), radius);
}


void ARP::Entity::updateCollider()
{
	if (this->collider.getRadius() != 0) {
		this->collider.setCenter(this->getPosition());
	}
}



