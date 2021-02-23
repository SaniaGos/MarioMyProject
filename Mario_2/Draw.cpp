#include "Window.h"

void MyWindow::draw()
{
	myWindow.clear();						// ������ ���������� ����

	myWindow.draw(myBackgroundSprite);		// ������ ������ ���

	drawMap();								// ������� �����
	myWindow.draw(mario.getSprite());		// ������ ����
	drawEnemies();							//drawEnemies();							// ������ ����������� �����
	myWindow.display();						// ��������� �������
}
void MyWindow::drawMap()
{
	for (size_t i = 0; i < map.getMap().size(); i++)
	{
		for (size_t j = 0; j < map.getMap()[i].size(); j++)
		{
			if (j * ATLAS_WIDTH < map.offset.x - ATLAS_WIDTH ||				// ��������� ������� �����, �� ���� �� ����� ��� ������� �����, ��� ������������
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
		myWindow.draw(personage[i].getSprite());
	}
}

void MyWindow::loadPersonage()
{

	for (size_t i = 0; i < map.getMap().size(); i++)
	{
		for (size_t j = 0; j < map.getMap()[i].size(); j++)
		{
			if (map.getMap()[i][j] == 'H')
			{
				personage.push_back(MinorPesonage(ENEMIES, 2, SPEED_ENEMIES,
					128, true, Vector2f(j * ATLAS_WIDTH, i * ATLAS_HEIGHT), Vector2i(32, 32)));
				personage.back().setFrameS({
					IntRect(64, 0, 32, 32),          // ���� ��������

					IntRect(0, 0, 32, 32),           // ��� ����� ���� ������
					IntRect(32, 0, 32, 32),

					IntRect(0, 0, 32, 32),           // ��� ����� ���� ����
					IntRect(32, 0, 32, 32)
					});

				//else if (map.getMap()[i][j] == 'K') ;
				//else if (map.getMap()[i][j] == 'M') ;
				//else continue;
			}
		}
	}
}
