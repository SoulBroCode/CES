#pragma once


enum class Component_types
{
	NONE = 0,
	HEALTH = 1 ,
	POSITION = 2 ,
	CONTROL = 3 ,
} ;


struct Component
{
	int id;
} ;


class HealthComponent : public Component
{
public:
	HealthComponent() : health(100){ 
		id = (int)Component_types::HEALTH;
	};
	/* Data Only */
	int getHealth() { return health; }
	void setHealth(int health) { this->health = health; }
private:
	int health;
};

class PositionComponent : public Component
{
public:
	PositionComponent() : x(0),y(0) {
		id = (int)Component_types::POSITION;
	};
	/* Data Only */
	int getX() { return x; }
	void setX(float x) { this->x = x; }
	int getY() { return y; }
	void setY(float y) { this->y = y; }
private:
	float x;
	float y;
};

class ControlComponent : public Component
{
public:
	ControlComponent() : key(0) {
		id = (int)Component_types::CONTROL;
	};
	/* Data Only */
	int getKey() { return key; }
	void setKey(float key) { this->key = key; }

private:
	int key; //to be change into actual key, not int
};

