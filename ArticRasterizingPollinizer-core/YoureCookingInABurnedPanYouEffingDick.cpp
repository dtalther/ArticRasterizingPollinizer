#define GLEW_STATIC
#include "YoureCookingInABurnedPanYouEffingDick.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "glm.hpp"
#include "Util.h"


using namespace ARP::HellsKitchen;
using namespace ARP;
void YourCookingInABurnedPanYouEffingDick::prepare() {
	//glClearColor(1,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
}
void YourCookingInABurnedPanYouEffingDick::youreBurningThe(Dish plate, CookTheSpinachToOrderYouLazyCow &spinach, int location) {
	AnEffingRawDonkey rawdonkey = plate.getDonkey();
	ItsEffingRaw food = rawdonkey.raw;
	glBindVertexArray(food.getvaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glm::mat4 transformationMatrix = ARP::Utilites::createTransformMatrix(plate.getPosition(),plate.getRotation(),plate.getScale());
	spinach.loadMatrix(location,transformationMatrix);
	//printf("%d\n", rawdonkey.donkey.getTextureID());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, rawdonkey.donkey.getTextureID());

	glDrawElements(GL_TRIANGLES,food.getvertexcount(),GL_UNSIGNED_INT,0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}