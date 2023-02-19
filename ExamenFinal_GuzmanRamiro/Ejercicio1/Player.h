#pragma once

#include "Entity.h"

class Player : public Entity
{


private:
	const int maxSteps = 250;
	int steps = maxSteps;
	int coints = 0;
	int maxCollectibles = 20;
	int currentCollectibles = 0;

	Vector initialPosition;
	Vector edgeDistance;

	void move();
	void reduceSteps();
	void playerRenderer();
	void clearPlayer();

public:
	Player(Color color, Vector edgeDistance);
	~Player();
	
	void setInitialPosition(int x, int y);

	void addCoins(int coin);
	void addSteps(int steps);
	void addCurrentCollectibles();

	int getSteps();
	int getMaxSteps();
	int getCoins();
	int getCurrentCollectibles();
	int getMaxCollectibles();

	void restart();

	virtual void draw() override;

	virtual void checkCollisions(Entity* entity) override;

	virtual type getEntityType() override;


};

