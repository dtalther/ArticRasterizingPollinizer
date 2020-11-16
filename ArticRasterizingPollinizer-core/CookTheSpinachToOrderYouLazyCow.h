#pragma once

#include <vector>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"
#include "gtc/type_ptr.hpp"


namespace ARP {
	namespace HellsKitchen {
		class CookTheSpinachToOrderYouLazyCow {
		private:
			std::string vshaderCode;
			std::string fshaderCode;
			GLuint vID;
			GLuint fID;
			GLuint programID;
			bool compileShader(std::string code, int ID);
		public:
			CookTheSpinachToOrderYouLazyCow(std::string vertexfilename, std::string fragmentfilename);
			~CookTheSpinachToOrderYouLazyCow();
			std::string vgetShaderCode() { return vshaderCode; };
			std::string fgetShaderCode() { return fshaderCode; };
			int getUniformLocation(std::string uniformName);
			void loadBoolean(int location, bool value);
			void loadFloat(int location, float value);
			void loadMatrix(int location, glm::mat4 matrix);
			void loadVector(int location, glm::vec3 vec);
			void start();
			void stop();
			void bindAttribute(int attribute, std::string varName);
			GLuint getvID() { return vID; };
			GLuint getfID() { return fID; };
			GLuint getprogramID() { return programID; };
		};
	}
}
