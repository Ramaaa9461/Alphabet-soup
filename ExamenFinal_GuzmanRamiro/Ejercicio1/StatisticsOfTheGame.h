#pragma once

#include <string>
#include <vector>

struct statisticsOfTheGame
{
	std::string playerName = "There is no information";
	int maximumAmountOfSteps = 10000;
	static const int levelCount = 3;
	int timesPlaysByLevel[levelCount];
};