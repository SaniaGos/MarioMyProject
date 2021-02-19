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
    FloatRect   rect;           // ������� ��������� � ����� �������
    float       playerSpeed;
    float       dx, dy;

       
public:
    Personage() = delete;
    Personage(string path, int frames, FloatRect inRect, float speed);
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

public:
    PLAYER(string path, int frames, float inSpeed, FloatRect inRect, float speed);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    
    void stopUp();
    void stopDown();
    void stopRight();
    void stopLeft();

};

class MinorPesonage : public Personage
{
private:

public:
    MinorPesonage(string path, int frames, float inSpeed, FloatRect inRect, float speed);

};