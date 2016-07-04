#ifndef SHADER_H
#define SHADER_H


#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


class Shader{
public:
    GLuint Program;
    Shader(const GLchar * vertexSourcePath, const GLchar * fragmentSourcePath);
    void Use();
};

#endif
