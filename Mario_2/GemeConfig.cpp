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
		mario.life = stoi(config.at("mario_life"));
	}
	catch (std::exception& ex)
	{
		mario.life = 3;
		cout << "mario life no find " << ex.what() << endl;
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
