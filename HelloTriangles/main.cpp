//
//  main.cpp
//  HelloTriangles
//
//  Created by ZhuXiaolei on 7/4/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//
#include "../Shader.h"
#include "Triangle1.h"
#include "Triangle2.h"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;


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
	glewExperimental = GL_TRUE;
	if(glewInit()!=GLEW_OK)
	{
		return -1;
	}

    //Triangle1 triangle;
    Triangle2 triangle2;
    
	while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        triangle2.update();
    	
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    
    // Properly de-allocate all resources once they've outlived their purpose
    
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}
