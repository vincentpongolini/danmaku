#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <windows.h>


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 800, 32), "Dannemaku");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Music menu{};
    sf::Music menu2{};
    sf::Image icon;
    sf::Texture texture;
    sf::Clock clock;


    icon.loadFromFile("C:\\Users\\Vincent\\c++_projects\\danmaku\\test.gif");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    if(!texture.loadFromFile("sprites\\spritesheet.png"))
    {
        std::cout << "ERROR: Spritesheet not found" << std::endl;
        return 0;
    }
    sf::IntRect rectSourceSprite(0,0,148,125);
    sf::Sprite ufoo{texture, rectSourceSprite};

    ufoo.setPosition (500 / 2, 800 / 2);
    auto size { texture.getSize () };
    ufoo.setOrigin (size.x / 8, size.y / 2);


    menu.openFromFile("C:\\Users\\Vincent\\c++_projects\\danmaku\\BGM\\menu1.wav");
    if(!menu.openFromFile("C:\\Users\\Vincent\\c++_projects\\danmaku\\BGM\\menu1.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    menu.setVolume(100);
    menu.play();
    menu.setLoop(true);
    menu.setLoopPoints(sf::Music::TimeSpan(sf::milliseconds(5300), sf::milliseconds(58000)));


    /*if(menu.getStatus() == sf::SoundSource::Status::Stopped)
    {
        menu2.openFromFile("C:\\Users\\Vincent\\c++_projects\\danmaku\\BGM\\menu2.wav");
        menu2.play();
        menu2.setLoop(true);
        std::cout << "playing 2" << std::endl;
    }*/
    

    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(clock.getElapsedTime().asMilliseconds() > 100)
        {
            if(rectSourceSprite.left == 296)
            {
                rectSourceSprite.left = 0;
            }
            else
            {
                rectSourceSprite.left += 148;
            }
            ufoo.setTextureRect(rectSourceSprite);
            clock.restart();
        }

        //regular movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {

            ufoo.move(sf::Vector2f(0, -0.1f));

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            ufoo.move(sf::Vector2f(0, 0.1f));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            ufoo.move(sf::Vector2f(-0.1f, 0));
            ufoo.setScale(1.f, 1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            ufoo.move(sf::Vector2f(0.1f, 0));
            ufoo.setScale(-1.f, 1.f);
        }

        //slowdown
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {

            ufoo.move(sf::Vector2f(0, -0.06f));

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            ufoo.move(sf::Vector2f(0, 0.01f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            ufoo.move(sf::Vector2f(-0.01f, 0));
            ufoo.setScale(1.f, 1.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            ufoo.move(sf::Vector2f(0.01f, 0));
            ufoo.setScale(-1.f, 1.f);
        }



        window.clear();
        /*int loop {100};
        for ( int i = loop; i > 0; i--)
        {
            //window.draw(shape);
            window.draw(ufoo);
          
        }*/
        window.draw(ufoo);
        window.display();
    }

    return 0;
}