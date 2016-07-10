//
//  main.cpp
//  HelloTriangles
//
//  Created by ZhuXiaolei on 7/4/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//
#include "MatrixTest.h"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    
}

MatrixTest test;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    glfwInit();
    //set major code
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //set submajor code
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //use core mode
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "HelloTriangles", nullptr, nullptr);
    
    if(nullptr == window)
    {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glfwSetKeyCallback(window, key_callback);
    
    glewExperimental = GL_TRUE;
    if(glewInit()!=GLEW_OK)
    {
        return -1;
    }
    
    test.init();
    
    
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        
        test.update();
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    
    // Properly de-allocate all resources once they've outlived their purpose
    
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    test.keyCallBack(window, key, scancode, action, mode);
    
}
