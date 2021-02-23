#include "Window.h"

MyWindow::MyWindow() :// ����������� �������� ����
	mario(JUMP, MARIO, 3, MARIO_SPEED, Vector2f(100, 100), Vector2i(32, 32))
{
	myWindow.create(VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Mario By SaniaGos");    // � define ����� ����� ���� � ��� ���� �����
	myBackgroundTexture.loadFromFile(MY_BACKGROUND);                                                // ����� �������� �������� ����
	myBackgroundSprite.setTexture(myBackgroundTexture);                                             // �������� �������� � ������ �������� ����
	map.loadMap(MAP1);
	texture.loadFromFile(BRICK);
	m_Sprite.setTexture(texture);
	TimeMiliSeconds = 0;
	buffer.loadFromFile(MUSIC);
	sound.setBuffer(buffer);
}

void MyWindow::start()
{
	Clock clock;
	mario.setFrames({
		IntRect(0,96,32,32),            // ���� �������� ����

		IntRect(32,96,32,32),           // ��� ����� ���� ������
		IntRect(64,96,32,32),
		IntRect(96,96,32,32),

		IntRect(64,96,-32,32),          // ��� ����� ���� ����
		IntRect(96,96,-32,32),
		IntRect(128,96,-32,32),
		});
	loadPersonage();
	sound.play();

	while (myWindow.isOpen())
	{
		TimeMiliSeconds = clock.getElapsedTime().asMicroseconds();             // ����� ��� � ���������� �� ������� ���
		clock.restart();
		TimeMiliSeconds = TimeMiliSeconds / 2000 * SPEED;

		if (TimeMiliSeconds > 5) TimeMiliSeconds = 5;           // �������� �������� ���

		Event event;                                   // ����� ����� OpenGL, ��� ����� ���� ���� ��������� � ���������, � �� ��� �� ���� �������
		while (myWindow.pollEvent(event)) {
			if (event.type == Event::Closed)
				myWindow.close();
		}

		input();
		update(TimeMiliSeconds);
		draw();
	}

}