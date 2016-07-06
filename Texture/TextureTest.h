//
//  TextureTest.h
//  LearnOpenGL
//
//  Created by ZhuXiaolei on 7/6/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//

#ifndef TextureTest_h
#define TextureTest_h

#include "../Shader.h"
#include "../BaseTest.h"

class TextureTest : public BaseTest{
public:
    TextureTest(){
        init();
    }
    
    ~TextureTest(){
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


#endif /* TextureTest_h */
