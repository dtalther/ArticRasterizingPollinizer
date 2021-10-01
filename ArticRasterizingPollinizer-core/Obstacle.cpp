#include "Obstacle.h"
#include <iostream>

ARP::Obstacle::Obstacle(Entity ent): Entity(ent){
}
void ARP::Obstacle::detectCollision(std::vector<Entity> *entityList)
{
	for (auto& member : *entityList) {
		if (this->collider.isColliding(member.getCollider())) {
			glm::vec3 bounce = this->collider.bounceVector(this->getPosition(), member.getPosition(), member.getForward());
			member.setForward(glm::normalize(bounce));
			member.increasePosition(member.getForward()* 0.5f); // nudge the entity so it doesn't get stuck in flipping the forward vector in the collider

		}
	}
}
