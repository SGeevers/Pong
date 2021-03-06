//
//  Player.cpp
//  Pong
//
//  Created by Devashish  on 10/11/14.
//  Copyright (c) 2014 Sjoerd Geevers. All rights reserved.
//

#include "Player.h"

Player::Player( sf::Vector2f barSize, sf::Color color, sf::Keyboard::Key keyUpIn , sf::Keyboard::Key keyDownIn, double x, double y, double speedIn)
{
    bar.setSize(barSize);
    bar.setFillColor(color);
    keyUp = keyUpIn;
    keyDown = keyDownIn;
    bar.setPosition(x, y);
    speed = speedIn;
}

double Player::getx() const
{
    return bar.getPosition().x;
}

double Player::gety() const
{
    return bar.getPosition().y;
}

double Player::getHeight() const
{
    return bar.getSize().y;
}

double Player::getWidth() const
{
    return bar.getSize().x;
}

void Player::moveUp()
{
    if (sf::Keyboard::isKeyPressed(keyUp))
    {
        if(bar.getPosition().y>0)
        {
            bar.move(0,-speed);
        }
    }

}

void Player::moveDown()
{
    if (sf::Keyboard::isKeyPressed(keyDown))
    {
        if(bar.getPosition().y<600 - getHeight())
        {
            bar.move(0,speed);
        }
    }
}

sf::RectangleShape Player::getBar() const
{
    return bar;
}

sf::Keyboard::Key Player::getKeyUp() const
{
    return keyUp;
}

sf::Keyboard::Key Player::getKeyDown() const
{
    return keyDown;
}

