#pragma once
#include "glm.hpp"
namespace ARP {
	class Camera {
	private:

	public:
		Camera();
		void move(glm::vec3 target);
		void rotate(glm::vec3 target);
		glm::vec3 position;
		glm::vec3 rotation;
	};

}