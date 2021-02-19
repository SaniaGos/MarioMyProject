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
   // Texture m_Texture;
       
public:
    Personage() = delete;
    Personage(string path, int frames);
    void update(float time);
};


class PLAYER : public Personage
{
private:
    SoundBuffer buffer;
    Sound       sound;

    float       dx, dy;
    FloatRect   rect;

    bool        onGround;
    bool        m_UpPressed;
    bool        m_DownPressed;
    float       m_Speed;


public:




};