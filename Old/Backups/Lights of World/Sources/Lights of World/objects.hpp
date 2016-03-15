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
#include <GLUT/glut.h>


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


// Draw
struct ObjectComplex {
    ObjectComplex();
    ~ObjectComplex();
    
    void kObjectDraw(float _x_size, float _y_size);
    
    // Aplicação de Movimentos em Geral;
    void kApplyMovement(float _x_ = 0.0f, float _y_ = 0.0f);
    void kApplyForce(float _x_ = 0.0f, float _y_ = 0.0f);
    
    void kApplyRotation(float _force_);
    
    // Aplicação da Fisica;
    void kRunPhysics(void);
    
private:
    
    enum KX_PHYSIC_STATES {
        MOVING, STOPPED
    };
    
    enum KX_PHYSIC_BODY {
        BOX, CIRCLE, PER_PIXEL, PER_SPACE
    };
    
    enum KX_PHYSIC_TYPE {
        NO_COLLISION, OCCLUDER, RIGID_BODY, DYNAMIC
    };
    
    // Estados de Colisão e etc;
    KX_PHYSIC_BODY cl_body;
    KX_PHYSIC_STATES cl_state;
    KX_PHYSIC_TYPE cl_type;
    
    float cl_object_mass;
    
public:
    
    float ob_position_x, ob_position_y;
    float ob_size_x, ob_size_y;
    
    float ob_rotation;
    
    GLfloat localScale[2];
    GLfloat localPosition[2];
    GLfloat localRotation[1];

    GLfloat globalScale[2];
    GLfloat globalPosition[2];
    GLfloat globalRotation[1];
    
    void kDisablePhysics(void);
    void kEnablePhysics(void);
    
};


#endif /* objects_hpp */
