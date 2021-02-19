#include "Map.h"

void Map::loadMap(const string path)
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
			map.push_back(tmp);
		}
		file_in.close();
}

Map::Map(){}

vector<string>& Map::getMap() { return map; }

void Map::update(RenderWindow& myWindow)
{
   
        
    
}
