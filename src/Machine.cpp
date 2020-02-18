/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "Machine.h"
#include "Game.h"

Machine::Machine()
{
	//Loading all textures
	TheTextureManager::Instance()->load("../Assets/textures/slot.jpg",
		"Machine", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SlotMachine");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
	setType(MACHINE);
}

Machine::~Machine()
{
}

void Machine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;



	TheTextureManager::Instance()->draw("Machine", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}

void Machine::update()
{
}

void Machine::clean()
{
}