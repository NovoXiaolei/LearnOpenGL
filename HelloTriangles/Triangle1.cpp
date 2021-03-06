//
//  Triangle.cpp
//  LearnOpenGL
//
//  Created by ZhuXiaolei on 7/5/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//

#include "Triangle1.h"



void Triangle1::init(){
    
    GLfloat vertices[]={
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        1.0f, 0.5f, 0.0f
    };
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    const GLchar* vert = "/Users/xiaolei/Develop/GitHub/LearnOpenGL/HelloTriangles/triangles.vert";
    const GLchar* frag = "/Users/xiaolei/Develop/GitHub/LearnOpenGL/HelloTriangles/triangles.frag";
    _shader = new Shader(vert, frag);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void Triangle1::update(){
    _shader->Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
