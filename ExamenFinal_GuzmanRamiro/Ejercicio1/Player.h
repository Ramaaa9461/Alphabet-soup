#pragma once

#include "Entity.h"

class Player : public Entity
{


private:
	int steps = 0;
	int coints = 0;

	Vector initialPosition;
	Vector previusPosition;
	Vector edgeDistance;

	void move();
	void addOneSteps();
	void playerRenderer();
	void clearPlayer();

public:
	Player(Color color, Vector edgeDistance);
	~Player();
	
	void goToPreviusPosition();
	void setInitialPosition(int x, int y);

	void addCoins(int coin);
	void reduceOneSteps();

	int getSteps();
	int getCoins();

	void restart();

	virtual void draw() override;

	virtual void checkCollisions(Entity* entity) override;

	virtual type getEntityType() override;


};

