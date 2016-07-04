#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

class Shader
{
public:
        // 程序ID
        GLuint Program;
        // 构造器读取并创建Shader
        Shader(const GLchar * vertexSourcePath, const GLchar * fragmentSourcePath);
        // 使用Program
        void Use();
};

#endif
