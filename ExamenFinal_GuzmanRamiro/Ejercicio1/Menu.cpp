#include "Menu.h"

#include "Awesome Library/AwesomeLibrary.h"

#include <iostream>

using namespace std;



Menu::Menu()
{
}

GameState Menu::updateMenu()
{
	system("cls");
	int choice;

	drawWelcome();

	drawMenuOptions(getScreenWidth() / 2 - 25 , 13, Color::LRED);

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

void Menu::drawWelcome()
{

	setForegroundColor(Color::LBLUE);
	int x = getScreenWidth() / 2 - 38;
	int y = 4;

	goToCoordinates(x, y);
	cout << ":::       ::: :::::::::: :::         ::::::::   ::::::::  ::::    ::::  :::::::::: " << endl;
	goToCoordinates(x, y + 1);
	cout << ":+:       :+: :+:        :+:        :+:    :+: :+:    :+: +:+:+: :+:+:+ :+:" << endl;
	goToCoordinates(x, y + 2);
	cout << "+:+       +:+ +:+        +:+        +:+        +:+    +:+ +:+ +:+:+ +:+ +:+" << endl;
	goToCoordinates(x, y + 3);
	cout << "+#+  +:+  +#+ +#++:++#   +#+        +#+        +#+    +:+ +#+  +:+  +#+ +#++:++#   " << endl;
	goToCoordinates(x, y + 4);
	cout << "+#+ +#+#+ +#+ +#+        +#+        +#+        +#+    +#+ +#+       +#+ +#+        " << endl;
	goToCoordinates(x, y + 5);
	cout << " #+#+# #+#+#  #+#        #+#        #+#    #+# #+#    #+# #+#       #+# #+#        " << endl;
	goToCoordinates(x, y + 6);
	cout << "  ###   ###   ########## ##########  ########   ########  ###       ### ########## " << endl;

	setForegroundColor(Color::WHITE);
}


void Menu::drawMenuOptions(int x, int y, Color color) //Dibujo las opciones del menu con los parametros que llegan
{
	setForegroundColor(color);

	goToCoordinates(x, y);
	cout << "  __        __     ____  __      __    _  _ " << endl;
	goToCoordinates(x, y + 1);
	cout << " /  )   ___ \\ \\   (  _ \\(  )    /__\\  ( \\/ )" << endl;
	goToCoordinates(x, y + 2);
	cout << "  )(   (___) > >   )___/ )(__  /(__)\\  \\  / " << endl;
	goToCoordinates(x, y + 3);
	cout << " (__)       /_/   (__)  (____)(__)(__) (__) " << endl;

	y += 5;

	goToCoordinates(x, y);
	cout << " ___         __     ___  ____    __    ____  ___ " << endl;
	goToCoordinates(x, y + 1);
	cout << "(__ \\    ___ \\ \\   / __)(_  _)  /__\\  (_  _)/ __)" << endl;
	goToCoordinates(x, y + 2);
	cout << " / _/   (___) > >  \\__ \\  )(   /(__)\\   )(  \\__ \\" << endl;
	goToCoordinates(x, y + 3);
	cout << "(____)       /_/   (___/ (__) (__)(__) (__) (___/" << endl;

	y += 6;

	goToCoordinates(x, y);
	cout << "(__ )   ___ \\ \\   ( ___)( \\/ )(_  _)(_  _)" << endl;
	goToCoordinates(x, y + 1);
	cout << " (_ \\  (___) > >   )__)  )  (  _)(_   )(  " << endl;
	goToCoordinates(x, y + 2);
	cout << "(___/       /_/   (____)(_/\\_)(____) (__) " << endl;

	setForegroundColor(Color::WHITE);
	goToCoordinates(24, getScreenHeight() - 1);
	cout << "Press 1 to go to the game, 2 to go to the Stats, 3 to exit" << endl;
}

