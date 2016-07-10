#ifndef _TEXTURETEST1_H
#define _TEXTURETEST1_H

#include "../Shader.h"
#include "../BaseTest.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"

class MatrixTest : public BaseTest
{
public:
    MatrixTest(){
        
    }
    
    ~MatrixTest(){
        delete _shader;
        
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
    
    virtual void init();
    virtual void update();
    
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    bool keys[1024];
    
    void do_movement();
    
    void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mode);

    
protected:
    Shader* _shader = nullptr;
    GLuint VBO, VAO, EBO;
    GLuint _texture1, _texture2;
    
    
};

#endif