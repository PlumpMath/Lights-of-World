//
//  object.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/01/16.
//  Copyright © 2016 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <stdio.h>

struct GameObject {
    GameObject();
    ~GameObject();
    
    void kDraw(void);
    
    float kColisionSpace[4];
    void kGetColisionSpace(void);
    
    bool kColisionDetect(GameObject *object);
    
public:
    float localScale[2];
    float localPosition[2];
    
    float objectColor[4];
};

struct TextObject {
    TextObject();
    ~TextObject();
    
    void kDraw();
    
public:
    
    // Edições do Texto;
    char* Text;
    void* Font;
    
    float localScale[2];
    float localPosition[2];
    
    float textColor[4];
};

#endif /* _OBJECT_HPP_ */
