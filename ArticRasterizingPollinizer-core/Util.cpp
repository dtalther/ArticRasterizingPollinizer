#include "Util.h"
#include <iostream>
#include <fstream>
#include <streambuf>
#include <stdlib.h>
#include <time.h>

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


int ARP::Utilites::RandomGenerator::generateRandomNumber(int range)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, range); 

	return dist(rng);
}
float ARP::Utilites::playerEntityDistance(glm::vec3 myPosition, glm::vec3 theirPosition) {
	float dist = sqrt(pow((theirPosition[0] - (myPosition[0] * -1)), 2.0) + pow((theirPosition[1] - (myPosition[1]*-1)), 2.0) + pow((theirPosition[2] - (-1*myPosition[2])), 2.0));
	/*std::cout << "--------------------------------\n";
	std::cout << theirPosition[0];
	std::cout << "\n";
	std::cout << theirPosition[1];
	std::cout << "\n";
	std::cout << theirPosition[2];
	std::cout << "\n";
	std::cout << "----------SLICE---------\n";
	std::cout << myPosition[0] * -1;
	std::cout << "\n";
	std::cout << myPosition[1] * -1;
	std::cout << "\n";
	std::cout << myPosition[2] * -1;
	std::cout << "\n Distance: ";
	std::cout << dist;
	std::cout << "\n--------------------------------\n";*/
	return dist;
}


