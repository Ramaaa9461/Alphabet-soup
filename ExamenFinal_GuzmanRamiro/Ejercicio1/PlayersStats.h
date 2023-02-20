#pragma once

#include "GameState.h"
#include "StatisticsOfTheGame.h"
#include "Awesome Library/AwesomeLibrary.h"

#include <iostream>
#include <fstream>

using namespace std;

class PlayersStats
{

private:

	const string Gamepath = "GameStats.dat";
	statisticsOfTheGame gameStats;

	ifstream inputStream;
	ofstream outputStream;

	void readGameStats();
	void writeGameStats();

	void drawPlayerStats(int x, int y, Color color);

public:

	PlayersStats();

	statisticsOfTheGame initPlayersStats();
	GameState updatePlayerStats();

	void checkNewScore(statisticsOfTheGame gameStats);

	statisticsOfTheGame getGameStats();

};

