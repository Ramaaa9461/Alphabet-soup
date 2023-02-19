#pragma once

#include <iostream>

#include "Entity.h"
#include "Player.h"

#include "GameState.h"


using namespace std;

class Game
{

private:

#pragma region Mapa y lectura de archivo
	static const int LevelCount = 3;
	const string levelsPath[LevelCount] = { "Levels/level1.txt" , "Levels/level2.txt" , "Levels/level3.txt"};

	const char* levelText;
	string playerName;

	static const int SIZE = 10;
	char levelMapGrid[SIZE][SIZE];

	void readLevelText();

#pragma endregion

	Vector mapSize;
	Vector edgeDistance;

	Player* player;
	void draw();

	void drawMapGrid();

public:

	Game();
	~Game();

	void initGame();
	GameState updateGame();
	void resetGame();



};

