#ifndef ANIM_H
#define ANIM_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Animation{
public:
    std::vector<IntRect> frames, frames_flip;
    float currentFrame, speed;
    bool flip, isPlaying;
    Sprite sprite;

    Animation(Texture &t, int x, int y, int w, int h, int Count, float Speed, int step){
        speed = Speed;
        sprite.setTexture(t);

        currentFrame = 0;
        isPlaying = true;
        flip = false;

        for(int i = 0; i < Count; i++){
            frames.push_back(IntRect(x*i*step,y,w,h));
            frames_flip.push_back(IntRect(x*i*step+w,y,-w,h));
        }
    }

    void tick(float time){
        if(!isPlaying){
            return;
        }
        currentFrame += speed*time;

        if(currentFrame > frames.size()){
            currentFrame -= frames.size();
        }

        int i = currentFrame;
        sprite.setTextureRect(frames[i]);
        if(flip){
            sprite.setTextureRect(frames_flip[i]);
        }
    }

};

class AnimationManeger{
public:
    String currentAnim;
    std::map<String, Animation>, animList;

    AnimationManeger(){
    }

    void create(String name, Texture &t, int x, int y, int w, int h, int Count, float Speed, int step){
        animList[name] = Animation(t,x,y,w,h,Count,Speed,step);
        currentAnim = name;
    }

    void draw(RenderWindow &window, int x = 0, int y = 0){
        animList[currentAnim].sprite.setPosition(x,y);
        window.draw(animList[currentAnim].sprite);
    }

    void Set(String name){currentAnim = name;}

    void flip(bool b){ animList[currentAnim].flip = b;}

    void tick(float time){ animList[currentAnim].tick(time);}

    void pause(){ animList[currentAnim].isPlaying = false;}

    void play(){ animList[currentAnim].isPlaying = true;}


};


#endif // ANIM_H
