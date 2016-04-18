#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "anim.hpp"
using namespace sf;
int main()
{
    RenderWindow window(sf::VideoMode(1366, 768), "Angry Creature", Style::Fullscreen);

    Player Hero("warrior.png", 10, 10, 47.0, 67.0);
    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }
    /// äâèæåíèå
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
        {
            Hero.direction = 1;
            Hero.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 8) CurrentFrame -= 8;
            Hero.sprite.setTextureRect(IntRect(47 * int(CurrentFrame) + 47, 0, -47, 67));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
        {
            Hero.direction = 0;
            Hero.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 8) CurrentFrame -= 8;
            Hero.sprite.setTextureRect(IntRect(47 * int(CurrentFrame), 0, 47, 67));
        }

        Hero.update(time);
        window.clear();
        window.draw(Hero.sprite);
        window.display();
    }

    return 0;
