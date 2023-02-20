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

void Player::goToPreviusPosition()
{
	boxCollider.position = previusPosition;
}

void Player::setInitialPosition(int x, int y)
{
	initialPosition.x = x + edgeDistance.x;
	initialPosition.y = y + edgeDistance.y;

	restart();
}

void Player::playerRenderer()
{
	setForegroundColor(color);


	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << "0" << endl;

	/*goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << " " << "0" << " " << endl;
	goToCoordinates(boxCollider.position.x, boxCollider.position.y + 1);
	cout << "/" << "|" << "\\" << endl;
	goToCoordinates(boxCollider.position.x, boxCollider.position.y + 2);
	cout << "/" << " " << "\\" << endl;
*/
	setForegroundColor(Color::WHITE);

}

void Player::clearPlayer()
{
	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << (" ") << endl;
	/*goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << ("   ") << endl;
	goToCoordinates(boxCollider.position.x, boxCollider.position.y + 1);
	cout << ("   ") << endl;
	goToCoordinates(boxCollider.position.x, boxCollider.position.y + 2);
	cout << ("   ") << endl;*/

}

#pragma region movement

void Player::move()
{
	playerRenderer();
	previusPosition = boxCollider.position;

	Vector directionMove = { 0, 0 };
	switch (getKey())
	{
	case 'a':
	case 'A':
		if (boxCollider.position.x > 1)
		{
			directionMove = { -1,0 };
			addOneSteps();
		}
		break;

	case 's':
	case'S':

		if (boxCollider.position.y + boxCollider.height < getScreenHeight() - 1)
		{
			directionMove = { 0,1 };
			addOneSteps();
		}
		break;

	case 'd':
	case'D':
		if (boxCollider.position.x + boxCollider.width < getScreenWidth() - 1)
		{
			directionMove = { 1,0 };
			addOneSteps();
		}

		break;
	case 'w':
	case 'W':

		if (boxCollider.position.y > 1)
		{
			directionMove = { 0,-1 };
			addOneSteps();
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
	steps = 0;
	coints = 0;

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
	move();

	playerRenderer();
}

#pragma endregion

#pragma region Adders

void Player::addCoins(int coin)
{
	this->coints += coin;
}

void Player::reduceOneSteps()
{
	steps--;
}

void Player::addOneSteps()
{
	steps++;
}

#pragma endregion 

#pragma region Getters

int Player::getSteps()
{
	return steps;
}

int Player::getCoins()
{
	return coints;
}

#pragma endregion
