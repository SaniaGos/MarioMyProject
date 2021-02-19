#include "Window.h"

MyWindow::MyWindow() :// конструктор ігрового вікна
    mario(MARIO, 3, MARIO_SPEED, FloatRect(100, 100, 32, 32))
{
	myWindow.create(VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Mario By SaniaGos");    // з define берем розмір вікна і даєм йому назву
	myBackgroundTexture.loadFromFile(MY_BACKGROUND);                                                // берем картинку заднього фону
	myBackgroundSprite.setTexture(myBackgroundTexture);                                             // загружаєм картинку в спрайт заднього фону
    map.loadMap(MAP1);
    m_Texture.loadFromFile(BRICK);
    m_Sprite.setTexture(m_Texture);
}

void MyWindow::start()
{
	Clock clock;
    
    while (myWindow.isOpen())
    {
        float TimeMiliSeconds = clock.restart().asMilliseconds();             // берем час в мілісекундах від початку гри
        
        TimeMiliSeconds = TimeMiliSeconds / 10;                               // регулюєм швидкість гри
        if (TimeMiliSeconds > 10) TimeMiliSeconds = 10;
     
        Event event;                                   // якась шняга OpenGL, щоб можна було вікно закривати і переміщати, а то без неї вікно завмирає
        while (myWindow.pollEvent(event)) {
            if (event.type == Event::Closed)
                myWindow.close();
        }


        input();
        update(TimeMiliSeconds);
        draw();
    }

}