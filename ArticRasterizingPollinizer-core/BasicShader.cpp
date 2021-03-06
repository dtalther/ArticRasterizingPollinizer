#include "BasicShader.h"//BasicShader
#include "Util.h"



using namespace ARP::HellsKitchen;
using namespace std;

BasicShader::BasicShader(std::string vfilename, std::string ffilename) {
    this->vshaderCode = ARP::Utilites::readwholefile(vfilename);
	this->vID = glCreateShader(GL_VERTEX_SHADER);	
	this->fshaderCode = ARP::Utilites::readwholefile(ffilename);
	this->fID = glCreateShader(GL_FRAGMENT_SHADER);
    bool v = compileShader(vshaderCode, vID);
    bool f = compileShader(fshaderCode, fID);
    if (v && f) {
        this->programID = glCreateProgram();
        glAttachShader(programID, vID);
        glAttachShader(programID, fID);
        glLinkProgram(programID);
        glValidateProgram(programID);
    }

}

BasicShader::~BasicShader() {
    stop();
    printf("cya kid\n");
    glDetachShader(programID, vID);
    glDetachShader(programID, fID);
    glDeleteShader(vID);
    glDeleteShader(fID);
    glDeleteProgram(programID);
}

int BasicShader::getUniformLocation(std::string uniformName) {
    const char* str = uniformName.c_str();
    return glGetUniformLocation(programID, str);
}

void BasicShader::loadFloat(int location, float value) {
    glUniform1f(location,value);
}
void BasicShader::loadVector(int location, glm::vec3 vec) {
    glUniform3f(location, vec.x, vec.y, vec.z);
}
void BasicShader::loadBoolean(int location, bool value) {
    float toLoad = 0;
    if (value) {
        toLoad = 1;
    }
    glUniform1f(location,toLoad);
}
void BasicShader::loadMatrix(int location, glm::mat4 matrix) {
    glUniformMatrix4fv(location,1,false,glm::value_ptr(matrix));
}



void BasicShader::start() {
    glUseProgram(programID);
}
void BasicShader::stop() {
    glUseProgram(0);
}

void BasicShader::bindAttribute(int attribute, std::string varName) {
    const char* str = varName.c_str();
    //printf("how i do this?\n");
    glBindAttribLocation(programID,attribute,str);
}

bool BasicShader::compileShader(std::string code, int ID) {
		const char* str = code.c_str();
		glShaderSource(ID, 1, &str, NULL);
		glCompileShader(ID);
        int compiled = 0;
        glGetShaderiv(ID, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            //Getting shader compulation Error
            int infologLength = 0;
            glGetShaderiv(ID, GL_INFO_LOG_LENGTH, (GLint*)&infologLength);
            char* infoLog = (char*)malloc(infologLength);
            glGetShaderInfoLog(ID, infologLength, NULL, infoLog); // will include terminate char
            printf("(S) Shader compilation error:\n%s", infoLog);
            free(infoLog);

            glDeleteShader(ID);
            return false;
        }
        return true;
	
}

