/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "MinusButton.h"
#include "Game.h"

MinusButton::MinusButton()
// call super constructor
	:Button(
		"../Assets/textures/minus.png",
		"minus",
		MINUS_BUTTON, glm::vec2(600, 734.0f)), m_isClicked(false)
{

}

MinusButton::~MinusButton()
{
}

bool MinusButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
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
int MinusButton::countsClickOnce()
{
	return m_pClickFlag;
}

void MinusButton::setClickOnce(int clickCount)
{
	m_pClickFlag = clickCount;
}