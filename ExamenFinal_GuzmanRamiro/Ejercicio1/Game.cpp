#include "Game.h"

#include <fstream>

#include "Awesome Library/AwesomeLibrary.h"
#include "LevelInstaller.h"

Game::Game()
{
}

Game::~Game()
{
	delete player;
}

void Game::initGame()
{
	string aux;

	aux = LevelInstaller::openFileText(levelsPath[rand() % LevelCount]);
	levelText = aux.c_str();

	edgeDistance = { 1 , 1 };
	player = new Player(Color::BLUE, edgeDistance);

	readLevelText();
}

GameState Game::updateGame()
{
	draw();

	//Hacer el guardado en archivo


	if (player->getSteps() <= 0 && player->getCurrentCollectibles() >= player->getMaxCollectibles())
	{
		return GameState::StateMenu;
	}
	return GameState::StateGame;
}

void Game::readLevelText()
{
	int numberOfRow = 0;
	int numberOfColums = 0;
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
			levelMapGrid[i][j] = (char)219; // █
			i++;
			break;

		case '-': //Espacio caminable
			levelMapGrid[i][j] = ' ';
			i++;
			break;

		case 'c': //Moneda
			levelMapGrid[i][j] = 'c';
			i++;

			break;
		case 'i': //Posicion Inicial

			player->setInitialPosition(i, j);
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
	drawMapGrid();
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
}

void Game::resetGame()
{
	system("cls");

	cout << "Ingrese su nombre de usuario: ";
	cin >> playerName;

	system("cls");

	drawMapGrid();
}
