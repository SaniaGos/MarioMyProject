#include "Window.h"

void MyWindow::draw()
{
	myWindow.clear();						// Стираєм попередній кадр
	myWindow.draw(myBackgroundSprite);		// малюєм задній фон
	drawMap();								// малюємо карту
	myWindow.draw(mario.getSprite());		// малюєм Маріо
	drawEnemies();							// малюєм другорядних героїв
	myWindow.draw(text);
	myWindow.draw(frames.getFrames());
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
			if (map.getMap()[i][j] == 'B') m_Sprite.setTextureRect(IntRect(32, 0, ATLAS_WIDTH, ATLAS_HEIGHT));
			else if (map.getMap()[i][j] == 'C') m_Sprite.setTextureRect(IntRect(82, 160, ATLAS_WIDTH * 2, ATLAS_HEIGHT * 1.5));
			else if (map.getMap()[i][j] == 'T') m_Sprite.setTextureRect(IntRect(0, 160, ATLAS_WIDTH, ATLAS_HEIGHT * 3));
			else if (map.getMap()[i][j] == 'A') m_Sprite.setTextureRect(IntRect(32, 160, ATLAS_WIDTH, ATLAS_HEIGHT));
			else continue;
			m_Sprite.setPosition(32 * j - map.offset.x, 32 * i);
			myWindow.draw(m_Sprite);
		}
	}
}

void MyWindow::drawEnemies()
{
	for (size_t i = 0; i < personage.size(); i++)
	{
		if (personage[i]->getLives())
		{
			if (personage[i]->getPosition().x > (mario.getPosition().x - HORIZONTAL_RESOLUTION) &&
				personage[i]->getPosition().x < (mario.getPosition().x + HORIZONTAL_RESOLUTION))
				myWindow.draw(personage[i]->getSprite());
		}
	}
}

void MyWindow::loadPersonage()
{
	for (size_t i = 0; i < map.getMap().size(); i++)
	{
		for (size_t j = 0; j < map.getMap()[i].size(); j++)
		{
			if (map.getMap()[i][j] == 'H')
				personage.push_back(new Mushrooms(
					Vector2f(j * ATLAS_WIDTH, i * ATLAS_HEIGHT), Vector2i(32, 32)));
			else if (map.getMap()[i][j] == 'K')
				personage.push_back(new Turtle(
					Vector2f(j * ATLAS_WIDTH, i * ATLAS_HEIGHT), Vector2i(32, 48)));
			else if (map.getMap()[i][j] == 'M')
				personage.push_back(new Money(
					Vector2f(j * ATLAS_WIDTH, i * ATLAS_HEIGHT), Vector2i(32, 32)));
			
		}
	}
}
