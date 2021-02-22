#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Define.h"

using namespace sf;
using namespace std;



class Personage
{
protected:
    int numOfFrame;
    float currentFrame;
    FloatRect   rect;     // позиція персонажа і розмір спрайту
    Texture texture;    
    float       playerSpeed;
    float       dx, dy;
    Sprite sprite;

public:
    Personage() = delete;
    Personage(const string path, const int frames, const float speed, FloatRect inRect);
    Sprite getSprite() const;
    virtual void update(float time) = 0;
};


class PLAYER : public Personage
{
private:
    SoundBuffer buffer;
    Sound       sound;


    bool        onGround;
    bool        playerUp;
    bool        playerDown;
    bool        playerRight;
    bool        playerLeft;
    
    void m_update();
public:
    PLAYER() = delete;
    PLAYER(const string path, const int frames, const float inSpeed, FloatRect inRect);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    
    void stopUp();
    void stopDown();
    void stopRight();
    void stopLeft();
    void update(float time);

};

class MinorPesonage : public Personage
{
private:

public:
    MinorPesonage(string path, int frames, float inSpeed, FloatRect inRect, float speed);

};