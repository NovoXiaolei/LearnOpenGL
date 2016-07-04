//
//  main.cpp
//  HelloTriangles
//
//  Created by ZhuXiaolei on 7/4/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//
#include "../Shader.h"

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

	GLfloat vertices[]={
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	GLuint VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
    
    const GLchar* vert = "/Users/xiaolei/Develop/GitHub/LearnOpenGL/HelloTriangles/triangles.vert";
    const GLchar* frag = "/Users/xiaolei/Develop/GitHub/LearnOpenGL/HelloTriangles/triangles.frag";
	Shader shader(vert, frag);

	while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

    	shader.Use();
    	glBindVertexArray(VAO);
    	glDrawArrays(GL_TRIANGLES, 0, 3);
    	glBindVertexArray(0);
        
        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}
