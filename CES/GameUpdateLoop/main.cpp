#include <iostream>
#include <Windows.h>
#include "GameTime.h"
#include "Component.h"
#include "System.h"
using namespace std;

const float TRIGGER = 1.2f;

int main(void)
{
	HealthComponent hc; PositionComponent pc; ControlComponent cc;

	Entity player;
	player.setID((int)Entity_types::PLAYER);
	player.addComponent(hc); 
	player.addComponent(pc);
	player.addComponent(cc);

	Entity alien;
	alien.setID((int)Entity_types::ALIEN);
	alien.addComponent(hc);
	alien.addComponent(pc);

	Entity cat;
	cat.setID((int)Entity_types::CAT);
	cat.addComponent(hc);
	cat.addComponent(pc);

	Entity dog;
	dog.setID((int)Entity_types::DOG);
	dog.addComponent(hc);
	dog.addComponent(pc);
	dog.addComponent(cc);

	dog.removeComponent(cc);

	ControlSystem cs; 
	cs.addEntity(player);
	cs.addEntity(alien);
	cs.addEntity(cat);
	cs.addEntity(dog);

	RenderSystem rs;
	rs.addEntity(player);
	rs.addEntity(alien);
	rs.addEntity(cat);
	rs.addEntity(dog);

	AISystem as;
	as.addEntity(player);
	as.addEntity(alien);
	as.addEntity(cat);
	as.addEntity(dog);

	//gametime loop
	float last = 0.0f;
	float current = 0.0f;
	GameTime* gameTime = GameTime::getInstance();
	last = gameTime->running();
	//Main Game Loop
	while(true)
	{
		current = gameTime->running();
		if((current - last) > TRIGGER)
		{
			std::cout << "updating...." << std::endl;
			cs.update();
			rs.update();
			as.update();
			last = current;
		}
		Sleep(1000);//main process sleeps
	}
	system("PAUSE");
}