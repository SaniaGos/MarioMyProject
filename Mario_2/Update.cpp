#include "Window.h"

void MyWindow::update(float TimeMiliSeconds)
{
	mario.update(TimeMiliSeconds, map);
	for (size_t i = 0; i < personage.size(); i++)
	{
		if (personage[i]->getPosition().x > (mario.getPosition().x - GlobalConfig::GetConfig().map.horizontal_resolution) &&
			personage[i]->getPosition().x < (mario.getPosition().x + GlobalConfig::GetConfig().map.horizontal_resolution))
		personage[i]->update(TimeMiliSeconds, map);
	}
	clash_Personage();
	text.setString("BitCoin: " + to_string(mario.getCoin()));
}
void MyWindow::clash_Personage()
{
	for (size_t i = 0; i < personage.size(); i++)
	{
		if (personage[i]->getLives())
		{
			clashPersonage(mario, *personage[i]);
		}
	}
}