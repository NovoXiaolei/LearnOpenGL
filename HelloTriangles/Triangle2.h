//
//  Triangle2.h
//  LearnOpenGL
//
//  Created by ZhuXiaolei on 7/5/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//

#ifndef Triangle2_h
#define Triangle2_h

#include "../BaseTest.h"
#include "../Shader.h"

class Triangle2 : public BaseTest{
public:
    Triangle2(){
        init();
    }
    
    ~Triangle2(){
        delete _shader;
        delete _yellowShader;
        
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    
    }
    
    virtual void init();
    virtual void update();
    
    GLuint VBO, VAO;
    Shader* _shader = nullptr;
    Shader* _yellowShader = nullptr;
};

#endif /* Triangle2_h */
