#include "Window.h"

void MyWindow::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        myWindow.close();
    }
   
    // Опрацьовуємо нажимання клавіш керування Маріо //
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        //Mario.moveLeft();
    }
    else
    {
        //Mario.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        //Mario.moveRight();
    }
    else
    {
        //Mario.stopRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        //Mario.moveUp();
    }
    else
    {
        //Mario.stopUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        //Mario.moveDown();
    }
    else
    {
        //Mario.stopDown();
    }

}