#include "Window.h"

void MyWindow::draw()
{
	
	myWindow.clear();						// Стираєм попередній кадр

	myWindow.draw(myBackgroundSprite);		// малюєм задній фон

	drawMap();								// малюємо карту
	myWindow.draw(mario.getSprite());
	myWindow.display();						// відображаєм картину

}
void MyWindow::drawMap()
{
	for (size_t i = 0; i < map.getMap().size(); i++)
	{
		for (size_t j = 0; j < map.getMap()[i].size(); j++)
		{
			if (j * ATLAS_WIDTH < map.offset.x - ATLAS_WIDTH ||				// пришвидчує обробку кадру, бо бере до уваги лиш частину карти, яка відображається
				j * ATLAS_WIDTH > map.offset.x + HORIZONTAL_RESOLUTION)
				continue;
			if (map.getMap()[i][j] == 'B') m_Sprite.setTextureRect(IntRect(32, 0, ATLAS_HEIGHT, ATLAS_WIDTH));
			else if (map.getMap()[i][j] == 'S') m_Sprite.setTextureRect(IntRect(82, 160, 64, 48));
			else continue;
			m_Sprite.setPosition(32 * j - map.offset.x, 32 * i);
			myWindow.draw(m_Sprite);
		}
	}

}