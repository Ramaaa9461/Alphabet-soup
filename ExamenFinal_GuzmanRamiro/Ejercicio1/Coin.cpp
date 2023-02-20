#include "Coin.h"

#include "player.h"

void Coin::coinRenderer()
{
	setForegroundColor(color);

	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << (char)207 << endl;

	setForegroundColor(Color::WHITE);
}

void Coin::coinClear()
{
	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << " " << endl;
}

Coin::Coin(Color color, Vector position) : Entity(color)
{
	entityType = coins;

	boxCollider.height = 1;
	boxCollider.width = 1;

	boxCollider.position = position;
}

Coin::~Coin()
{
}

void Coin::changeIsAlive(bool alive)
{
	isAlive = alive;
}

type Coin::getEntityType()
{
	return entityType;
}

void Coin::checkCollisions(Entity* entity)
{
	if (isAlive)
	{
		if (isColliding(entity->getBoxCollider()))
		{
			if (entity->getEntityType() == player)
			{
				((Player*)entity)->addCoins(1);

				isAlive = false;
				coinClear();
			}
		}
	}

}

void Coin::draw()
{
	if (isAlive)
	{
		coinRenderer();
	}
}
