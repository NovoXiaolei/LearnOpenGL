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
        
    }
    
    virtual void init();
    virtual void update();
};


#endif /* TextureTest_h */
