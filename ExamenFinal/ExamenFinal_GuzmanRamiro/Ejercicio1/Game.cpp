#include "Game.h"

#include <fstream>

#include "Awesome Library/AwesomeLibrary.h"
#include "AlphabetSoupInstaller.h"


Game::Game()
{
}

GameState Game::inGame()
{
	int choice;
	string aux;

	cout << "Seleccion una Tematica: \n 1- Animales \n 2- Comidas \n 3- Paises" << endl;

	do
	{
		cin >> choice;
	} while (choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:

		//soupText = openFileText(animalsSoupPath);
		aux = AlphabetSoupInstaller::openFileText(animalsSoupPath);

		break;
	case 2:

		aux = AlphabetSoupInstaller::openFileText(foodSoupPath);

		break;
	case 3:

		aux = AlphabetSoupInstaller::openFileText(countrysSoupPath);

		break;
	}

	soupText = aux.c_str();
	system("cls");

	cout << "Ingrese su nombre de usuario: ";
	cin >> playerName;
	//Pedir nombre del jugador

	system("cls");

	readAlphabetSoup();

	readCorrectsWords();

	checkInputPlayer();

	system("pause");

	//Hacer el guardado en archivo

	return GameState::StateMenu;

}



void Game::readAlphabetSoup()
{
	int i = 0, j = 0;
	bool inBucle = true;
	do
	{
		switch (*soupText)
		{
		case ' ':
			j++;
			i = 0;
			break;

		case '*':
			alphabetSoipGrid[j][i] = rand() % 26 + 97;
			i++;
			break;

		case '+':
			inBucle = false;

		default:
			alphabetSoipGrid[j][i] = *soupText;
			i++;
			break;
		}

		soupText++;

	} while (inBucle);
}

void Game::readCorrectsWords()
{
	soupText++;
	int index = 0;
	char line[20]{};
	bool inBucle = true;
	int i = 0 ,j = 0;

	do
	{
		switch (*soupText)
		{
		case ' ':
			j++;
			i = 0;

			wordsToFind[index] = line;
			for (int i = 0; i < 20; i++)
			{
				line[i] = '\0';
			}
			index++;
			break;

		case '+':
			inBucle = false;

		default:
			line[i] = *soupText;
			i++;
			break;
		}

		soupText++;

	} while (inBucle);

}

void Game::checkInputPlayer()
{
	int counter = 0;
	bool inBucle = true;
	string words;
	do
	{
		system("cls");

		drawSoupGrid();
		drawWordsFounds();

		cin >> words;

		for (int i = 0; i < WORDSTOFINDCOUNT; i++)
		{
			if (words == wordsToFind[i])
			{
				wordsFound[i] = true;
				counter++;

				if (counter >= WORDSTOFINDCOUNT)
				{
					inBucle = false;
				}
			}
		}

	} while (inBucle);
}

void Game::drawSoupGrid()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << alphabetSoipGrid[i][j] << " ";
		}
		cout << endl;
	}
}

void Game::drawWordsFounds()
{
	for (int i = 0; i < WORDSTOFINDCOUNT; i++)
	{
		if (wordsFound[i])
		{
			goToCoordinates(25, 10 + i); //Funciona pero hay que adaptarlo
			cout << wordsToFind[i] << endl;
		}
	}
}

void Game::resetGame()
{
	for (int i = 0; i < WORDSTOFINDCOUNT; i++)
	{
		wordsFound[i] = false;
	}
}
