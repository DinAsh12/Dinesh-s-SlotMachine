/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Machine.h"
#include "SpinButton.h"
#include "QuitButton.h"
#include "ResetButton.h"
#include "PlusButton.h"
#include "MinusButton.h"
#include "BetButton.h"
#include "LeftSpin.h"
#include "MiddleSpin.h"
#include "MachineReel.h"
#include "ReelImages.h"
#include "Label.h"
#include "RightLabel.h"

class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	void spin();
	void decreaseMoney(int theBet);

	//setters
	void setBalance(int money);
	void increaseBet();
	void decreaseBet();
	void setBet(int bet);
	
	// getters
	glm::vec2 getMousePosition();
	int getBalance();
	int getBet();

	void initializeLabels();
	void changeLeftReelImage(int reelImage);
	void changeMiddleReelImage(int reelImage);
	void changeRightReelImage(int reelImage);
	void checkWinCondition();
	void checkJackPotCondition();
	int slotCombo(int slotValues[3]);

private:
	void m_checkWins();
	int m_checkLine(int line[3]);
	int m_money;
	int m_jackpot;
	int m_wins;
	int m_betAmount;
	std::string m_moneyString;
	std::string m_betAmountString;
	std::string m_winsString;
	std::string m_jackpotString;
	//Starting images for the slots
	std::string m_LeftSpinImageString = "LeftSpinDiamond";
	std::string m_MiddleSpinImageString = "MiddleSpinDiamond";
	std::string m_RightSpinImageString = "RightSpinDiamond";


	Label* m_pSlotLabel;
	Label* m_pMoneyLabel;
	Label* m_pBetLabel;
	Label* m_pWinLabel;
	
	// game objects
	Machine* m_pMachine;
	SpinButton* m_pSpinButton;
	ResetButton* m_pResetButton;
	PlusButton* m_pPlusButton;
	MinusButton* m_pMinusButton;
	QuitButton* m_pQuitButton;
	BetButton* m_pBetButton;
	// private data member
	glm::vec2 m_mousePosition;

	LeftSpin* m_pLeftSpin;
	MiddleSpin* m_pMiddleSpin;
	RightSpin* m_pRightSpin;
	MachineReel* m_pMachineReelSlot[3];
	
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
