#pragma once
#include "ComponentTest.h"
#include <vector>

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
private:
	std::vector<Component> components;
	int id;
};


class Player : public Entity
{
	Player() {
		setID((int)Entity_types::PLAYER);
	}
};

class Alien : public Entity
{
	Alien() {
		setID((int)Entity_types::ALIEN);
	}
};

class Cat : public Entity
{
	Cat() {
		setID((int)Entity_types::CAT);
	}
};

class Dog : public Entity
{
	Dog() {
		setID((int)Entity_types::DOG);
	}

};