#pragma once
#include "EntityTest.h"
#include <vector>
#include <iostream>

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { /* TBI */ }
	void update() {
		std::cout << "HealthSystem Update" << std::endl;
		/* Loop through Entities with */
		/* HealthComponents and Update */
		/* TBI */
	}
};
