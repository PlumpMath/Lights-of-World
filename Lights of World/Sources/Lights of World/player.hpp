//
//  player.hpp
//  Lights of World
//
//  Created by Vinicius A.M. Lobo on 24/09/15.
//  Copyright © 2015 Vinicius A.M. Lobo. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>

struct Graphics;
struct GameObject;

struct Player {
    Player();
    ~Player();
    
    void kDraw(void);
    void kEvents(Graphics *graphics);
    
    float kColisionSpace[4];
    
    bool kColisionDetect(GameObject *object);
    
public:

    float localScale[2];
    float localPosition[2];
    
    float playerColor[4];
    
};

#endif /* player_hpp */
