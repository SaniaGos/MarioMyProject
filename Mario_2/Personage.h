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
    Vector2f pozition;             // позиція персонажа
    Vector2i proportions;       // розмір спрайту персонажа
    Texture texture;    
    float       playerSpeed;
    float       dx, dy;
    Sprite sprite;
    vector<Sprite> frames;

public:
    Personage() = delete;
    Personage(const string path, const int _frames, const float speed, Vector2f _pozition, Vector2i size);
    Sprite getSprite() const;
    void setFrames(const vector<IntRect> frames);
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
    PLAYER(const string path, const int frames, const float inSpeed,
        Vector2f _pozition, Vector2i size);
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
    MinorPesonage(const string path, const int frames, const float inSpeed,
        Vector2f _pozition, Vector2i size);

};