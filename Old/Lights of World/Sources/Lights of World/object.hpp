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

// Objeto de Jogo Convencional
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

// Estrutura de Texto
struct TextObject {
    TextObject();
    ~TextObject();
    
    void kDraw();
    
    void kSetColor(float red=1.0f, float green=1.0f, float blue=1.0f, float alpha=1.0f);
    void kFadeToColor(float red=1.0f, float green=1.0f, float blue=1.0f, float alpha=1.0f); // Subtração de cor;
    
public:
    
    // Edições do Texto;
    char* Text;
    void* Font;
    
    float localScale[2];
    float localPosition[2];
    
    float textColor[4];
};

// Estrutura Inteligente
struct SmartObject {
    SmartObject();
    ~SmartObject();
    
    
};

#endif /* _OBJECT_HPP_ */
