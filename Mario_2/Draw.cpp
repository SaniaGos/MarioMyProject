#include "Window.h"

void MyWindow::draw()
{
	
	myWindow.clear();						// ������ ��������� ����

	myWindow.draw(myBackgroundSprite);		// ������ ����� ���

	drawMap();								// ������� �����
	myWindow.draw(mario.getSprite());
	myWindow.display();						// ��������� �������

}
void MyWindow::drawMap()
{
	for (size_t i = 0; i < map.getMap().size(); i++)
	{
		for (size_t j = 0; j < map.getMap()[i].size(); j++)
		{
			if (map.getMap()[i][j] == 'B') m_Sprite.setTextureRect(IntRect(32, 0, ATLAS_HEIGHT, ATLAS_WIDTH));
			else continue;
			m_Sprite.setPosition(32 * j - map.offset.x, 32 * i);
			myWindow.draw(m_Sprite);
		}
	}

}