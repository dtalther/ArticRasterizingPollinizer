#pragma once
#include "RawModel.h"
#include "TexturedModel.h"
#include "Entity.h"
#include "BasicShader.h"
namespace ARP {
	namespace HellsKitchen {
		class BasicRenderer {
		private:

		public:
			void prepare();
			void youreBurningThe(Entity plate, BasicShader &spinach, int location);

		};
	}
}