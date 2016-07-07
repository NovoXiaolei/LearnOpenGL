#ifndef _TEXTURETEST1_H
#define _TEXTURETEST1_H

#include "../Shader.h"
#include "../BaseTest.h"

class TextureTest1 : public BaseTest
{
public:
    TextureTest1(){
        init();
    }
    
    ~TextureTest1(){
        delete _shader;
        
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
    
    virtual void init();
    virtual void update();
    
protected:
    Shader* _shader = nullptr;
    GLuint VBO, VAO, EBO;
    GLuint _texture;

};

#endif