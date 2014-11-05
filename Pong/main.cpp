
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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

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
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());*/

    // Load a sprite to display
    /*sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);*/
    double ball_r=20;
    double ball_vx=-8;
    double ball_vy=8;
    sf::CircleShape ball(ball_r);
    ball.setFillColor(sf::Color(250, 100, 50));
    ball.setPosition(400-ball_r/2,300-ball_r/2);
    
    double wall_w=35;
    double bar_w=50;
    double bar_h=100;
    int speed=5;
    sf::RectangleShape bar1(sf::Vector2f(bar_w, bar_h));
    bar1.setFillColor(sf::Color(50, 100, 250));
    bar1.setPosition(wall_w,300-bar_h/2);
    sf::RectangleShape bar2(sf::Vector2f(bar_w, bar_h));
    bar2.setFillColor(sf::Color(50, 100, 250));
    bar2.setPosition(800-wall_w-bar_w,300-bar_h/2);
    
    double line_w=2;
    double line_h=600;
    sf::RectangleShape line(sf::Vector2f(line_w,line_h));
    line.setFillColor(sf::Color(250, 250, 250));
    line.setPosition(400,0);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text1("", font, 50);
    text1.setColor(sf::Color::White);
    int Score1 = 0;
    std::string textScore1 = std::to_string(Score1);
    text1.setString(textScore1);
    sf::FloatRect boxText1 = text1.getGlobalBounds();
    text1.setPosition(300, 50);
    
    
    
    
    
    sf::Text text2("", font, 50);
    text2.setColor(sf::Color::White);
    int Score2 = 0;
    std::string textScore2 = std::to_string(Score2);
    text2.setString(textScore2);
    sf::FloatRect boxText2 = text2.getGlobalBounds();
    text2.setPosition(450, 50);
     
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    

    // Start the game loop
    while (window.isOpen())
    {
        ball.move(ball_vx,ball_vy);
        
        // Process events
        if(ball_vx<0)
        {
            if(ball.getPosition().x<=0)
            {
                ball_vx*=-1;
            }
            if(ball.getPosition().x<=wall_w+bar_w)
            {
                if(ball.getPosition().y<bar1.getPosition().y+bar_h && ball.getPosition().y>bar1.getPosition().y-2*ball_r)
                {
                    ball_vx*=-1;
                }
            }
        }
        if(ball_vx>0)
        {
            if(ball.getPosition().x>=800-2*ball_r)
            {
                ball_vx*=-1;
            }
            if(ball.getPosition().x>=800-wall_w-bar_w-2*ball_r)
            {
                if(ball.getPosition().y<bar2.getPosition().y+bar_h && ball.getPosition().y>bar2.getPosition().y-2*ball_r)
                {
                    ball_vx*=-1;
                }
            }
        }
        if(ball_vy<0){
            if(ball.getPosition().y<=0){
                ball_vy*=-1;
            }
            if(ball.getPosition().y>=bar1.getPosition().y+bar_h-ball_r && ball.getPosition().y<=bar1.getPosition().y+bar_h){
                if(ball.getPosition().x<=wall_w+bar_w && ball.getPosition().x>=wall_w-2*ball_r){
                    ball_vy*=-1;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                        ball_vy=8;
                    }
                }
            }
            if(ball.getPosition().y>=bar2.getPosition().y+bar_h-ball_r && ball.getPosition().y<=bar2.getPosition().y+bar_h){
                if(ball.getPosition().x>=800-wall_w-bar_w-2*ball_r && ball.getPosition().x<=800-wall_w){
                    ball_vy*=-1;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
                        ball_vy=8;
                    }
                }
            }
        }
        if(ball_vy>0){
            if(ball.getPosition().y>=600-2*ball_r){
                ball_vy*=-1;
            }
            if(ball.getPosition().y>=bar1.getPosition().y-2*ball_r && ball.getPosition().y<=bar1.getPosition().y-ball_r){
                if(ball.getPosition().x<=wall_w+bar_w && ball.getPosition().x>=wall_w-2*ball_r){
                    ball_vy*=-1;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                        ball_vy=-8;
                    }
                }
            }
            if(ball.getPosition().y>=bar2.getPosition().y-2*ball_r && ball.getPosition().y<=bar2.getPosition().y-ball_r){
                if(ball.getPosition().x>=800-wall_w-bar_w-2*ball_r && ball.getPosition().x<=800-wall_w){
                    ball_vy*=-1;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
                        ball_vy=-8;
                    }
                }
            }
        }
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            if(bar2.getPosition().y>0)
            {
                bar2.move(0,-speed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            if(bar2.getPosition().y<600-bar_h)
            {
                bar2.move(0,speed);
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(bar1.getPosition().y>0)
            {
                bar1.move(0,-speed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            if(bar1.getPosition().y<600-bar_h)
            {
                bar1.move(0,speed);
            }
        }
        
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

        // Draw the sprite
        line.setPosition(400, 0);
        window.draw(line);
        window.draw(ball);
        window.draw(bar1);
        window.draw(bar2);
        
       
        // Draw the string
        window.draw(text1);
        window.draw(text2);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
