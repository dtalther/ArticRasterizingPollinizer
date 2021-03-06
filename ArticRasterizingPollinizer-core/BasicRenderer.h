#pragma once
#include "RawModel.h"
#include "TexturedModel.h"
#include "Entity.h"
#include "BasicShader.h"
#include "Player.h"
namespace ARP {
	namespace HellsKitchen {
		class BasicRenderer {
		private:
			const float FOV = 70;
			const float NEAR_PLANE = 0.1;
			const float FAR_PLANE = 1000;
			glm::mat4 createProjectionMatrix(int width, int height);
		public:
			void prepare();
			void render(Entity plate, BasicShader &spinach, int width,int height, BasicShader &shader, Player &player);

			

		};
	}
}