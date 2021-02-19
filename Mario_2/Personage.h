#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Define.h"

using namespace sf;
using namespace std;



class Personage
{
private:
    int numOfFrame;
    float currentFrame;
    Sprite m_Sprite;
    FloatRect   rect;

       
public:
    Personage() = delete;
    Personage(string path, int frames, FloatRect inRect);
    void update(float time);
};


class PLAYER : public Personage
{
private:
    SoundBuffer buffer;
    Sound       sound;

    float       dx, dy;

    bool        onGround;
    bool        playerUp;
    bool        playerDown;
    bool        playerRight;
    bool        playerLeft;
    float       playerSpeed;

public:
    PLAYER(string path, int frames, float inSpeed, FloatRect inRect);



};