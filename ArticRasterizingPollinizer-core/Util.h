#pragma once
#include <string>
#include "glm.hpp"
#include "gtx/transform.hpp"
#include "gtx/euler_angles.hpp"
#include <random>
namespace ARP {
	namespace Utilites {
		std::string readwholefile(std::string filename);

		glm::mat4 createTransformMatrix(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);

		class RandomGenerator {
		private:
		public:
			int generateRandomNumber(int range);

		};

		float playerEntityDistance(glm::vec3 myPosition, glm::vec3 theirPosition);

	}
}