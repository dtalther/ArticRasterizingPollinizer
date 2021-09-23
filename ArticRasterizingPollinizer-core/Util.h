#pragma once
#include <string>
#include "glm.hpp"
#include "gtx/transform.hpp"
#include "gtx/euler_angles.hpp"
namespace ARP {
	namespace Utilites {
		std::string readwholefile(std::string filename);

		glm::mat4 createTransformMatrix(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);

		int generateRandomNumber(int range);

	}
}