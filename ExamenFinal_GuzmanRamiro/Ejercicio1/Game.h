#pragma once

#include <iostream>
#include <vector>

#include "Entity.h"
#include "HUD.h"
#include "Player.h"

#include "StatisticsOfTheGame.h"
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

	static const int SIZE = 20;
	char levelMapGrid[SIZE][SIZE];
	
	int level = 0;

	void readLevelText();

#pragma endregion

	int coinsCollectibles = 0;

	Vector mapSize;
	Vector edgeDistance;
	Vector initialPositionPlayer;
	vector<Entity*> entity_vector;

	Player* player;
	HUD* hud;
	void draw();

	void drawMapGrid();

public:

	Game();
	~Game();

	void initGame();
	GameState updateGame(statisticsOfTheGame& gameStats);
	void resetGame();



};

