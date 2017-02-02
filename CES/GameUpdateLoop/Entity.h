#pragma once
#include "Component.h"
#include <vector>
#include <string>

enum class Entity_types
{
	NONE = 0,
	PLAYER = 1,
	ALIEN = 2,
	CAT = 3,
	DOG = 4
};

class Entity
{
public:
	
	Entity() {};
	void addComponent(Component c) { 
		components.push_back(c); 
	}
	void removeComponent(Component c) {
		for (std::vector<Component>::iterator it = components.begin(); it < components.end();)
		{
			if ((*it).id == c.id)
			{
				std::cout << entitydebug(id) << " remove " << componentdebug(c.id) << std::endl;
				it = components.erase(it);		
			}
			else
			{
				it++;
			}
		}
	}
	std::vector<Component> getComponents() { return components; }
	int getID() { return id; }
	void setID(int id) { this->id = id; }


	//for debugging only
	std::string entitydebug(int id)
	{
		std::string type = "";
		switch (id)
		{
		case (int)Entity_types::PLAYER:
			type = "entity player";
			break;
		case (int)Entity_types::ALIEN:
			type = "entity alien";
			break;
		case (int)Entity_types::DOG:
			type = "entity dog";
			break;
		case (int)Entity_types::CAT:
			type = "entity cat";
			break;
		default:
			break;
		}
		return type;
	}
	//for debugging only
	std::string componentdebug(int id)
	{
		std::string type = "";
		switch (id)
		{
		case (int)Component_types::HEALTH:
			type = "health component";
			break;
		case (int)Component_types::POSITION:
			type = "position component";
			break;
		case (int)Component_types::CONTROL:
			type = "control component";
			break;
		default:
			break;
		}
		return type;
	}


private:
	std::vector<Component> components;
	int id;

	
};

