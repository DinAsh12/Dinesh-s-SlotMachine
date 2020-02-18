/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/


#include "Level1Scene.h"
#include "Game.h"
#include "EndScene.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include<sstream>
#include <string>
#include <iostream>
using namespace std;



Level1Scene::Level1Scene()
{
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	//drawing background and buttons
	m_pMachine->draw();
	m_pSpinner->draw();
	m_pResetter->draw();
	m_pBetAmountPlus->draw();
	m_pBetAmountMinus->draw();
	m_pQuitButton->draw();
	m_pBettingButton->draw();
	//adding labels and spin images reels
	m_pMoneyLabel->draw();
	m_pBetLabel->draw();
	m_pWinLabel->draw();
	m_pLeftLabel->draw(m_LeftSpinImageString);
	m_pMiddleLabel->draw(m_MiddleSpinImageString);
	m_pRightLabel->draw(m_RightSpinImageString);
}

void Level1Scene::update()
{
	//Mouse click events
	m_pSpinner->setMousePosition(m_mousePosition);
	m_pSpinner->ButtonClick();
	m_pResetter->setMousePosition(m_mousePosition);
	m_pResetter->ButtonClick();
	m_pBetAmountPlus->setMousePosition(m_mousePosition);
	m_pBetAmountPlus->ButtonClick();
	m_pBetAmountMinus->setMousePosition(m_mousePosition);
	m_pBetAmountMinus->ButtonClick();
	m_pQuitButton->setMousePosition(m_mousePosition);
	m_pQuitButton->ButtonClick();
	m_pBettingButton->setMousePosition(m_mousePosition);
	m_pBettingButton->ButtonClick();
	//Bet increases if plus button is clicked
	if (m_pBetAmountPlus->ButtonClick())
	{
		increaseAmount();
	}
	//Bet decreased if minus button is clicked
	if (m_pBetAmountMinus->ButtonClick())
	{	
		decreaseAmount();
	}
	//Spinning started when spin button is clicked
	if (m_pSpinner->ButtonClick())
	{
		spin();
	}
	//Reset the game on clicking reset button
	if (m_pResetter->ButtonClick())
	{
		setAmount(0);
		m_pBetLabel->setText("Bet: " + m_betAmountString);
		setBalance(1000);
		m_pMoneyLabel->setText("Balance: " + m_moneyString);
		m_pWinLabel->setText("You win: ");
		m_LeftSpinImageString = "LeftJackpot";
		m_MiddleSpinImageString = "MiddleJackpot";
		m_RightSpinImageString = "RightJackpot";
	}
	//quit the game on clicking quit button
	if (m_pQuitButton->ButtonClick())
	{
		TheGame::Instance()->quit();
	}
}


