#include "Window.h"

MyWindow::MyWindow() :// ����������� �������� ����
    mario(MARIO, 3, MARIO_SPEED, Vector2f(100, 100), Vector2i(32, 32))
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
    mario.setFrames({
        IntRect(0,96,32,32),            // ���� �������� ����
        
        IntRect(32,96,32,32),           // ��� ����� ���� ������
        IntRect(64,96,32,32),
        IntRect(96,96,32,32),
        
        IntRect(64,96,-32,32),          // ��� ����� ���� ����
        IntRect(96,96,-32,32),
        IntRect(128,96,-32,32),
        });
    
    while (myWindow.isOpen())
    {
        float TimeMiliSeconds = clock.restart().asMilliseconds();             // ����� ��� � ���������� �� ������� ���
        
        TimeMiliSeconds = TimeMiliSeconds / 5;                               // �������� �������� ���
        if (TimeMiliSeconds > 5) TimeMiliSeconds = 5;
     
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