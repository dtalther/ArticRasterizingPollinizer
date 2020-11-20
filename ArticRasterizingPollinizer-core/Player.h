#pragma once
#include "Camera.h"
#include "window.h"
namespace ARP {
	class Player{
		private:

		public:
			Player(GLFWwindow* window);
			void move(float speed);
			GLFWwindow* window;
			Camera playerCam;
	};

}