void Level1Scene::clean()
{

	delete m_pBettingButton;
	delete m_pSpinner;
	delete m_pMachineReelSlots[0];
	delete m_pMachineReelSlots[1];
	delete m_pMachineReelSlots[2];

	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				//setting mouse button clicks to true if button clicked.
				m_pSpinner->setClickEvents(true);
				m_pResetter->setClickEvents(true);
				m_pBetAmountPlus->setClickEvents(true);
				m_pBetAmountMinus->setClickEvents(true);
				m_pQuitButton->setClickEvents(true);
				m_pBettingButton->setClickEvents(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				TheSoundManager::Instance()->load("../Assets/audio/yay.ogg", "yay", SOUND_SFX);
				m_pSpinner->setClickEvents(false);
				m_pResetter->setClickEvents(false);
				m_pBetAmountPlus->setClickEvents(false);
				m_pBetAmountMinus->setClickEvents(false);
				m_pQuitButton->setClickEvents(false);
				m_pBettingButton->setClickEvents(false);

				m_pSpinner->setClickOnce(0);
				m_pResetter->setClickOnce(0);
				m_pBetAmountPlus->setClickOnce(0);
				m_pBetAmountMinus->setClickOnce(0);
				m_pQuitButton->setClickOnce(0);
				m_pBettingButton->setClickOnce(0);

				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			}
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	//Sets initial balance
	setBalance(1000);
	//Sets initial Bet
	setAmount(0);
	//Gets Balance and bet and assigns to an integer
	m_money = getBalance();
	m_betAmount = getBet();
	//jackpot bonus
	m_jackpot = 1000;
	//assigning memory to machineReelSlots
	m_pMachineReelSlots[0] = new MachineReel();
	m_pMachineReelSlots[1] = new MachineReel();
	m_pMachineReelSlots[2] = new MachineReel();

	initializeLabels();
	//Adding game objects on scene
	m_pMachine = new Machine(); // instantiates Plane
	addChild(m_pMachine);
	
	m_pSpinner = new SpinButton();
	m_pSpinner->setClickEvents(false);
	addChild(m_pSpinner);
	
	m_pResetter = new ResetButton();
	m_pResetter->setClickEvents(false);
	addChild(m_pResetter);
	
	m_pBetAmountPlus = new PlusButton();
	m_pBetAmountPlus->setClickEvents(false);
	addChild(m_pBetAmountPlus);
	
	m_pBetAmountMinus = new MinusButton();
	m_pBetAmountMinus->setClickEvents(false);
	addChild(m_pBetAmountMinus);
	
	m_pQuitButton = new QuitButton();
	m_pQuitButton->setClickEvents(false);
	addChild(m_pQuitButton);
	
	m_pBettingButton = new BetButton();
	m_pBettingButton->setClickEvents(false);
	addChild(m_pBettingButton);
	
	m_pLeftLabel = new LeftSpin();
	addChild(m_pLeftLabel);
	m_pMiddleLabel = new MiddleSpin();
	addChild(m_pMiddleLabel);
	m_pRightLabel = new RightSpin();
	addChild(m_pRightLabel);
}
void Level1Scene::spin()
{
	//Checks if the button is clicked or not
	if (m_pSpinner->countClickOnce() == 0)
	{
		//checks balance
		if (getBalance() < getBet())
		{
			m_pWinLabel->setText("No Money to Spin");
			
			m_pSpinner->setClickEvents(false);
		}
		//If the bet is 0, raise bet error
		else if(getBet() == 0)
		{
			m_pWinLabel->setText("Add Some bet!!");
		}
		//
		else {

			//decrease money according the bet
			decreaseMoney(m_betAmount);


			//spin the slots and select random image
			m_pMachineReelSlots[0]->spin();
			m_pMachineReelSlots[1]->spin();
			m_pMachineReelSlots[2]->spin();
			
			int LeftSpin = m_pMachineReelSlots[0]->getSlotNumber();
			int MiddleSpin = m_pMachineReelSlots[1]->getSlotNumber();
			int RightSpin = m_pMachineReelSlots[2]->getSlotNumber();

			

			changeLeftReel(LeftSpin);
			changeMiddleReel(MiddleSpin);
			changeRightReel(RightSpin);

			//check winning conition
			isWinTrue();
			
			//show the win
			std::stringstream winStream;
			winStream << m_wins;
			winStream >> m_winsString;
			// If The player loses money he gets "You Lost: " Message otherwise "You won".
			if(m_wins ==0)
			{
				m_pWinLabel->setText("You Lost: " + m_betAmountString);
			}
			else
			{
				m_pWinLabel->setText("You Win: " + m_winsString);
			}
			
			//check if user won jackpot
			isJackpotTrue();
		}

	}
	//set click count after all spinning functions are done
	m_pSpinner->setClickOnce(1);

}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}
void Level1Scene::decreaseMoney(int theBet)
{
	//Check if no clicks has done before and decrease the bet amount from your money only once
	if (m_pSpinner->countClickOnce() == 0) {

		m_money -= m_betAmount;
		stringstream moneyStream;
		//sets integer as a string to be printed out
		moneyStream << m_money;
		moneyStream >> m_moneyString;
		//prints balance
		m_pMoneyLabel->setText("Balance: " + m_moneyString);
		


	}
}


//sets the balance initially
void Level1Scene::setBalance(int money)
{
	m_money = money;
	//sets integer as a string to be printed out
	stringstream moneyStream;
	moneyStream << m_money;
	moneyStream >> m_moneyString;
}

// Decreases the bet when someone click minus button
void Level1Scene::decreaseAmount()
{
	//Check if no clicks has done before and decrease your bet only once per click
	if (m_pBettingButton->countsClickOnce() == 0) {
		m_betAmount -= 10;
		m_pBettingButton->setClickOnce(1);
		cout << m_betAmount << endl;
		if(m_betAmount < 0)
		{
			m_pWinLabel->setText("Negative bets not accepted.");
			setAmount(0);
		}
		//sets integer as a string to be printed out
		stringstream betStream;
		betStream << m_betAmount;
		betStream >> m_betAmountString;
		m_pBetLabel->setText("" + m_betAmountString);
	}
}

