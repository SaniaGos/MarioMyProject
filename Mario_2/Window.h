#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Define.h"
#include "Personage.h"
#include "ScreenFrames.h"

#pragma warning( disable : 4996)
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

	Font font;
	Text text;

	ScreenFrames frames;

	PLAYER mario;

	vector<Minor_Personage*> personage;

	void input();
	void update(float TimeMiliSeconds);
	void draw();
	void drawMap();
	void drawEnemies();
	void loadPersonage();
	void clash_Personage();

public:

	MyWindow();

	void start();

};