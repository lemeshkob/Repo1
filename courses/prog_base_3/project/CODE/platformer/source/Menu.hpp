#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <list>
#include "level.hpp"
#include "Animation.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "MovingPlatform.hpp"
#include "HealthBar.hpp"
#include "Dead.hpp"
#include "Game.hpp"

using namespace sf;
int menu(RenderWindow & window) {
    Image m1, m2, m3, ab;
    m1.loadFromFile("Level1.png");
    m2.loadFromFile("badge_2.png");
    m2.createMaskFromColor(Color::White);
    m3.loadFromFile("Exit.png");
    m3.createMaskFromColor(Color::White);
    ab.loadFromFile("about.png");
    ab.createMaskFromColor(Color::White);

	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture2.loadFromImage(m2);
	menuTexture1.loadFromImage(m1);
	menuTexture3.loadFromImage(m3);
	aboutTexture.loadFromImage(ab);
	menuBackground.loadFromFile("menuBG.jpg");
	Sprite menu1(menuTexture1), menu3(menuTexture3), menu2(menuTexture2);
	Sprite menuBg(menuBackground);
	Sprite about;
	about.setTexture(aboutTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 150);
	menu3.setPosition(100, 300);
	menuBg.setPosition(0, 0);
    Level lvl;
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		about.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 300, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(100, 500, 300, 50).contains(Mouse::getPosition(window))) { about.setColor(Color::Blue); menuNum = 4; }


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)  return 1;//если нажали первую кнопку, то выходим из меню
			if (menuNum == 2) { return 2;}
			if (menuNum == 3)  { window.close(); isMenu = false; }
			if (menuNum == 4)   { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	////////////////////////////////////////////////////
}
#endif // MENU_H