void Level1Scene::increaseAmount()
{
	//Check if no clicks has done before and increase your bet only once per click
	if (m_pBettingButton->countsClickOnce() == 0) {
		m_betAmount += 10;
		m_pBettingButton->setClickOnce(1);
		cout << m_betAmount << endl;
		//sets integer as a string to be printed out
		stringstream betStream;
		betStream << m_betAmount;
		betStream >> m_betAmountString;
		m_pBetLabel->setText("" + m_betAmountString);
	}
}
void Level1Scene::setAmount(int bet)
{

	m_betAmount = bet;
	//sets integer as a string to be printed out
	stringstream betStream;
	betStream << m_betAmount;
	betStream >> m_betAmountString;
}
//Gets the balance whatever is left
int Level1Scene::getBalance()
{
	return m_money;
}

//Gets the bet amount
int Level1Scene::getBet()
{
	return m_betAmount;
}
//Initializes labels
void Level1Scene::initializeLabels()
{
	//Various colour RGBA
	SDL_Color green = { 0, 255, 50, 255 };
	SDL_Color white = { 255, 255, 255, 0.3 };
	SDL_Color red = { 255, 00, 00, 255 };

	
	//Adding labels
	m_pMoneyLabel = new Label("Your Amount: " + m_moneyString, "Dock51", 30, white, glm::vec2(235.0f, 625.0f));
	m_pMoneyLabel->setParent(this);
	addChild(m_pMoneyLabel);

	m_pBetLabel = new Label("" + m_betAmountString, "Dock51", 40, white, glm::vec2(486.0f, 734.0f));
	m_pBetLabel->setParent(this);
	addChild(m_pBetLabel);

	m_pWinLabel = new Label("You win: " + m_winsString, "Dock51", 30, red, glm::vec2(645.0f, 625.0f));
	m_pWinLabel->setParent(this);
	addChild(m_pWinLabel);


}
//Left Reel Image according to numbers
void Level1Scene::changeLeftReel(int reelImage)
{
	switch (reelImage)
	{
	case carrot:
		m_LeftSpinImageString = "LeftCarrot";
		break;
	case seven:
		m_LeftSpinImageString = "LeftSeven";
		break;
	case bar:
		m_LeftSpinImageString = "LeftBar";
		break;
	case banana:
		m_LeftSpinImageString = "LeftBanana";
		break;
	case cherry:
		m_LeftSpinImageString = "LeftCherry";
		break;
	case orange:
		m_LeftSpinImageString = "LeftOrange";
		break;
	case peer:
		m_LeftSpinImageString = "LeftPeer";
		break;
	case jackpot:
		m_LeftSpinImageString = "LeftJackpot";
		break;
	case strawberry:
		m_LeftSpinImageString = "LeftStrawberry";
		break;
	default:
		break;
	}
}

//Middle Reel Image according to numbers
void Level1Scene::changeMiddleReel(int reelImage)
{
	switch (reelImage)
	{
	case carrot:
		m_MiddleSpinImageString = "MiddleCarrot";

		break;
	case seven:
		m_MiddleSpinImageString = "MiddleSeven";
		break;
	case bar:
		m_MiddleSpinImageString = "MiddleBar";
		break;
	case banana:
		m_MiddleSpinImageString = "MiddleBanana";
		break;
	case cherry:
		m_MiddleSpinImageString = "MiddleCherry";
		break;
	case orange:
		m_MiddleSpinImageString = "MiddleOrange";
		break;
	case peer:
		m_MiddleSpinImageString = "MiddleSpinPeer";
		break;
	case jackpot:
		m_MiddleSpinImageString = "MiddleJackpot";
		break;
	case strawberry:
		m_MiddleSpinImageString = "MiddleStrawberry";
		break;
	default:
		break;
	}
}

//Right Reel Image according to numbers
void Level1Scene::changeRightReel(int reelImage)
{
	switch (reelImage)
	{
	case carrot:
		m_RightSpinImageString = "RightCarrot";

		break;
	case seven:
		m_RightSpinImageString = "RightSeven";
		break;
	case bar:
		m_RightSpinImageString = "RightBar";
		break;
	case banana:
		m_RightSpinImageString = "RightBanana";
		break;
	case cherry:
		m_RightSpinImageString = "RightCherry";
		break;
	case orange:
		m_RightSpinImageString = "RightOrange";
		break;
	case peer:
		m_RightSpinImageString = "RightPeer";
		break;
	case jackpot:
		m_RightSpinImageString = "RightJackpot";
		break;
	case strawberry:
		m_RightSpinImageString = "RightStrawberry";
		break;
	default:
		break;
	}

}

