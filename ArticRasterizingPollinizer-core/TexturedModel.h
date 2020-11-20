#pragma once
#include "RawModel.h"
#include "Texture.h"
namespace ARP {
	namespace HellsKitchen {
		class TexturedModel {
		public:
			TexturedModel(RawModel raw, Texture donkey);
			RawModel raw;
			Texture donkey;
		};
	}
}