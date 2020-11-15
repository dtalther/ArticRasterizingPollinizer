#define GLEW_STATIC
#include "YoureCookingInABurnedPanYouEffingDick.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

using namespace ARP::HellsKitchen;
void YourCookingInABurnedPanYouEffingDick::prepare() {
	//glClearColor(1,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
}
void YourCookingInABurnedPanYouEffingDick::youreBurningThe(AnEffingRawDonkey rawdonkey) {
	ItsEffingRaw food = rawdonkey.raw;
	glBindVertexArray(food.getvaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glActiveTexture(GL_TEXTURE0);
	//printf("%d",rawdonkey.donkey.getTextureID());
	glBindTexture(GL_TEXTURE_2D, rawdonkey.donkey.getTextureID());
	//printf("%d",food.getvertexcount());
	//glDrawArrays(GL_TRIANGLES, 0, food.getvertexcount());
	glDrawElements(GL_TRIANGLES,food.getvertexcount(),GL_UNSIGNED_INT,0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}