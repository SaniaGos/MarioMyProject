#include "Window.h"


int main()
{
    auto a = GlobalConfig::GetConfig();
    
    MyWindow game;
    game.start();

    return 0;
}