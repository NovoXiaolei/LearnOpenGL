//
//  Triangle1.h
//  LearnOpenGL
//
//  Created by ZhuXiaolei on 7/5/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//

#ifndef Triangle1_h
#define Triangle1_h

#include "../BaseTest.h"
#include "../Shader.h"

class Triangle1 : public BaseTest{
public:
    Triangle1(){
        init();
    }
    ~Triangle1(){
        delete _shader;
        
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }
    
    virtual void init();
    virtual void update();
    
    
    GLuint VBO, VAO;
    Shader* _shader = nullptr;
};

#endif /* Triangle1_h */
