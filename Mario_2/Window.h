#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Define.h"
#include "Personage.h"

using namespace sf;

class MyWindow
{
private:
    
    RenderWindow myWindow;
    Texture myBackgroundTexture;
    Sprite myBackgroundSprite;
    float TimeMiliSeconds;
    
    Sprite m_Sprite;
    Texture texture;
    Map map;
    
    SoundBuffer buffer;
    Sound       sound;

    PLAYER mario;

    vector<MinorPesonage> personage;

    void input();
    void update(float TimeMiliSeconds);
    void draw();
    void drawMap();
    void drawEnemies();
    void loadPersonage();

public:
    
    MyWindow();
        
    void start();

};