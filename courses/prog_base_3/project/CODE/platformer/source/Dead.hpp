#ifndef DEAD_H
#define DEAD_H

#include <SFML/Graphics.hpp>

#include "level.hpp"
#include "Animation.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "MovingPlatform.hpp"
#include "HealthBar.hpp"
#include "Game.hpp"

using namespace sf;

void 	RunGame();
void death(){
    RenderWindow window(VideoMode(640, 480), "You are dead!");

    View view( FloatRect(0, 0, 450, 280) );

    while (window.isOpen()){

            Event event;
            while (window.pollEvent(event)){
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
            }

            Image vitya;
            vitya.loadFromFile("vitya.jpg");

            Texture vTex;
            vTex.loadFromImage(vitya);

            Sprite vSpr;
            vSpr.setTexture(vTex);

        Font font;
        font.loadFromFile("Xerox Sans Serif Wide Bold Oblique.ttf");
        Text text("", font, 15);
        text.setColor(Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(view.getCenter().x,view.getCenter().y);
        text.setString("V\nA\nS\n \nV\nI\nD\nR\nA\nH\nO\nV\nA\nN\nO\n!\n!\n!");


            window.clear();
            window.draw(vSpr);
            window.draw(text);
            window.display();
	}

	RunGame();

}

#endif // DEAD_H
