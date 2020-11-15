#include "CookTheSpinachToOrderYouLazyCow.h"

#include "Util.h"


using namespace ARP::HellsKitchen;

CookTheSpinachToOrderYouLazyCow::CookTheSpinachToOrderYouLazyCow(std::string vfilename, std::string ffilename) {
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

CookTheSpinachToOrderYouLazyCow::~CookTheSpinachToOrderYouLazyCow() {
    stop();
    glDetachShader(programID, vID);
    glDetachShader(programID, fID);
    glDeleteShader(vID);
    glDeleteShader(fID);
    glDeleteProgram(programID);
}

void CookTheSpinachToOrderYouLazyCow::start() {
    glUseProgram(programID);
}
void CookTheSpinachToOrderYouLazyCow::stop() {
    glUseProgram(0);
}

void CookTheSpinachToOrderYouLazyCow::bindAttribute(int attribute, std::string varName) {
    const char* str = varName.c_str();
    //printf("how i do this?\n");
    glBindAttribLocation(programID,attribute,str);
}

bool CookTheSpinachToOrderYouLazyCow::compileShader(std::string code, int ID) {
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

