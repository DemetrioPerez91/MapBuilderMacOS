
#include <stdio.h>
#include "FileManager.h"
FileManager * FileManager::ms_pInstance = NULL;

FileManager::FileManager()
{
}

int FileManager::getTimeStamp(std::string url)
{
	int timeStamp =0 ;
	struct stat st;
	int ierr = stat(url.c_str(), &st);
	if (ierr != 0)
	{
		printf("getTimeStamp Error\n");
	}
	timeStamp = int(st.st_mtime);
	return timeStamp;
}
void FileManager::loadFile()
{
	std::string tempURL;
	switch(map)
	{
		case ZELDA:
			tempURL = url2;
			zeldaTimeStamp = getTimeStamp(atlasURL.c_str());
			break;
		case POKEMON:
			tempURL = url;
			pokemonTimeStamp = getTimeStamp(atlasURL.c_str());
			break;
	}
	while(!tileNumbers.empty())
	{
		tileNumbers.pop_back();
	}

    
    mFile = fopen(tempURL.c_str(), "r");
    
	if(mFile == NULL)
	{
		printf("Could not load map file: %s \n",tempURL.c_str());
	}
	else
	{
        //Reading map file
        //TO DO: Split in testable method
		char tileSetURL[256] ;
        fscanf(mFile, "TILE_SET %256s ;\n",&tileSetURL );
		printf("%s\n", tileSetURL);
		atlasURL = tileSetURL;
		fscanf(mFile, "SIZE %d;\n", &mapSize);
		printf("SIZE %d\n",mapSize);
		printf("FILE LOADED \n");
		fscanf(mFile, "LINEBREAKS %d;\n", &lineBreak);
		printf("LineBrakes %i \n", lineBreak);
		fscanf(mFile, "COLLUMNS %d;\n", &collumns);
		printf("COLLUMNS %i \n", collumns);
		
        state = READ_MAP;
		int temp=0;
		int i = 0;
		int j = 0;
		while(state!= CLOSE_MAP)
		{
			fscanf(mFile, " %d,", &temp);
			printf("%i", temp);
			tileNumbers.push_back(temp);
			
			i++;
			if(i==collumns)
			{
				fscanf(mFile,"\n");
				printf("\n");
				i = 0;
				j++;
			}
			if(j==lineBreak)
			{
				state = CLOSE_MAP;
			}
		}
		printf("CHECK VECTOR\n\n\n");
		for (int i = 0; i < lineBreak;i++)
		{
			for (int j = 0; j < collumns;j++)
			{
				printf("%i,",tileNumbers.at((i*16)+j));
			}
			printf("\n");
		}
	}
	fclose(mFile);
}

void FileManager::writeFile(Tile * tiles,int nTiles)
{
	std::string tempURL;
	switch (map)
	{
	case ZELDA:
		tempURL = url2;
		break;
	case POKEMON:
		tempURL = url;
		break;
	}
	std::string fileText = "";
	std::string nCollums = std::to_string(collumns);
	std::string lBreaks = std::to_string(lineBreak);
	std::string tileSize = std::to_string(mapSize);
	fileText = "TILE_SET " + atlasURL + " ;\nSIZE " + tileSize + ";\nLINEBREAKS " + lBreaks + ";\n" + "COLLUMNS " + nCollums + ";\n";
	for (int i = 0; i < nTiles; i++)
	{
		if (tiles[i].tileType<10)
		{
			fileText = fileText + "0";
		}
		if(i % collumns == 0 && i != 0)
		{
			
			fileText = fileText + std::to_string(tiles[i].tileType)+",\n";

		}
		else
		{
			fileText = fileText + std::to_string(tiles[i].tileType) + ",";
		}
	}
	
	//printf(fileText.c_str());
	mFile = fopen( tempURL.c_str(), "w");
	fputs(fileText.c_str(),mFile);
	fclose(mFile);

	
		
}

int FileManager::checkForUpdates()
{
	

	struct stat st;
	int ierr= stat(atlasURL.c_str(), &st);
	if (ierr != 0) 
	{
		printf( "error");
	}
	int newdate = int(st.st_mtime);
	switch(map)
	{
		case ZELDA:
			
			if(newdate==zeldaTimeStamp)
			{
				return 0;
			}
			else
			{
				zeldaTimeStamp = newdate;
				return 1;
			}
		break;
		case POKEMON:
			if (newdate == pokemonTimeStamp)
			{
				return 0;
			}
			else
			{
				pokemonTimeStamp = newdate;
				return 1;
			}
		break;
	}
    return 0;
}


FileManager::~FileManager()
{
}
	
