#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Define.h"

using namespace sf;
using namespace std;

class Map
{
private:
    vector<string> map;
public:

    Map();
    Vector2f offset;
    vector<string>& getMap();
    void loadMap(string path);
};