/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "LeftLabel.h"
#include "Game.h"

LeftSpin::LeftSpin()
{
	//Loading all textures
	TheTextureManager::Instance()->load("../Assets/textures/carrot.png",
		"LeftCarrot", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/jackpot.png",
		"LeftJackpot", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/seven.png",
		"LeftSeven", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/bar.png",
		"LeftBar", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/banana.png",
		"LeftBanana", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/cherry.png",
		"LeftCherry", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/orange.png",
		"LeftOrange", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/peer.png",
		"LeftPeer", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/strawberry.png",
		"LeftStrawberry", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("LeftSpinCarrot");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(296, 455));
	setType(LEFT_LABEL);
}

LeftSpin::~LeftSpin()
{
}

void LeftSpin::draw()
{

}

void LeftSpin::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;


	TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void LeftSpin::update()
{
}

void LeftSpin::clean()
{
}