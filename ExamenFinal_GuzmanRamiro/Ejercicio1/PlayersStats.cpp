#include "PlayersStats.h"


void PlayersStats::readGameStats()
{
	try
	{
		inputStream.open(Gamepath, ios::in | ios::binary);

		if (!inputStream.good())
		{
			outputStream.open(Gamepath);

			if (!outputStream.good())
			{
				throw ios::failure(" El archivo no se pudo abrir correctamente");
			}
		}


		inputStream.read((char*)&gameStats, sizeof(statisticsOfTheGame));

		inputStream.close();

		if (inputStream.is_open())
			throw ios::failure("El archivo no se cerro correctamente!");

	}

	catch (const ios::failure& e)
	{
		cout << "Hubo problemas con la interaccion con el archivo, " << e.what() << endl;
	}
}

void PlayersStats::writeGameStats()
{
	try
	{
		outputStream.open(Gamepath, ios::out | ios::binary);

		if (!outputStream.good())
			throw ios::failure(" El archivo no se pudo abrir correctamente");

		outputStream.write((char*)&gameStats, sizeof(statisticsOfTheGame));

		outputStream.close();

		if (outputStream.is_open())
			throw ios::failure("El archivo no se cerro correctamente!");
	}

	catch (const ios::failure& e)
	{
		cout << "Hubo problemas con la interaccion con el archivo, " << e.what() << endl;
	}
}

PlayersStats::PlayersStats()
{
}

PlayersStats::~PlayersStats()
{
}

statisticsOfTheGame PlayersStats::initPlayersStats()
{
	readGameStats();
	return gameStats;
}

GameState PlayersStats::updatePlayerStats()
{

	system("cls");

	drawPlayerStats(getScreenWidth() / 2 - 34, 4, Color::LBLUE);

	goToCoordinates(getScreenWidth() / 2 - 10, getScreenHeight() / 2);
	cout << "Player name: " << gameStats.playerName << endl;
	goToCoordinates(getScreenWidth() / 2 - 10, getScreenHeight() / 2 + 2);
	cout << "Amount of steps: " << gameStats.maximumAmountOfSteps << endl;

	for (int i = 0; i < gameStats.levelCount; i++)
	{
		goToCoordinates(getScreenWidth() / 2 - 10, getScreenHeight() / 2 + 4 + i);
		cout << "Time played level " << i + 1 << ": " << gameStats.timesPlaysByLevel[i] << endl;
	}

	goToCoordinates(getScreenWidth() / 2 - 20, getScreenHeight() - 1);
	system("pause");
	return GameState::StateMenu;
}

void PlayersStats::checkNewScore(statisticsOfTheGame gameStats)
{
	if (gameStats.maximumAmountOfSteps < this->gameStats.maximumAmountOfSteps) //El nuevo tiene menos pasos qe el viejo
	{
		this->gameStats.playerName = gameStats.playerName;
		this->gameStats.maximumAmountOfSteps = gameStats.maximumAmountOfSteps;
	}

	for (int i = 0; i < gameStats.levelCount; i++)
	{
		if (this->gameStats.timesPlaysByLevel[i] != gameStats.timesPlaysByLevel[i])
		{
			this->gameStats.timesPlaysByLevel[i]++;
		}
	}

	writeGameStats();
}

statisticsOfTheGame PlayersStats::getGameStats()
{
	return gameStats;
}

void PlayersStats::drawPlayerStats(int x, int y, Color color)
{
	setForegroundColor(color);

	goToCoordinates(x, y);
	cout << " ____  __      __    _  _  ____  ____    ___  ____    __    ____  ___ " << endl;
	goToCoordinates(x, y + 1);
	cout << "(  _ \\(  )    /__\\  ( \\/ )( ___)(  _ \\  / __)(_  _)  /__\\  (_  _)/ __)" << endl;
	goToCoordinates(x, y + 2);
	cout << " )___/ )(__  /(__)\\  \\  /  )__)  )   /  \\__ \\  )(   /(__)\\   )(  \\__ \\" << endl;
	goToCoordinates(x, y + 3);
	cout << "(__)  (____)(__)(__) (__) (____)(_)\\_)  (___/ (__) (__)(__) (__) (___/" << endl;

	setForegroundColor(Color::WHITE);
}
