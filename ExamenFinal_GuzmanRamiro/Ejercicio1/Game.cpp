#include "Game.h"

#include <fstream>

#include "Awesome Library/AwesomeLibrary.h"
#include "LevelInstaller.h"

#include "Coin.h"
#include "Wall.h"

Game::Game()
{
}

Game::~Game()
{
	delete player;
	delete hud;

	for (int i = 0; i < entity_vector.size(); i++)
	{
		delete entity_vector[i];
	}
}

void Game::initGame()
{
	string aux;

	level = rand() % LevelCount;
	aux = LevelInstaller::openFileText(levelsPath[level]);
	levelText = aux.c_str();

	readLevelText();
	edgeDistance = { getScreenWidth() / 2 - mapSize.x / 2, getScreenHeight() / 2 - mapSize.y / 2};
	player = new Player(Color::BLUE, edgeDistance);
	player->setInitialPosition(initialPositionPlayer.x, initialPositionPlayer.y);

	
	hud = new HUD(player, coinsCollectibles);
}

GameState Game::updateGame(statisticsOfTheGame& gameStats)
{

	for (int i = 0; i < entity_vector.size(); i++)
	{
		entity_vector[i]->checkCollisions(player);

		entity_vector[i]->draw();
	}

	draw();


	if (player->getCoins() >= coinsCollectibles)
	{
		gameStats.playerName = playerName;
		gameStats.maximumAmountOfSteps = player->getSteps();
		gameStats.timesPlaysByLevel[level] ++;

		system("cls");
		return GameState::StateMenu;
	}
	return GameState::StateGame;
}

void Game::readLevelText()
{

	int i = 0, j = 0;
	bool inBucle = true;
	do
	{
		switch (*levelText)
		{
		case ' ': // Cambio de fila
			if (j == 0)
			{
				mapSize.x = i;
			}
			j++;
			i = 0;
			break;

		case '*': // Pared
			
			entity_vector.push_back(new Wall(Color::YELLOW, { i + edgeDistance.x, j + edgeDistance.y }));

			i++;
			break;

		case '-': //Espacio caminable
			
			levelMapGrid[i][j] = ' ';

			i++;
			break;

		case 'c': //Moneda

			entity_vector.push_back(new Coin(Color::BROWN, {i + edgeDistance.x, j + edgeDistance.y}));
			coinsCollectibles++;
			i++;

			break;
		case 'i': //Posicion Inicial

			initialPositionPlayer = { i , j };
			//player->setInitialPosition(i, j);
			i++;

			break;

		case '+':
			inBucle = false;
			break;
		}

		levelText++;

	} while (inBucle);

	mapSize.y = j;

}

void Game::draw()
{
	player->draw();
	hud->printStats();

//	drawMapGrid();
}

void Game::drawMapGrid()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			goToCoordinates(edgeDistance.x + i, edgeDistance.y + j);
			cout << levelMapGrid[i][j];
		}
		cout << endl;
	}

	setForegroundColor(Color::LBLUE);
	drawFrame(edgeDistance.x - 1, edgeDistance.y - 1, edgeDistance.x + mapSize.x, edgeDistance.y + mapSize.y);
	setForegroundColor(Color::WHITE);
}

void Game::resetGame()
{
	for (int i = 0; i < entity_vector.size(); i++)
	{
		entity_vector.clear();
	}
	coinsCollectibles = 0;
	player->restart();

	initGame();
	system("cls");

	cout << "Ingrese su nombre de usuario: ";
	cin >> playerName;

	//system("cls");

	drawMapGrid();
}
