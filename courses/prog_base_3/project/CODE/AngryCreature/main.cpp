
#include <SFML/Graphics.hpp>
#include "anim.hpp"

using namespace sf;


int main()
{
    RenderWindow win(sf::VideoMode(200, 200), "SFML Test");
    Texture q;
    q.loadFromFile("rogue spritesheet calciumtrice.png");


    Animation anim;



        win.clear(Color::White);
        win.draw(heroSprite);
        win.display();
    }

    return 0;
}
