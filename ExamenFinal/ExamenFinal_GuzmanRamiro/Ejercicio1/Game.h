#pragma once

#include <iostream>

#include "GameState.h"

using namespace std;

class Game
{

private:

	const string animalsSoupPath = "TematicsSoups/AnimalsSoup.txt";
	const string foodSoupPath = "TematicsSoups/FoodSoup.txt";
	const string countrysSoupPath = "TematicsSoups/CountysSoup.txt";

	const char* soupText;
	string playerName;
	string message;

	static const int WORDSTOFINDCOUNT = 5;
	string wordsToFind[WORDSTOFINDCOUNT];
	bool wordsFound[WORDSTOFINDCOUNT];

	static const int SIZE = 10;
	char alphabetSoipGrid[SIZE][SIZE];

	void readAlphabetSoup();
	void readCorrectsWords();
	void checkInputPlayer();

	void drawSoupGrid();
	void drawWordsFounds();

public:

	Game();

	GameState inGame();
	void resetGame();



};

