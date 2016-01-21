//
//  objects.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 20/01/16.
//  Copyright © 2016 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef objects_hpp
#define objects_hpp

#include <stdio.h>


struct SimpleBox {
    SimpleBox(); /* Constructor */
    ~SimpleBox(); /* Destructor */
    
    void kApplyMovement();
    void kObjectDraw(float _x_size_, float _y_size_);
    
public:
    float size_x_, size_y_;
    float x_, y_;
    
    float full_size=1.0f;
};


struct FinderLine {
    FinderLine();
    ~FinderLine();
    
    void kDrawLine(float* find_x_, float* find_y_);
    
public:
    
    float start_x_=0.0f;
    float start_y_=0.0f;
    
};


struct ConstructorPivot {
    ConstructorPivot();
    ~ConstructorPivot();
    
    void DestructPanel(void);
    void CallerPannel(void);
    
public:
    
    float PivotDirection;
    
    void ToggleVisibility(bool set_hidden);
    void display(void);
    
    void kDrawPivot();
};

#endif /* objects_hpp */
