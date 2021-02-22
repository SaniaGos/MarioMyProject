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
    Texture m_Texture;
    Map map;
    
    PLAYER mario;

    void input();
    void update(float TimeMiliSeconds);
    void draw();
    void drawMap();


public:
    
    MyWindow();
        
    void start();

};