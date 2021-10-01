#pragma once
#include "glm.hpp"
namespace ARP {
	class SphereCollider {
	private:
		float radius;
		glm::vec3 center;
	public:
		SphereCollider(glm::vec3 center,float radius);
		bool isColliding(SphereCollider other);
		void setRadius(float radius);
		void setCenter(glm::vec3 newCenter);
		float getRadius();
		glm::vec3 getCenter();
		glm::vec3 bounceVector(glm::vec3 myPosition, glm::vec3 theirPosition, glm::vec3 theirForward);
	};
}