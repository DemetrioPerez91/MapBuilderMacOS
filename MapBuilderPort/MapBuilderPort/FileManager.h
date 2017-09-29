#pragma once
#ifndef FILE_MANAGER
#define FILE_MANAGER
#include <string>
#include <vector>
#include "Tile.h"
#include <sys/types.h>
#include <sys/stat.h> 

class FileManager
{
protected:
	FileManager();
	~FileManager();
	FileManager(const FileManager &) {}
	FileManager& operator =(const FileManager &) {}

public:
	static FileManager * GetInstance() {
		if (ms_pInstance == NULL)
			ms_pInstance = new FileManager;
		return ms_pInstance;
	}
	 void DestroyInstance() {
		if (ms_pInstance)
		{
			delete ms_pInstance;
			ms_pInstance = NULL;
		}
	}
	 std::string url = "Data\\Maps\\PokemonMaps\\map.map";
	 std::string url2 = "Data\\Maps\\zeldaMaps\\map.map";
	 std::vector<int> tileNumbers;
	 int collumns = 0;
	 int size = 0;
	 std::string atlasURL;
	 int map;
	 int pokemonTimeStamp = 0;
	 int zeldaTimeStamp = 0;
	 FILE * FileManager::mFile = NULL;
	 int state = 0;
	 int lineBreak = 0;
	 void loadFile();
	 void writeFile(Tile * tiles,int nTiles);
	 int checkForUpdates();
	 int getTimeStamp(std::string url);


	enum Maps
	{
		ZELDA,POKEMON
	};

	enum readingStates
	{
		LINE_BRAKES,
		READ_MAP,
		CLOSE_MAP
	};

protected:
	static FileManager * ms_pInstance;
};
#endif

