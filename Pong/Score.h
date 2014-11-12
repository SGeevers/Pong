//
//  Score.h
//  Pong
//
//  Created by Sjoerd Geevers on 11/11/14.
//  Copyright (c) 2014 Sjoerd Geevers. All rights reserved.
//

#ifndef __Pong__Score__
#define __Pong__Score__
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

class Score
{
public:
    Score(unsigned int,sf::Color,double,double,double);
    void addScore();
    void reset();
    sf::Text getSpriteScore(sf::Font);
    
private:
    int score;
    sf::Text scoreSprite;
    double originxRelative;
};

#endif /* defined(__Pong__Score__) */
