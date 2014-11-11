//
//  Player.h
//  Pong
//
//  Created by Devashish  on 10/11/14.
//  Copyright (c) 2014 Sjoerd Geevers. All rights reserved.
//

#ifndef Pong_Player_h
#define Pong_Player_h
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Player
{
    public:
    Player(sf::Vector2f, sf::Color, sf::Keyboard::Key , sf::Keyboard::Key, double, double, double);
    double getx() const;
    double gety() const;
    double getHeight() const;
    double getWidth() const;
    void moveUp();
    void moveDown();
    sf::RectangleShape getBar() const;
    sf::Keyboard::Key getKeyUp() const;
    sf::Keyboard::Key getKeyDown() const;
    
    
    private:
    sf::RectangleShape bar;
    double speed;
    sf::Keyboard::Key keyUp, keyDown;
    
};

#endif
