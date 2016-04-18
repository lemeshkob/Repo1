#include <SFML/Graphics.hpp>
#include <stdio.h >
#include <stdlib.h>
#include <iostream>
#include <windows.h>



using namespace sf;

class Player
{
public:
    int xcoord = 0, ycoord = 0,weight = 0,height = 0, dx = 0 ,dy = 0, speed = 0;
    int direction = 0;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;
    Player(String F, int X, int Y, float W, float H)
    {
        File = F;
        weight = W;
        height = H;
        image.loadFromFile(File);
        image.createMaskFromColor(image.getPixel(0,0));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        xcoord = X;
        ycoord = Y;
        sprite.setTextureRect(IntRect(weight,height,weight,height));

    }

    void update(float time)
    {
        switch (direction)
        {
        case 0:
            dx = speed;
            dy = 0;
            break;
        case 1:
            dx = -speed;
            dy = 0;
        default:
                dx=0;
                dy=0;
                break;
        }

        xcoord += dx*time;
        ycoord += dy*time;

        speed = 0;
        sprite.setPosition(xcoord,ycoord);
    }
};
