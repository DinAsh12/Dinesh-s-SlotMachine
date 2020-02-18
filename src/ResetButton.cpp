/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "ResetButton.h"
#include "Game.h"

ResetButton::ResetButton()
// call super constructor
	:Button(
		"../Assets/textures/reset.png",
		"reset",
		RESET_BUTTON, glm::vec2(192, 732.0f)), m_isClicked(false)
{

}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Reset Button Clicked!" << std::endl;
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
int ResetButton::countsClickOnce()
{
	return m_pClickFlag;
}

void ResetButton::setClickOnce(int clickCount)
{
	m_pClickFlag = clickCount;
}