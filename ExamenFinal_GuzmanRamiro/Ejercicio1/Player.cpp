#include "Player.h"



Player::Player(Color color, Vector edgeDistance) : Entity(color)
{
	entityType = player;

	boxCollider.width = 1;
	boxCollider.height = 1;
	this->edgeDistance = edgeDistance;
}

Player::~Player()
{
}

void Player::setInitialPosition(int x, int y)
{
	initialPosition.x = x;
	initialPosition.y = y;

	restart();
}


void Player::playerRenderer()
{
	setForegroundColor(color);

	goToCoordinates(boxCollider.position.x + edgeDistance.x, boxCollider.position.y + edgeDistance.y);

	cout << ("O") << endl;

	setForegroundColor(Color::WHITE);

}


void Player::clearPlayer()
{
	goToCoordinates(boxCollider.position.x + edgeDistance.x, boxCollider.position.y + edgeDistance.y);

	cout << (" ") << endl;
}

#pragma region movement

void Player::move()
{
	playerRenderer();

	Vector directionMove = { 0, 0 };
	switch (getKey())
	{
	case 'a':
	case 'A':
		if (boxCollider.position.x > 1) 
		{
			directionMove = { -1,0 };
			reduceSteps();
		}
		break;

	case 's':
	case'S':

		if (boxCollider.position.y + boxCollider.height < getScreenHeight() - 1)
		{
			directionMove = { 0,1 };
			reduceSteps();
		}
		break;

	case 'd':
	case'D':
		if (boxCollider.position.x + boxCollider.width < getScreenWidth() - 1)
		{
			directionMove = { 1,0 };
			reduceSteps();
		}

		break;
	case 'w':
	case 'W':

		if (boxCollider.position.y > 1)
		{
			directionMove = { 0,-1 };
			reduceSteps();
		}
		break;
	}

	clearPlayer();

	boxCollider.position.x += directionMove.x;
	boxCollider.position.y += directionMove.y;

	directionMove = { 0,0 };

}

void Player::restart()
{
	boxCollider.position.x = initialPosition.x;
	boxCollider.position.y = initialPosition.y;

	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
}

#pragma endregion

#pragma region pureVirtualMethods

type Player::getEntityType()
{
	return entityType;
}
void Player::checkCollisions(Entity* entity)
{

}
void Player::draw()
{
	if (steps > 0)
	{
		move();
	}

	playerRenderer();

}

#pragma endregion

#pragma region Adders

void Player::addCoins(int coin)
{
	this->coints += coin;
}
void Player::addSteps(int steps)
{
	this->steps += steps;

	if (this->steps > maxSteps)
	{
		this->steps = maxSteps;
	}
}
void Player::addCurrentCollectibles()
{
	currentCollectibles++;
	
	if (this->currentCollectibles > maxCollectibles)
	{
		this->currentCollectibles = maxCollectibles;
	}
}

void Player::reduceSteps()
{
	steps--;
}

#pragma endregion 

#pragma region Getters

int Player::getSteps()
{
	return steps;
}
int Player::getMaxSteps()
{
	return maxSteps;
}
int Player::getCoins()
{
	return coints;
}
int Player::getCurrentCollectibles()
{
	return currentCollectibles;
}

int Player::getMaxCollectibles()
{
	return maxCollectibles;
}

#pragma endregion