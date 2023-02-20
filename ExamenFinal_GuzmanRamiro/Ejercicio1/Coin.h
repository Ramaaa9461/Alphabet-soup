#pragma once

#include "Entity.h"

class Coin : public Entity
{
private:

	void coinRenderer();
	void coinClear();
	bool isAlive = true;

public:
	Coin(Color color, Vector position);
	~Coin();

	void changeIsAlive(bool alive);

	virtual type getEntityType() override;
	virtual void checkCollisions(Entity* entity) override;
	virtual void draw() override;

};

