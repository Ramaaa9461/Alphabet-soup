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

}



void GameManager::init()
{

}

void GameManager::update()
{

	system("cls");

	switch (state)
	{

	case GameState::Menu:

		inMenu();

		break;
	
	case GameState::Game:
		
		inGame();
		
		break;

	case GameState::Stats:

		inStats();
		
		break;
	
	default:
		break;
	}

}

void GameManager::inMenu()
{
	int choice;
	cout << "Bienvenido!!! " << endl << endl;

	cout << "Seleccion una opcion: \n 1- Jugar \n 2- Ver Estadisticas \n 3- Salir";

	do
	{

		cin >> choice;

	} while (choice < 1 || choice > 3);

	switch (choice)
	{

	case 1: 
		state = GameState::Game;
		break;

	case 2:
		state = GameState::Stats;
		break;
	case 3:
		insideGame = false;
		break;

	default:
		system('cls');
		inMenu(); 
		break;
	}
}

void GameManager::inGame()
{
}

void GameManager::inStats()
{
}

