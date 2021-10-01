#pragma once
#include "TexturedModel.h"
#include "glm.hpp"
#include <vector>
#include "SphereCollider.h"
namespace ARP {
	class Entity {
	protected:
		HellsKitchen::TexturedModel texture;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::vec3 forward;
		float velocity;
		SphereCollider collider = SphereCollider(glm::vec3(0,0,0),0);

	public:
		Entity(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, glm::vec3 forward, HellsKitchen::TexturedModel texture, float velocity = 0.3f);
		void increasePosition(glm::vec3 pos);
		void increaseRotation(glm::vec3 rot);
		void setScale(glm::vec3 scale);
		void setForward(glm::vec3 forward);
		HellsKitchen::TexturedModel getTexture();
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();
		glm::vec3 getForward();
		void setVelocity(float speed);
		SphereCollider getCollider();
		void update();
		void packTactics(std::vector<Entity> pack);
		void attachCollider();
		void updateCollider();
	};
}