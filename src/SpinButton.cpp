/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
// call super constructor
	:Button(
		"../Assets/textures/spin.png",
		"spin",
		SPIN_BUTTON, glm::vec2(750, 734.0f)), m_isClicked(false)
{
	
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			TheSoundManager::Instance()->load("../Assets/audio/mouseclick.wav", "yay", SOUND_SFX);
			std::cout << "Spin Button Clicked!" << std::endl;
			
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
int SpinButton::countClickOnce()
{
	return m_pClickFlag;
}

void SpinButton::setClickOnce(int clickFlag)
{
	m_pClickFlag = clickFlag;
}