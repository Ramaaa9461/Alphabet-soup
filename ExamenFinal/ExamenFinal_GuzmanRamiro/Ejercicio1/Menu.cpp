#include "Menu.h"

#include <iostream>

using namespace std;


Menu::Menu()
{
}

GameState Menu::inMenu()
{
	int choice;

	cout << "Seleccion una opcion: \n 1- Jugar \n 2- Ver Estadisticas \n 3- Salir" << endl;

	do
	{
		cin >> choice;

	} while (choice < 1 || choice > 3);

	switch (choice)
	{

	case 1:

		return GameState::StateGame;
		break;

	case 2:

		return GameState::StateStats;
		break;

	case 3:

		return GameState::StateExit;
		break;
	}
}
