#pragma once

#include <iostream>

using namespace std;

class Game
{

private:

	const string animalsSoupPath = "TematicsSoups/AnimalsSoup.txt";
	const string foodSoupPath = "TematicsSoups/FoodSoup.txt";
	const string countrysSoupPath = "TematicsSoups/CountysSoup.txt";

	string soupText;

	string openFileText(string path);

public:

	Game();

	void inGame();


};

