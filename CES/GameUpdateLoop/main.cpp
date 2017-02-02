#include <iostream>
#include <Windows.h>
#include "GameTime.h"
#include "ComponentTest.h"
#include  "SystemTest.h"
using namespace std;

const float TRIGGER = 0.2f;

int main(void)
{
	HealthComponent hc; PositionComponent pc; ControlComponent cc;

	Entity player;
	player.addComponent(hc); 
	player.addComponent(pc);
	player.addComponent(cc);

	Entity alien;
	alien.addComponent(hc);
	alien.addComponent(pc);

	Entity cat;
	cat.addComponent(hc);
	cat.addComponent(pc);

	Entity dog;
	dog.addComponent(hc);
	dog.addComponent(pc);

	ControlSystem hs; 
	hs.addEntity(player);
	hs.addEntity(alien);
	hs.addEntity(cat);
	hs.addEntity(dog);

	C

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
			hs.update();
			last = current;
		}
		Sleep(500);//main process sleeps
	}
	system("PAUSE");
}