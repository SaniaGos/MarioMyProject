#include "Window.h"

void MyWindow::update(float TimeMiliSeconds)
{
	mario.update(TimeMiliSeconds, map);
	for (size_t i = 0; i < personage.size(); i++)
	{
		personage[i].update(TimeMiliSeconds, map);
	}
}