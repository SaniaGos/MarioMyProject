#include "Window.h"

MyWindow::MyWindow() :// конструктор ≥грового в≥кна
    mario(MARIO, 3, MARIO_SPEED, Vector2f(100, 100), Vector2i(32, 32))
{
	myWindow.create(VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Mario By SaniaGos");    // з define берем розм≥р в≥кна ≥ даЇм йому назву
	myBackgroundTexture.loadFromFile(MY_BACKGROUND);                                                // берем картинку заднього фону
	myBackgroundSprite.setTexture(myBackgroundTexture);                                             // загружаЇм картинку в спрайт заднього фону
    map.loadMap(MAP1);
    m_Texture.loadFromFile(BRICK);
    m_Sprite.setTexture(m_Texture);
}

void MyWindow::start()
{
	Clock clock;
    mario.setFrames({
        IntRect(0,96,32,32),            // кадр сто€чого мар≥о
        
        IntRect(32,96,32,32),           // три кадри руху вправо
        IntRect(64,96,32,32),
        IntRect(96,96,32,32),
        
        IntRect(64,96,-32,32),          // три кадри руху вл≥во
        IntRect(96,96,-32,32),
        IntRect(128,96,-32,32),
        });
    
    while (myWindow.isOpen())
    {
        float TimeMiliSeconds = clock.restart().asMilliseconds();             // берем час в м≥л≥секундах в≥д початку гри
        
        TimeMiliSeconds = TimeMiliSeconds / 5;                               // регулюЇм швидк≥сть гри
        if (TimeMiliSeconds > 5) TimeMiliSeconds = 5;
     
        Event event;                                   // €кась шн€га OpenGL, щоб можна було в≥кно закривати ≥ перем≥щати, а то без нењ в≥кно завмираЇ
        while (myWindow.pollEvent(event)) {
            if (event.type == Event::Closed)
                myWindow.close();
        }


        input();
        update(TimeMiliSeconds);
        draw();
    }

}