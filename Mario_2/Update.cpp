#include "Window.h"

void MyWindow::update(float TimeMiliSeconds)
{
	mario.update(TimeMiliSeconds, map);
}