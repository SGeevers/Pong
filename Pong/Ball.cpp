//
//  Ball.cpp
//  Pong
//
//  Created by Devashish  on 10/11/14.
//  Copyright (c) 2014 Sjoerd Geevers. All rights reserved.
//

#include "Ball.h"

Ball::Ball(double radius, sf::Color color, double xIn, double yIn, double speedxIn, double speedyIn)
{
    circle.setRadius(radius);
    circle.setFillColor(color);
    circle.setPosition(xIn, yIn);
    speedx = speedxIn;
    speedy = speedyIn;
}

sf::CircleShape Ball::getBall()
{
    return circle;
    
}

double Ball::getRadius()
{
    return circle.getRadius();
}

void Ball::move()
{
    circle.move(speedx, speedy);
    
}
bool Ball::collisionWall()
{
    if(speedx<0)
    {
        if(circle.getPosition().x<=0)
        {
            speedx*=-1;
            
        }
    }
    
    if(speedx>0)
    {
        if(circle.getPosition().x>=800 - 2 * getRadius())
        {
            speedx*=-1;
        }
    }
    
    if(speedy<0)
    {
        if(circle.getPosition().y<=0)
        {
            speedy*=-1;
        }
    }
    
    if(speedy>0)
    {
        if(circle.getPosition().y>=600-2*getRadius())
        {
            speedy*=-1;
        }
    }
    
}

void Ball::collisionBar(const Player&)
{
    
}