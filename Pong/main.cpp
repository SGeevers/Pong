
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

//#define windowWidth 800;
//#define windowHeight 600;
//enum class wallType {noWall, leftWall, rightWall};
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Score.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"


int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setVerticalSyncEnabled(true);

    // Set the Icon
    /*sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icotn.getPixelsPtr());*/

    // Load a line to display
    double line_w=2;
    double line_h=600;
    sf::RectangleShape line(sf::Vector2f(line_w,line_h));
    line.setFillColor(sf::Color(250, 250, 250));
    line.setPosition(400,0);
    
    // Create players
    double barWidth=50;
    double barHeight=100;
    sf::Vector2f barSize(barWidth,barHeight);
    double wallDistance=10;
    double x1=wallDistance;
    double y1=300;
    double x2=800-wallDistance-barWidth;
    double y2=300;
    double playerSpeed=10;
    sf::Color playerColor(50, 100, 250);
    sf::Keyboard::Key keyUp1=sf::Keyboard::A;
    sf::Keyboard::Key keyDown1=sf::Keyboard::Z;
    sf::Keyboard::Key keyUp2=sf::Keyboard::K;
    sf::Keyboard::Key keyDown2=sf::Keyboard::M;
    
    Player player1(barSize, playerColor, keyUp1, keyDown1, x1, y1, playerSpeed);
    Player player2(barSize, playerColor, keyUp2, keyDown2, x2, y2, playerSpeed);
    
    // Create ball(s)
    double ballRadius = 20;
    double ballx=300;
    double bally=400;
    double ballSpeedx=12;
    double ballSpeedy=1;
    sf::Color ballColor(250, 100, 50);
    
    Ball ball(ballRadius, ballColor, ballx, bally, ballSpeedx, ballSpeedy);
    
    
    // Create score objects
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    unsigned int charSize=50;
    sf::Color scoreColor(250,250,250);
    double distanceMidline=50;
    double scorex1=400-distanceMidline;
    double scorex2=400+distanceMidline;
    double scorey=50;
    double originxRelative1=1;
    double originxRelative2=0;
    
    Score scoreLeft(charSize,scoreColor,scorex1,scorey,originxRelative1);
    Score scoreRight(charSize,scoreColor,scorex2,scorey,originxRelative2);
     
    // Load a music to play
    /*sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }*/

    // Play the music
    //music.play();
    

    // Start the game loop
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            scoreLeft.reset();
            scoreRight.reset();
        }
        player1.moveUp();
        player1.moveDown();
        player2.moveUp();
        player2.moveDown();
        switch(ball.collisionWall())
        {
            case 0:
                break;
            case 1:
                scoreLeft.addScore();
                break;
            case 2:
                scoreRight.addScore();
                break;
        }
        ball.move();
        ball.collisionBar(player1);
        ball.collisionBar(player2);
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        // Draw the line
        window.draw(line);
        
        // Draw the scores
        window.draw(scoreLeft.getSpriteScore(font));
        window.draw(scoreRight.getSpriteScore(font));
        
        // Draw the players and ball(s)
        window.draw(player1.getBar());
        window.draw(player2.getBar());
        window.draw(ball.getCircle());

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
