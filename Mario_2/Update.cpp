#include "Window.h"

void MyWindow::update(float TimeMiliSeconds)
{
	mario.update(TimeMiliSeconds, map);
	for (size_t i = 0; i < personage.size(); i++)
	{
		if (personage[i].getPosition_x() > (mario.getPosition_x() - HORIZONTAL_RESOLUTION) &&
			personage[i].getPosition_x() < (mario.getPosition_x() + HORIZONTAL_RESOLUTION))
		personage[i].update(TimeMiliSeconds, map);
	}
}