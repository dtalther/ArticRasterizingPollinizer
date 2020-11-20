#pragma once
#include <GLFW/glfw3.h>

namespace ARP {
	namespace HellsKitchen {
		class Window {
			private:
				int width, height;
				const char* name;
				
				bool isclosed;
			public:
				Window(const char* name, int width, int height);
				~Window();
				void clear();
				void update();
				bool closed() const;
				GLFWwindow* window;
				int getwidth() { return width; };
				int getheight() { return height; };

			private:
				bool init();
		};
	}

}