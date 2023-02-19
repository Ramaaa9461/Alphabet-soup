#include "Entity.h"


Entity::Entity(Color color)
{
	this->color = color;

	entityType = none;
}

Entity::~Entity()
{

}

void Entity::setPosition(int x, int y)
{
	boxCollider.position.x = x;
	boxCollider.position.y = y;

	goToCoordinates(boxCollider.position.x, boxCollider.position.y);
}

BoxCollider Entity::getBoxCollider()
{
	return boxCollider;
}

Color Entity::getColor()
{
	return Color();
}

bool Entity::isWithinLimits()
{
	return boxCollider.position.y > 0 && boxCollider.position.y + boxCollider.height < getScreenHeight() - 4
		&& boxCollider.position.x > 0 && boxCollider.position.x + boxCollider.width < getScreenWidth();
}

bool Entity::isColliding(BoxCollider other)
{

	return boxCollider.position.x + boxCollider.width > other.position.x &&
		other.position.x + other.width > boxCollider.position.x &&
		boxCollider.position.y + boxCollider.height > other.position.y &&
		other.position.y + other.height > boxCollider.position.y;
}