//Winning condition
void Level1Scene::isWinTrue()
{
	int slotValue[3];
	//set wins to 0
	m_wins = 0;
	//get image combination from slots
	for (int i = 0; i < 3; i++)
	{
		slotValue[i] = m_pMachineReelSlots[i]->getSlotNumber();
	}
	//check your combination and save your wins
	m_wins += slotCombo(slotValue);
	//increase your money with wins
	m_money += m_wins;

	
}

void Level1Scene::isJackpotTrue()
{
	//generate jackpot number and player number, compare them, if match inform and raise money by jackpot
	int jackpotnumber = 0 + rand() % 501;
	int playerNumber = 0 + rand() % 501;
	//std::cout << jackpotnumber << " - " << playerNumber << std::endl;
	if (jackpotnumber == playerNumber)
	{
		m_money += m_jackpot;
		stringstream jackpotStream;
		jackpotStream << m_jackpot;
		jackpotStream >> m_jackpotString;
		m_pWinLabel->setText("You win JACKPOT!! " + m_winsString + " + Jackpot: " + m_jackpotString);
	}

}

int Level1Scene::slotCombo(int slotValues[3])

{
	//check 

	//Checks all the conditions and returns the bet winning amount as integer
	if (slotValues[0] == jackpot && slotValues[1] == jackpot && slotValues[2] == jackpot)
	{
		return getBet() * 10;
	}
	if (slotValues[0] == orange && slotValues[1] == orange && slotValues[2] == orange)
	{
		return getBet() * 8;
	}
	if (slotValues[0] == seven && slotValues[1] == seven && slotValues[2] == seven)
	{
		return getBet() * 7;
	}
	if (slotValues[0] == carrot && slotValues[1] == carrot && slotValues[2] == carrot)
	{
		return getBet() * 7;
	}
	if ((slotValues[0] == jackpot && slotValues[1] == jackpot)|| (slotValues[1] == jackpot && slotValues[2] == jackpot)|| (slotValues[0] == jackpot && slotValues[2] == jackpot))
	{
		return getBet() * 6;
	}
	if (slotValues[0] == cherry && slotValues[1] == cherry && slotValues[2] == cherry)
	{
		return getBet() * 5;
	}
	if (slotValues[0] == strawberry && slotValues[1] == strawberry && slotValues[2] == strawberry)
	{
		return getBet() * 4;
	}
	if (slotValues[0] == bar && slotValues[1] == bar && slotValues[2] == bar)
	{
		return getBet() * 2;
	}
	if (slotValues[0] == peer && slotValues[1] == peer && slotValues[2] == peer)
	{
		return getBet() * 2;
	}
	if (slotValues[0] == banana && slotValues[1] == banana && slotValues[2] == banana)
	{
		return getBet() * 2;
	}
	if ((slotValues[0] == banana && slotValues[1] == banana) || (slotValues[1] == banana && slotValues[2] == banana) || (slotValues[0] == banana && slotValues[2] == banana))
	{
		return getBet() * 1;
	}
	
	if ((slotValues[0] == cherry && slotValues[2] == cherry)||(slotValues[0] == cherry && slotValues[1] == cherry)|| (slotValues[1] == cherry && slotValues[2] == cherry))
	{
		return getBet() * 1;
	}
	if ((slotValues[0] == bar && slotValues[2] == bar) || (slotValues[0] == bar && slotValues[1] == bar) || (slotValues[1] == bar && slotValues[2] == bar))
	{
		return getBet() * 1;
	}
	if ((slotValues[0] == peer && slotValues[2] == peer) || (slotValues[0] == peer && slotValues[1] == peer) || (slotValues[1] == peer && slotValues[2] == peer))
	{
		return getBet() * 1;
	}
	if ((slotValues[0] == orange && slotValues[2] == orange) || (slotValues[0] == orange && slotValues[1] == orange) || (slotValues[1] == orange && slotValues[2] == orange))
	{
		return getBet() * 1;
	}
	if ((slotValues[0] == seven && slotValues[2] == seven) || (slotValues[0] == seven && slotValues[1] == seven) || (slotValues[1] == seven && slotValues[2] == seven))
	{
		return getBet() * 1;
	}
	if ((slotValues[0] == carrot && slotValues[2] == carrot) || (slotValues[0] == carrot && slotValues[1] == carrot) || (slotValues[1] == carrot && slotValues[2] == carrot))
	{
		return getBet() * 1;
	}
	if ((slotValues[0] == strawberry && slotValues[2] == strawberry) || (slotValues[0] == strawberry && slotValues[1] == strawberry) || (slotValues[1] == strawberry && slotValues[2] == strawberry))
	{
		return getBet() * 1;
	}
	return 0;

}