#include "window.h"
#include <stdio.h>

namespace ARP {
	namespace HellsKitchen {
		void windowResize(GLFWwindow* window, int width, int height);
		Window::Window(const char* name, int width, int height) {
			this->name = name;
			this->width = width;
			this->height = height;
			if (!init())
				glfwTerminate();
		}
		Window::~Window(){
			glfwTerminate();
		}
		bool Window::init() {
			if (!glfwInit()) {
				printf("Failed to init GLFW\n");
				return false;
			}
	
			window = glfwCreateWindow(width, height, name,NULL,NULL);
			if (!window) {
				glfwTerminate();
				printf("Failed to create GLFW window!");
				return false;
			}
			glfwMakeContextCurrent(window);
			glfwSetWindowSizeCallback(window, windowResize);
			return true;

		}
		void Window::clear() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		bool Window::closed() const{
			return glfwWindowShouldClose(window);
		}
		void Window::update(){
			glfwPollEvents();
			glfwGetFramebufferSize(window, &width, &height);
			//glViewport(0, 0, width, height);
			glfwSwapBuffers(window);			
		}
		void windowResize(GLFWwindow* window, int width, int height) {
			glViewport(0,0,width,height);
		}
	}
}