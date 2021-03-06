//
//  Ball.h
//  Pong
//
//  Created by Devashish  on 10/11/14.
//  Copyright (c) 2014 Sjoerd Geevers. All rights reserved.
//

#ifndef __Pong__Ball__
#define __Pong__Ball__
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Player.h"
#include "wallType.h"

class Player;

class Ball
{
    public:
    
        Ball(double, sf::Color, double, double, double, double);
        sf::CircleShape getCircle();
        void move();
        wallType collisionWall();
        void collisionBar(const Player&);
        double getRadius();
    
    private:
    
        sf::CircleShape circle;
        double speedx, speedy;
};




#endif /* defined(__Pong__Ball__) */
