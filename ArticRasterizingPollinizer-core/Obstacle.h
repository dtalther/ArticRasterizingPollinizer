#pragma once
#include "Entity.h"
namespace ARP {
	class Obstacle : public Entity {
	private:
	public:
		Obstacle(Entity ent);
		//Obstacle(const Entity& ent) : Entity(ent) {};
		void detectCollision(std::vector<Entity> *pack);
	};
}