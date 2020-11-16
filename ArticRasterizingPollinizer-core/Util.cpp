#include "Util.h"
#include <iostream>
#include <fstream>
#include <streambuf>

using namespace ARP::Utilites;

std::string ARP::Utilites::readwholefile(std::string filename) {
	std::ifstream t(filename);
	std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	return str;
}

glm::mat4 ARP::Utilites::createTransformMatrix(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale)
{
	glm::mat4 matrix = glm::identity<glm::mat4>();
	glm::mat4 newmatrix = glm::translate(matrix, translation);
	matrix *= newmatrix;
	glm::mat4 rotmatrix = glm::orientate4(rotation);
	matrix *= rotmatrix;
	glm::mat4 scalematrix = glm::scale(scale);
	matrix *= scalematrix;
	return matrix;
}


