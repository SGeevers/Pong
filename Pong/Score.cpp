//
//  Score.cpp
//  Pong
//
//  Created by Sjoerd Geevers on 11/11/14.
//  Copyright (c) 2014 Sjoerd Geevers. All rights reserved.
//

#include "Score.h"

Score::Score(unsigned int charSize,sf::Color color, double xIn, double yIn, double originxRelativeIn){
    score=0;
    scoreSprite.setPosition(xIn,yIn);
    scoreSprite.setCharacterSize(charSize);
    scoreSprite.setColor(color);
    originxRelative=originxRelativeIn;
}

void Score::addScore()
{
    score+=1;
}

void Score::reset()
{
    score=0;
}

sf::Text Score::getSpriteScore(sf::Font font)
{
    std::string textScore=std::to_string(score);
    scoreSprite.setFont(font);
    scoreSprite.setString(textScore);
    sf::FloatRect boxScore=scoreSprite.getGlobalBounds();
    scoreSprite.setOrigin(originxRelative * boxScore.width,0);
    
    return scoreSprite;
}