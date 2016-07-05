//
//  BaseTest.h
//  LearnOpenGL
//
//  Created by ZhuXiaolei on 7/5/16.
//  Copyright © 2016 ZhuXiaolei. All rights reserved.
//

#ifndef BaseTest_h
#define BaseTest_h

#include <iostream>

class BaseTest{
public:
    BaseTest();
    
    virtual void init();
    virtual void update();
};

#endif /* BaseTest_h */
