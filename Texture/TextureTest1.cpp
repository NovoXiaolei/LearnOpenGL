#include "TextureTest1.h"
#include <SOIL.h>

void TextureTest1::init(){
    GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 2.0f, // Top Right
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f  // Top Left
    };
    
    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };
    
    _shader = new Shader("/Users/xiaolei/Develop/GitHub/LearnOpenGL/Texture/texture1.vert",
                         "/Users/xiaolei/Develop/GitHub/LearnOpenGL/Texture/texture1.frag");
    
    
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    //posoiton arrribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(1);
    
    //texcoord attribute
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
    
    //crete texture
    glGenTextures(1, &_texture1);
    glBindTexture(GL_TEXTURE_2D, _texture1);
    //设置纹理过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //设置缩放过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Load image, create texture and generate mipmaps
    int width, height;
    unsigned char* image = SOIL_load_image("/Users/xiaolei/Develop/GitHub/LearnOpenGL/Texture/wall.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glGenTextures(1, &_texture2);
    glBindTexture(GL_TEXTURE_2D, _texture2);
    //设置纹理过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //设置缩放过滤
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //Load image, create texture and generate mipmaps
    image = SOIL_load_image("/Users/xiaolei/Develop/GitHub/LearnOpenGL/Texture/cat.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    

}

void TextureTest1::update(){
    _shader->Use();
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture1);
    glUniform1i(glGetUniformLocation(_shader->Program, "ourTexture1"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _texture2);
    glUniform1i(glGetUniformLocation(_shader->Program, "ourTexture2"), 1);
    
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}