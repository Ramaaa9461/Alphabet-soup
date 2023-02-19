#pragma once

#include "Awesome Library/AwesomeLibrary.h"
#include "Vector.h"

struct BoxCollider
{
	Vector position;
	int width;
	int height;
};

enum type { none, player, coins, wall };

class Entity
{

protected:

	type entityType;
	Color color;
	BoxCollider boxCollider;

	bool isWithinLimits();
	bool isColliding(BoxCollider boxCollider);

public:

	Entity(Color color);
	virtual ~Entity();

	void setPosition(int x, int y);

	BoxCollider getBoxCollider();
	Color getColor();

	virtual type getEntityType() = 0;
	virtual void checkCollisions(Entity* entity) = 0;
	virtual void draw() = 0;
};

