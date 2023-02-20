#include "HUD.h"

#include <iostream>
using namespace std;

HUD::HUD(Player* player, int totalcoins)
{
	this->player = player;
	totalCoins = totalcoins;

	//setForegroundColor(Color::BLUE);
	//drawFrame(2, getScreenHeight() - 3, getScreenWidth() - 1, getScreenHeight());
}

HUD::~HUD()
{
}

void HUD::printStats()
{
	goToCoordinates(3, getScreenHeight() - 2);

	setForegroundColor(Color::WHITE);

	cout << "Steps = [";

	setForegroundColor(Color::MAGENTA);

	cout << player->getSteps();

	setForegroundColor(Color::WHITE);

	cout << "]";




	goToCoordinates(getScreenWidth() - 20, getScreenHeight() - 2);
	
	setForegroundColor(Color::WHITE);

	cout << "Coins = [";

	setForegroundColor(Color::MAGENTA);

	cout << player->getCoins() << " / " << totalCoins;

	setForegroundColor(Color::WHITE);
	
	cout << "]";
}
