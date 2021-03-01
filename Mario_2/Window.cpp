#include "Window.h"

MyWindow::MyWindow() :// ����������� �������� ����
	mario(Vector2f(100, 100), Vector2i(32, 32)),
	frames()
{
	myWindow.create(VideoMode(GlobalConfig::GetConfig().map.horizontal_resolution, GlobalConfig::GetConfig().map.vertical_resolution), "Mario By SaniaGos");    // � define ����� ����� ���� � ��� ���� �����
	myBackgroundTexture.loadFromFile(GlobalConfig::GetConfig().map.background);                                                // ����� �������� �������� ����
	myBackgroundSprite.setTexture(myBackgroundTexture);                                             // �������� �������� � ������ �������� ����
	map.loadMap(GlobalConfig::GetConfig().map.level_1);
	texture.loadFromFile(GlobalConfig::GetConfig().map.map_atlas);
	m_Sprite.setTexture(texture);
	TimeMiliSeconds = 0;
	buffer.loadFromFile(GlobalConfig::GetConfig().map.music);
	sound.setBuffer(buffer);
	font.loadFromFile(GlobalConfig::GetConfig().map.font);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(Color::Green);
	text.setStyle(Text::Bold);
	text.setPosition(GlobalConfig::GetConfig().map.horizontal_resolution - 256, 32);
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
		TimeMiliSeconds = TimeMiliSeconds / 2000 * GlobalConfig::GetConfig().map.speed;

		if (TimeMiliSeconds > 20) TimeMiliSeconds = 20;           // �������� �������� ���
		
		Event event;											// ����� ����� OpenGL, ��� ����� ���� ���� ��������� � ���������, � �� ��� �� ���� �������
		while (myWindow.pollEvent(event)) {
			if (event.type == Event::Closed)
				myWindow.close();
		}

		input();
		update(TimeMiliSeconds);
		TimeMiliSeconds = clock.getElapsedTime().asMicroseconds();             // ����� ��� � ���������� �� ������� ���
		sf::sleep(sf::microseconds(12000 - TimeMiliSeconds));
		draw();
	}
	for (size_t i = 0; i < personage.size(); i++)
		delete personage[i];
}