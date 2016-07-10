#ifndef _LIGHT_TEST_H_
#define _LIGHT_TEST_H_

#include "../BaseTest.h"
#include "../Shader.h"
#include "../Camera.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"

class LightTest : public BaseTest
{
public:
    ~LightTest(){
        if(_shaderLight)
            delete _shaderLight;
        
        if(_shaderLamp)
            delete _shaderLamp;
        
        if(camera)
            delete camera;
        
        glDeleteVertexArrays(1, &containerVAO);
        glDeleteBuffers(1, &VBO);
    }
    virtual void init();
    virtual void update();
    void updateTime();
    
    Shader* _shaderLight = nullptr;
    Shader* _shaderLamp = nullptr;
    
    GLuint VBO, containerVAO;
    GLuint lightVAO;
    
    
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    
    bool keys[1024];
    
    void do_movement();
    
    void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mode);
    void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    
    // Window dimensions
    const GLuint WIDTH = 800;
    const GLuint HEIGHT = 600;
    
    // Camera
    Camera* camera = nullptr; ;
    GLfloat lastX;
    GLfloat lastY;
    
    // Light attributes
    glm::vec3 lightPos;
    // Deltatime
    GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
    GLfloat lastFrame = 0.0f;  	// Time of last frame
    
    bool firstMouse = true;

    
};
#endif