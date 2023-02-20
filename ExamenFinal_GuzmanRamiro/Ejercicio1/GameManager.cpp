#include "GameManager.h"

#include <iostream>

using namespace std;


GameManager::GameManager()
{
	init();

	while (insideGame)
	{
		update();
	}

	deInit();
}

void GameManager::deInit()
{
	delete menu;
	delete game;
	delete stats;
}

void GameManager::init()
{
	srand(time(NULL));
	hideCursor();

	menu = new Menu();
	game = new Game();
	stats = new PlayersStats();

	game->initGame();
	gameStats = stats->initPlayersStats();
}

void GameManager::update()
{
	switch (state)
	{

	case GameState::StateMenu:

		if (!resetValues)
		{
			resetValues = true;
		}
		state = menu->updateMenu();

		break;

	case GameState::StateGame:

		if (resetValues)
		{
			game->resetGame();
			resetValues = false;
		}
		state = game->updateGame(gameStats);

		if (state == GameState::StateMenu)
		{
			stats->checkNewScore(gameStats);
		}

		break;

	case GameState::StateStats:

		state = stats->updatePlayerStats();

		break;

	case GameState::StateExit:

		insideGame = false;

		break;

	default:
		break;
	}

}