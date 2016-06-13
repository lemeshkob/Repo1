#ifndef VICTORY_H
#define VICTORY_H

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
void victory(){
    RenderWindow window(VideoMode(800, 640), "You have won!");

    View view( FloatRect(0, 0, 450, 280) );

    while (window.isOpen()){

            Event event;
            while (window.pollEvent(event)){
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
            }

            Image had;
            had.loadFromFile("had.jpg");

            Texture hTex;
            hTex.loadFromImage(had);

            Sprite hSpr;
            hSpr.setTexture(hTex);

        Font font;
        font.loadFromFile("Xerox Sans Serif Wide Bold Oblique.ttf");
        Text text("", font, 15);
        text.setColor(Color::Yellow);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(view.getCenter().x+400,view.getCenter().y);
        text.setString("V\nI\nC\nT\nO\nR\nY");


            window.clear();
            window.draw(hSpr);
            window.draw(text);
            window.display();
	}

	RunGame();

}

#endif // VICTORY_H
