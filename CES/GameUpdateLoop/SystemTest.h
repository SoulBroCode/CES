#pragma once
#include <vector>
#include <iostream>
#include "EntityTest.h"

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) {
		entities.push_back(e);
	}
	void update() {
		std::cout << "HealthSystem Update" << std::endl;
		int entitySize = entities.size();
		for (int i = 0; i < entitySize; i++)
		{
			std::vector<Component> components = entities[i].getComponents();
			int componentSize = components.size();
			for (int j = 0; j < componentSize; j++)
			{
				bool hasHealth = false;
				bool hasControl = false;
				for (int j = 0; j < componentSize; j++)
				{
					if (components[j].id == (int)Component_types::POSITION)
					{
						hasHealth = true;
					}
					else if (components[j].id == (int)Component_types::CONTROL)
					{
						hasControl = true;
					}
				}
				if (hasHealth && hasControl)
				{
					//do something health and position
				}
			}
		}
	}
};

class RenderSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) {
		entities.push_back(e);
	}
	void update() {
		std::cout << "RenderSystem Update" << std::endl;
		int entitySize = entities.size();
		for (int i = 0; i < entitySize; i++)
		{
			std::vector<Component> components = entities[i].getComponents();
			int componentSize = components.size();
			for (int j = 0; j < componentSize; j++)
			{
				if (components[j].id == (int)Component_types::POSITION)
				{
					//render at position
				}
			}
		}
	}
};

class AISystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) {
		entities.push_back(e);
	}
	void update() {
		std::cout << "AISystem Update" << std::endl;
		int entitySize = entities.size();
		for (int i = 0; i < entitySize; i++)
		{
			std::vector<Component> components = entities[i].getComponents();
			int componentSize = components.size();
			bool hasHealth = false;
			bool hasPosition = false;
			for (int j = 0; j < componentSize; j++)
			{
				if (components[j].id == (int)Component_types::POSITION)
				{
					hasHealth = true;
				}
				else if (components[j].id == (int)Component_types::POSITION)
				{
					hasPosition = true;
				}
			}
			if (hasHealth && hasPosition)
			{
				//do something health and position
			}
		}
	}
};

