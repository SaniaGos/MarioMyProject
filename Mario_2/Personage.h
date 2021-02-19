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
    Sprite m_Sprite;
    FloatRect   rect;
    float       playerSpeed;

       
public:
    Personage() = delete;
    Personage(string path, int frames, FloatRect inRect, float speed);
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

public:
    PLAYER(string path, int frames, float inSpeed, FloatRect inRect, float speed);



};

class MinorPesonage : public Personage
{
private:
    float       dx, dy;

public:
    MinorPesonage(string path, int frames, float inSpeed, FloatRect inRect, float speed);

};