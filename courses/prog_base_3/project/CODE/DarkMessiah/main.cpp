#include "Level.hpp"

int main()
{
	Level level;
	level.LoadFromFile("lvl1.tmx");

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Level.h test");

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		level.Draw(window);
        window.display();
    }

    return 0;
}
