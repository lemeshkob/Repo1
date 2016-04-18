<<<<<<< HEAD
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "anim.hpp"
using namespace sf;
int main()
{
<<<<<<< HEAD
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
    /// ��������
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
=======
	RenderWindow window(sf::VideoMode(640, 480), "Lesson 7. kychka-pc.ru", Style::Fullscreen);

    Image heroImage;
    heroImage.loadFromFile("BOV_Warrior.png");
    heroImage.createMaskFromColor(Color(255,163,177));

	Texture herotexture;
	herotexture.loadFromImage(heroImage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 71, 38, 67));
	herosprite.setPosition(250, 250);

	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape)){
				window.close();
			}
		}


	
		if ((Keyboard::isKeyPressed(Keyboard::Left))) { 
			CurrentFrame += 0.005*time; 
			if (CurrentFrame < -8) CurrentFrame += 8; 
			herosprite.setTextureRect(IntRect(38 * int(CurrentFrame) + 38, 71, -38, 67)); 
			herosprite.move(-0.1*time, 0);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))) {
			CurrentFrame += 0.005*time; 
			if (CurrentFrame > 8) CurrentFrame -= 8;
			herosprite.setTextureRect(IntRect(38 * int(CurrentFrame), 71, 38, 67));
			herosprite.move(0.1*time, 0);

		}
		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
>>>>>>> 6f1e32e8d7580468c1ad1fcf82e9f847b58c9785
}
=======

>>>>>>> origin/master
