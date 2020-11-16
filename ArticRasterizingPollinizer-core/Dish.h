#pragma once
#include "AnEffingRawDonkey.h"
#include "glm.hpp"
namespace ARP {
	class Dish {
	private:
		HellsKitchen::AnEffingRawDonkey donkey;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	public:
		Dish(HellsKitchen::AnEffingRawDonkey donkey, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
		void increasePosition(glm::vec3 pos);
		void increaseRotation(glm::vec3 rot);
		HellsKitchen::AnEffingRawDonkey getDonkey();
		glm::vec3 getPosition();
		glm::vec3 getRotation();
		glm::vec3 getScale();

	};
}