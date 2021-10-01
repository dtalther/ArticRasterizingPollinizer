#pragma once
#include <stdlib.h>
#include "Entity.h"
#include "RawModel.h"
#include "Loader.h"
#include "Texture.h"
#include "TexturedModel.h"
namespace ARP {
	Entity createCube(HellsKitchen::Loader* loader, std::basic_string<char> textureSrc, glm::vec3 spawn);
	Entity createSphere(HellsKitchen::Loader* loader, std::basic_string<char> textureSrc, glm::vec3 spawn);
}