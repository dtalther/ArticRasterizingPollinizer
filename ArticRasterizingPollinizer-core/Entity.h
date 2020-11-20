#pragma once
#include "TexturedModel.h"
#include "glm.hpp"
namespace ARP {
	class Entity {
	private:
		HellsKitchen::TexturedModel donkey;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	public:
		Entity(HellsKitchen::TexturedModel donkey, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
		void increasePosition(glm::vec3 pos);
		void increaseRotation(glm::vec3 rot);
		void increaseScale(glm::vec3 scale);
		HellsKitchen::TexturedModel getDonkey();
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();

	};
}