#include <SFML/Graphics.hpp>
#include <stdio.h >
#include <stdlib.h>
#include <iostream>
#include <windows.h>



using namespace sf;

class Player {
    private: float x,y;
public:
	float  w, h, dx, dy, speed = 0;
	int dir = 0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H){
		File = F;
		w = W; h = H;
		 image.loadFromFile(File);
		 image.createMaskFromColor(image.getPixel(0,0));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}



	void update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0;   break;
		case 1: dx = -speed; dy = 0;   break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;
		sprite.setPosition(x,y);
	}

float getplayercoordinateX(){
		return x;
	}
	float getplayercoordinateY(){
		return y;
	}
};


