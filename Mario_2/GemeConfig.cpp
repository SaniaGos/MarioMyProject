#include "GemeConfig.h"

GameConfig* GlobalConfig::instance = nullptr;

void GameConfig::loadCongif(const string path)
{
	std::ifstream file_in;
	file_in.open(path);
	if (!file_in.is_open())
	{
		throw exception("cant open Map!");
	}
	while (!file_in.eof())
	{
		string tmp;
		getline(file_in, tmp);
		pair<string, string> param = split(tmp);
		config[param.first] = param.second;
	}
	file_in.close();
	fillData();
}

void GameConfig::fillData()
{
	// ****** Display ****** //
	try
	{
		map.horizontal_resolution = stoi(config.at("horizontal_resolution"));
	}
	catch (std::exception& ex)
	{
		map.horizontal_resolution = 800;
		cout << "horizontal resolution no find " << ex.what() << endl;
	}
	try
	{
		map.vertical_resolution = stoi(config.at("vertical_resolution"));
	}
	catch (std::exception& ex)
	{
		map.vertical_resolution = 600;
		cout << "vertical resolution no find " << ex.what() << endl;
	}
	try
	{
		map.background = config.at("background");
	}
	catch (std::exception& ex)
	{
		map.background = "Resorses/Sky.png";
		cout << "background no find " << ex.what() << endl;
	}
	try
	{
		map.music = config.at("map_music");
	}
	catch (std::exception& ex)
	{
		map.music = "Resorses/music/Theme.ogg";
		cout << "map music no find " << ex.what() << endl;
	}
	try
	{
		map.level_1 = config.at("level_1");
	}
	catch (std::exception& ex)
	{
		map.level_1 = "Resorses/Map/Level_1.txt";
		cout << "map level no find " << ex.what() << endl;
	}
	try
	{
		map.map_atlas = config.at("map_atlas");
	}
	catch (std::exception& ex)
	{
		map.map_atlas = "Resorses/Tiles.png";
		cout << "map atlas no find " << ex.what() << endl;
	}
	try
	{
		map.font = config.at("map_font");
	}
	catch (std::exception& ex)
	{
		map.font = "Resorses/Fonts/some_font.ttf";
		cout << "map font no find " << ex.what() << endl;
	}
	try
	{
		map.speed = stof(config.at("game_speed"));    // <stof> string to float
	}
	catch (std::exception& ex)
	{
		map.speed = 1.f;
		cout << "game speed no find " << ex.what() << endl;
	}
	try
	{
		map.atlas_width = stoi(config.at("atlas_width"));
	}
	catch (std::exception& ex)
	{
		map.atlas_width = 32;
		cout << "atlas width no find " << ex.what() << endl;
	}
	try
	{
		map.atlas_height = stoi(config.at("atlas_height"));
	}
	catch (std::exception& ex)
	{
		map.atlas_height = 32;
		cout << "atlas height no find " << ex.what() << endl;
	}
	
	// ****** Mario ******/
	try
	{
		mario.speed = stof(config.at("mario_speed"));    // <stof> string to float
	}
	catch (std::exception& ex)
	{
		mario.speed = 1.5;
		cout << "mario speed no find "<< ex.what() << endl;
	}
	try
	{
		mario.music = config.at("mario_music");
	}
	catch (std::exception& ex)
	{
		mario.music = "Resorses/music/jump.wav";
		cout << "mario music no find " << ex.what() << endl;
	}
	try
	{
		mario.life = stoi(config.at("mario_life"));
	}
	catch (std::exception& ex)
	{
		mario.life = 3;
		cout << "mario life no find " << ex.what() << endl;
	}
	try
	{
		mario_atlas = config.at("mario_atlas");
	}
	catch (std::exception& ex)
	{
		mario_atlas = "Resorses/Mario.png";
		cout << "mario atlas no find " << ex.what() << endl;
	}

	// ****** Enemies ****** //
	try
	{
		enemieSpeed = stoi(config.at("enemie_speed"));
	}
	catch (std::exception& ex)
	{
		enemieSpeed = 1;
		cout << "mushroom life no find " << ex.what() << endl;
	}
	try
	{
		maxDistance = stoi(config.at("maxDistance"));
	}
	catch (std::exception& ex)
	{
		maxDistance = 256;
		cout << "maxDistance no find " << ex.what() << endl;
	}
	try
	{
		enemie_atlas = config.at("enemie_atlas");
	}
	catch (std::exception& ex)
	{
		enemie_atlas = "Resorses/Enemies.png";
		cout << "enemie atlas no find " << ex.what() << endl;
	}
	try
	{
		item_atlas = config.at("item_atlas");
	}
	catch (std::exception& ex)
	{
		item_atlas = "Resorses/Items.png";
		cout << "item atlas no find " << ex.what() << endl;
	}
	
	// ****** Money ******//
	try
	{
		money.life = stoi(config.at("money_life"));
	}
	catch (std::exception& ex)
	{
		money.life = 1;
		cout << "money life no find " << ex.what() << endl;
	}
	try
	{
		money.speed = stof(config.at("money_speed"));    // <stof> string to float
	}
	catch (std::exception& ex)
	{
		money.speed = 1.f;
		cout << "money speed no find " << ex.what() << endl;
	}
	try
	{
		money.music = config.at("money_music");
	}
	catch (std::exception& ex)
	{
		money.music = "Resorses/music/coin.wav";
		cout << "money music no find " << ex.what() << endl;
	}

	// ****** Mushrooms ****** //
	try
	{
		mushroom.life = stoi(config.at("mushroom_life"));
	}
	catch (std::exception& ex)
	{
		mushroom.life = 4;
		cout << "mushroom life no find " << ex.what() << endl;
	}
	try
	{
		mushroom.speed = stof(config.at("mushroom_speed"));    // <stof> string to float
	}
	catch (std::exception& ex)
	{
		mushroom.speed = 1.f;
		cout << "mushroom speed no find " << ex.what() << endl;
	}
	try
	{
		mushroom.music = config.at("mushroom_music");
	}
	catch (std::exception& ex)
	{
		mushroom.music = "";
		cout << "mushroom music no find " << ex.what() << endl;
	}
	
	// ****** Turtle ****** //
	try
	{
		turtle.life = stoi(config.at("turtle_life"));
	}
	catch (std::exception& ex)
	{
		turtle.life = 2;
		cout << "turtle life no find " << ex.what() << endl;
	}
	try
	{
		turtle.speed = stof(config.at("turtle_speed"));    // <stof> string to float
	}
	catch (std::exception& ex)
	{
		turtle.speed = 1.f;
		cout << "turtle speed no find " << ex.what() << endl;
	}
	try
	{
		turtle.music = config.at("turtle_music");
	}
	catch (std::exception& ex)
	{
		turtle.music = "";
		cout << "turtle music no find " << ex.what() << endl;
	}
	
}

pair<string, string> GameConfig::split(string str)
{
	return pair<string, string>(str.substr(0, str.find(':')), str.substr(str.find(':') + 1));
}

GameConfig::GameConfig()
{
	try
	{
		loadCongif("Config.txt");
	}
	catch (std::exception& ex)
	{
		 cout << ex.what();
	}

}

GameConfig& GlobalConfig::GetConfig()
{
	if (instance == nullptr)
	{
		instance = new GameConfig();
	}
	return *instance;
}
