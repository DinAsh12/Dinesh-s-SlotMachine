/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "PlusButton.h"
#include "Game.h"

PlusButton::PlusButton()
// call super constructor
	:Button(
		"../Assets/textures/plus.png",
		"plus",
		PLUS_BUTTON, glm::vec2(360, 734.0f)), m_isClicked(false)
{

}

PlusButton::~PlusButton()
{
}

bool PlusButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Plus Button Clicked!" << std::endl;
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
int PlusButton::countsClickOnce()
{
	return m_pClickFlag;
}

void PlusButton::setClickOnce(int clickCount)
{
	m_pClickFlag = clickCount;
}