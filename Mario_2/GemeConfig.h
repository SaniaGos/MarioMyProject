#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <map>

using namespace sf;
using namespace std;

struct ConfigMap
{
	string music;
	string background;
	size_t horizontal_rezolution;
	size_t vertical_rezolution;
	string level_1;
	string map_atlas;
	string font;
	size_t atlas_width;
	size_t atlas_height;
	float  speed;
};
struct ConfigPlayer
{
	string music;
	size_t frames;
	size_t life;
	float  speed;
};

class GameConfig
{
	map<string, string> config;
	void loadCongif(const string path);
	void fillData();
	pair<string, string> split(string str);
public:
	GameConfig();

	ConfigMap map;
	ConfigPlayer mario;
	ConfigPlayer money;
	ConfigPlayer mushroom;
	ConfigPlayer turtle;
	string mario_atlas;
	string enemie_atlas;
	string item_atlas;
};

class GlobalConfig
{
	static GameConfig* instance;
public:

	static GameConfig& GetConfig();
};
