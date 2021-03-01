#include "ScreenFrames.h"


ScreenFrames::ScreenFrames() :
	frames(0),
	time()
{
	time.restart();
	framesFont.loadFromFile(GlobalConfig::GetConfig().map.font);
	framesText.setFont(framesFont);
	framesText.setCharacterSize(30);
	framesText.setColor(Color::Color(255, 191, 0));
	framesText.setStyle(Text::Bold);
	framesText.setPosition(64, 32);
}
Text& ScreenFrames::getFrames()
{
	calculation();
	return framesText;
}
void ScreenFrames::calculation()
{
	frames++;
	if (time.getElapsedTime().asMilliseconds() >= 1000)
	{
		framesText.setString("ScreenFrames :" + to_string(frames));
		frames = 0;
		time.restart();
	}
}
