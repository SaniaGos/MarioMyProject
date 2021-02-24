#include "Window.h"

void MyWindow::update(float TimeMiliSeconds)
{
	mario.update(TimeMiliSeconds, map);
	for (size_t i = 0; i < personage.size(); i++)
	{
		if (personage[i]->getPosition().x > (mario.getPosition().x - HORIZONTAL_RESOLUTION) &&
			personage[i]->getPosition().x < (mario.getPosition().x + HORIZONTAL_RESOLUTION))
		personage[i]->update(TimeMiliSeconds, map);
	}
	clash_Personage();
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