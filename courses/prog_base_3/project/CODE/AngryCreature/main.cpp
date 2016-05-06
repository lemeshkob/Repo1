#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "anim.hpp"
#include "map.hpp"
using namespace sf;
int main()
{
    RenderWindow window(sf::VideoMode(1366, 768), "Angry Creature", Style::Fullscreen);

    Image map_image;
    map_image.loadFromFile("map.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);

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
        if ((Keyboard::isKeyPressed(Keyboard::Left)))
        {
            Hero.dir = 1;
            Hero.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 8) CurrentFrame -= 8;
            Hero.sprite.setTextureRect(IntRect(47 * int(CurrentFrame) + 47, 0, -47, 67));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right)))
        {
            Hero.dir = 0;
            Hero.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 8) CurrentFrame -= 8;
            Hero.sprite.setTextureRect(IntRect(47 * int(CurrentFrame), 0, 47, 67));
        }

        Hero.update(time);
        window.clear();
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
                if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map);//рисуем квадратики на экран
            }
        window.draw(Hero.sprite);
        window.display();
    }

    return 0;

}

