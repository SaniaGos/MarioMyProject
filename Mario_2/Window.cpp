#include "Window.h"

MyWindow::MyWindow() :// ����������� �������� ����
    mario(MARIO, 3, MARIO_SPEED, FloatRect(100, 100, 32, 32))
{
	myWindow.create(VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Mario By SaniaGos");    // � define ����� ����� ���� � ��� ���� �����
	myBackgroundTexture.loadFromFile(MY_BACKGROUND);                                                // ����� �������� �������� ����
	myBackgroundSprite.setTexture(myBackgroundTexture);                                             // �������� �������� � ������ �������� ����
    map.loadMap(MAP1);
    m_Texture.loadFromFile(BRICK);
    m_Sprite.setTexture(m_Texture);
}

void MyWindow::start()
{
	Clock clock;
    
    while (myWindow.isOpen())
    {
        float TimeMiliSeconds = clock.restart().asMilliseconds();             // ����� ��� � ���������� �� ������� ���
        
        TimeMiliSeconds = TimeMiliSeconds / 10;                               // �������� �������� ���
        if (TimeMiliSeconds > 10) TimeMiliSeconds = 10;
     
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