#pragma once
#include <SFML/Graphics.hpp>
#include "Define.h"
#pragma warning( disable : 4996)


using namespace sf;
using namespace std;

class ScreenFrames
{
private:
	Font		framesFont;
	Text		framesText;

	int			frames;
	Clock		time;
	void calculation();
public:

	ScreenFrames();
	Text& getFrames();

};