/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "RightLabel.h"
#include "Game.h"

RightSpin::RightSpin()
{
	//Loading all textures
	TheTextureManager::Instance()->load("../Assets/textures/carrot.png",
		"RightCarrot", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/jackpot.png",
		"RightJackpot", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/seven.png",
		"RightSeven", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/bar.png",
		"RightBar", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/banana.png",
		"RightBanana", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/cherry.png",
		"RightCherry", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/orange.png",
		"RightOrange", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/peer.png",
		"RightPeer", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/strawberry.png",
		"RightStrawberry", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("RightSpinCarrot");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(655, 455));
	setType(RIGHT_LABEL);
}

RightSpin::~RightSpin()
{
}

void RightSpin::draw()
{

}

void RightSpin::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;


	TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void RightSpin::update()
{
}

void RightSpin::clean()
{
}