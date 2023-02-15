#include "GameManager.h"

#include <iostream>

using namespace std;


GameManager* GameManager::S_GameManager = nullptr;

GameManager* GameManager::getGameManager()
{
	if (S_GameManager == nullptr) {
		S_GameManager = new GameManager();
	}
	return S_GameManager;
}

void GameManager::changeState(GameState newState)
{
	state = newState;
}

void GameManager::changeInsideGameBoolean(bool insideGame)
{
	this->insideGame = insideGame;
}

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
	cout << &state << endl;
	menu = new Menu();
	game = new Game();
	stats = new PlayersStats();
}

void GameManager::update()
{
	system("cls");

	switch (state)
	{

	case GameState::StateMenu:

		state = menu->inMenu();

		break;

	case GameState::StateGame:

		game->inGame();

		break;

	case GameState::StateStats:

		stats->inStats();

		break;

	case GameState::StateExit:

		insideGame = false;

		break;

	default:
		break;
	}

}