#include "Game.h"

#include <fstream>


Game::Game()
{
}

void Game::inGame()
{
	int choice;
	cout << "Seleccion una Tematica: \n 1- Animales \n 2- Comidas \n 3- Paises" << endl;

	do
	{
		cin >> choice;
	} while (choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:

		soupText = openFileText(animalsSoupPath);

		break;
	case 2:

		soupText = openFileText(foodSoupPath);

		break;
	case 3:

		soupText = openFileText(countrysSoupPath);

		break;
	}

	cout << "asdasd " << soupText;
	//Pedir nombre del jugador

	system("pause");
}

string Game::openFileText(string path)
{
	string code;
	const int buffer_size = 248;
	char line[buffer_size];

	try
	{
		ifstream inputStream = ifstream();

		inputStream.open(path);

		if (!inputStream.good())
			throw ios::failure(" El archivo no se pudo abrir correctamente");


		while (!inputStream.eof())
		{
			inputStream >> line;
			code += (string)line + " ";
		}

		inputStream.close();

		if (inputStream.is_open())
			throw ios::failure("El archivo no se cerro correctamente!");

		return code;
	}

	catch (const ios::failure& e)
	{
		cout << "Hubo problemas con la interaccion con el archivo, " << e.what() << endl;
	}
}