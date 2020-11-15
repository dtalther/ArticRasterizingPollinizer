#pragma once
#include "ItsEffingRaw.h"
#include <vector>
#include <iostream>

namespace ARP {
	namespace HellsKitchen {
		class WheresTheLambSauce {
		private:
			int createVAO();
			void storeDataInAttributeList(int attributenumber,float* data, int length, int coordSize);
			void unbindVAO();
			void bindIndicesBuffer(int* indicies, int length);
			std::vector<int> vaolist;
			std::vector<int> vbolist;
			std::vector<int> textures;
		public:
			ItsEffingRaw loadtoVAO(float* positions, float* textureCoords, int length, int* indices, int ilength);
			int whatIsThat(std::string filename);
			~WheresTheLambSauce();
		};
	}
}