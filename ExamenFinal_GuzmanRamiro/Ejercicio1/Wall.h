#pragma once

#include "Entity.h"

class Wall : public Entity
{
private:

	void wallRenderer();
	void wallClear();

public:
	Wall(Color color, Vector position);
	~Wall();

	virtual type getEntityType() override;
	virtual void checkCollisions(Entity* entity) override;
	virtual void draw() override;
};

