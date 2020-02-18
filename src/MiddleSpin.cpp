/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "MiddleSpin.h"

#include <utility>
#include "Game.h"

MiddleSpin::MiddleSpin()
{
	//Loading all textures
	TheTextureManager::Instance()->load("../Assets/textures/carrot.png",
		"MiddleCarrot", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/jackpot.png",
		"MiddleJackpot", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/seven.png",
		"MiddleSeven", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/bar.png",
		"MiddleBar", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/banana.png",
		"MiddleBanana", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/cherry.png",
		"MiddleCherry", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/orange.png",
		"MiddleOrange", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/peer.png",
		"MiddlePeer", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/strawberry.png",
		"MiddleStrawberry", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("MiddleSpinCarrot");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(473, 455));
	setType(MIDDLE_LABEL);
}

MiddleSpin::~MiddleSpin()
{
}

void MiddleSpin::draw()
{

}

void MiddleSpin::draw(std::string imageID)
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;


	TheTextureManager::Instance()->draw(std::move(imageID), xComponent, yComponent,
	                                    TheGame::Instance()->getRenderer(), 0, 255, true);
}

void MiddleSpin::update()
{
}

void MiddleSpin::clean()
{
}