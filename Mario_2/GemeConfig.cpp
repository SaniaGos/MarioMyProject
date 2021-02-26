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
	mario.speed = stof(config["mario_speed"]);
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
