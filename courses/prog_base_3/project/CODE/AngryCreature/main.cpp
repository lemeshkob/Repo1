#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
int main()
{
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
}
