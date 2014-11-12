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

sf::CircleShape Ball::getCircle()
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
int Ball::collisionWall()
{
    if(speedx<0)
    {
        if(circle.getPosition().x<=0)
        {
            speedx*=-1;
            return 1;
        }
    }
    
    if(speedx>0)
    {
        if(circle.getPosition().x>=800 - 2 * getRadius())
        {
            speedx*=-1;
            return 2;
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
    return 0;
}

void Ball::collisionBar(const Player& player)
{
    // Process event
    if(speedx<0)
    {
        
        if(circle.getPosition().x <= player.getx() + player.getWidth() && circle.getPosition().x >= player.getx() + 0.5 * player.getWidth())
        {
            if(circle.getPosition().y < player.gety() + player.getHeight() && circle.getPosition().y > player.gety() - 2 *getRadius())
            {
                speedx *= -1;
                if(abs(speedy)<12)
                {
                    if (sf::Keyboard::isKeyPressed(player.getKeyDown()))
                    {
                        speedy+=2;
                    }
                    if (sf::Keyboard::isKeyPressed(player.getKeyUp()))
                    {
                        speedy-=2;
                    }
                }
            }
        }
    }
    if(speedx>0)
    {
        if(circle.getPosition().x >= player.getx() - 2 * getRadius() && circle.getPosition().x <= player.getx() - 2 * getRadius() + 0.5 * player.getWidth())
        {
            if(circle.getPosition().y < player.gety() + player.getHeight() && circle.getPosition().y > player.gety() - 2 * getRadius())
            {
                speedx*=-1;
                if(abs(speedy)<12)
                {
                    if (sf::Keyboard::isKeyPressed(player.getKeyDown()))
                    {
                        speedy+=2;
                    }
                    if (sf::Keyboard::isKeyPressed(player.getKeyUp()))
                    {
                        speedy-=2;
                    }
                }
            }
        }
    }

    if(speedy < 0)
    {
        
        if(circle.getPosition().y >= player.gety() + player.getHeight() - getRadius() && circle.getPosition().y <= player.gety() + player.getHeight())
        {
            if(circle.getPosition().x <= player.getx() + player.getWidth() && circle.getPosition().x >= player.getx() - 2 *getRadius())
            {
                speedy *= -1;
                if (sf::Keyboard::isKeyPressed(player.getKeyDown()))
                {
                    speedy=9;
                }
            }
        }
    }
    
    if(speedy>0)
    {

        if(circle.getPosition().y >= player.gety() - 2 * getRadius() && circle.getPosition().y <= player.gety() - getRadius())
        {
            if(circle.getPosition().x <= player.getx() + player.getWidth() && circle.getPosition().x >= player.getx() -2*getRadius()){
                speedy*=-1;
                if (sf::Keyboard::isKeyPressed(player.getKeyUp())){
                    speedy=-9;
                }
            }
        }

    }

}

