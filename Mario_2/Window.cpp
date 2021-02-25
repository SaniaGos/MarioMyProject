#include "Window.h"

MyWindow::MyWindow() :// конструктор ≥грового в≥кна
	mario(Vector2f(100, 100), Vector2i(32, 32))
{
	myWindow.create(VideoMode(HORIZONTAL_RESOLUTION, VERTICAL_RESOLUTION), "Mario By SaniaGos");    // з define берем розм≥р в≥кна ≥ даЇм йому назву
	myBackgroundTexture.loadFromFile(MY_BACKGROUND);                                                // берем картинку заднього фону
	myBackgroundSprite.setTexture(myBackgroundTexture);                                             // загружаЇм картинку в спрайт заднього фону
	map.loadMap(MAP1);
	texture.loadFromFile(MAP_ATLAS);
	m_Sprite.setTexture(texture);
	TimeMiliSeconds = 0;
	buffer.loadFromFile(MUSIC);
	sound.setBuffer(buffer);
	font.loadFromFile(FONT);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setColor(Color::Green);
	text.setStyle(Text::Bold);
	text.setPosition(HORIZONTAL_RESOLUTION - 256, 32);
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
	loadPersonage();
	sound.play();
	

	while (myWindow.isOpen())
	{
		TimeMiliSeconds = clock.getElapsedTime().asMicroseconds();             // берем час в м≥л≥секундах в≥д початку гри
		sf::sleep(sf::microseconds(4000 - TimeMiliSeconds));


		clock.restart();
		TimeMiliSeconds = TimeMiliSeconds / 2000 * SPEED_GAME;

		if (TimeMiliSeconds > 5) TimeMiliSeconds = 5;           // регулюЇм швидк≥сть гри
		
		Event event;											// €кась шн€га OpenGL, щоб можна було в≥кно закривати ≥ перем≥щати, а то без нењ в≥кно завмираЇ
		while (myWindow.pollEvent(event)) {
			if (event.type == Event::Closed)
				myWindow.close();
		}

		input();
		update(TimeMiliSeconds);
		draw();
	}
	for (size_t i = 0; i < personage.size(); i++)
		delete personage[i];
}