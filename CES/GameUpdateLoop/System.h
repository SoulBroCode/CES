#pragma once
#include <vector>
#include <iostream>
#include "Entity.h"

class ControlSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) {
		entities.push_back(e);
	}
	void update() {
		std::cout << "ControlSystem Update..." << std::endl;
		int entitySize = entities.size();
		for (int i = 0; i < entitySize; i++)
		{
			std::vector<Component> components = entities[i].getComponents();
			int componentSize = components.size();
			bool hasPosition = false;
			bool hasControl = false;
			for (int j = 0; j < componentSize; j++)
			{
				for (int j = 0; j < componentSize; j++)
				{
					if (components[j].id == (int)Component_types::POSITION)
					{
						hasPosition = true;
					}
					else if (components[j].id == (int)Component_types::CONTROL)
					{
						hasControl = true;
					}
				}				
			}
			if (hasPosition && hasControl)
			{
				std::cout << entities[i].entitydebug(entities[i].getID()) << " has control and position component" << std::endl;
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
		std::cout << "RenderSystem Update..." << std::endl;
		int entitySize = entities.size();
		for (int i = 0; i < entitySize; i++)
		{
			std::vector<Component> components = entities[i].getComponents();
			int componentSize = components.size();
			for (int j = 0; j < componentSize; j++)
			{
				if (components[j].id == (int)Component_types::POSITION)
				{
					std::cout << "render " << entities[i].entitydebug(entities[i].getID()) << std::endl;
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
		std::cout << "AISystem Update..." << std::endl;
		int entitySize = entities.size();
		
		for (int i = 0; i < entitySize; i++)
		{
			std::vector<Component> components = entities[i].getComponents();
			int componentSize = components.size();		
			bool hasHealth = false;
			bool hasPosition = false;
			for (int j = 0; j < componentSize; j++)
			{
				if (components[j].id == (int)Component_types::HEALTH)
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
				std::cout << entities[i].entitydebug(entities[i].getID()) << " has health and position component" << std::endl;
				//do something health and position
			}
		}
		
	}
};

