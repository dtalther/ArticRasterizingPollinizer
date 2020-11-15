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


