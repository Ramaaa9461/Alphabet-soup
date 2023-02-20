#pragma once

#include "Player.h"

class HUD
{
private:
	Player* player;

	int totalCoins;
public:
	HUD(Player* player, int totalconis);
	~HUD();

	void printStats();
};

