#pragma once
#include "Camera.h"
#include "window.h"
#include "Entity.h"
namespace ARP {
	class Player{
		private:
			//void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		public:
			Player(GLFWwindow* window);
			void move(float speed);
			//void update(float speed);
			
			GLFWwindow* window;
			Camera playerCam;

	};

}