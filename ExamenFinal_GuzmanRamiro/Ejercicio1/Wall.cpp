#include "Wall.h"

#include "player.h"

void Wall::wallRenderer()
{
	setForegroundColor(color);

	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << (char)219 << endl;

	setForegroundColor(Color::WHITE);
}

void Wall::wallClear()
{
	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
	cout << " " << endl;
}

Wall::Wall(Color color, Vector position) : Entity(color)
{
	entityType = wall;

	boxCollider.height = 1;
	boxCollider.width = 1;

	boxCollider.position = position;
}

Wall::~Wall()
{
}

type Wall::getEntityType()
{
	return entityType;
}

void Wall::checkCollisions(Entity* entity)
{
	if (isColliding(entity->getBoxCollider()))
	{
		if (entity->getEntityType() == player)
		{
			((Player*)entity)->goToPreviusPosition();
			((Player*)entity)->reduceOneSteps();
		}
	}
}

void Wall::draw()
{
	wallRenderer();
}

