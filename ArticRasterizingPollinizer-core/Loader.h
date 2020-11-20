#pragma once
#include "RawModel.h"
#include <vector>
#include <iostream>

namespace ARP {
	namespace HellsKitchen {
		class Loader {
		private:
			int createVAO();
			void storeDataInAttributeList(int attributenumber,float* data, int length, int coordSize);
			void unbindVAO();
			void bindIndicesBuffer(int* indicies, int length);
			std::vector<int> vaolist;
			std::vector<int> vbolist;
			std::vector<int> textures;
		public:
			RawModel loadtoVAO(float* positions, float* textureCoords, int length, int* indices, int ilength);
			int loadTexture(std::string filename);
			~Loader();
		};
	}
}