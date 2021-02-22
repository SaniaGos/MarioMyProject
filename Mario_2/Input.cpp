#include "Window.h"

void MyWindow::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        myWindow.close();
    }
   
    // Опрацьовуємо нажимання клавіш керування Маріо //
   
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        mario.moveRight();
    }
    else
    {
        mario.stopRight();
    }
   
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        mario.moveLeft();
    }
    else
    {
        mario.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        mario.moveUp();
    }
    else
    {
        mario.stopUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        mario.moveDown();
    }
    else
    {
        mario.stopDown();
    }

}