/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#include "QuitButton.h"
#include "Game.h"

QuitButton::QuitButton()
// call super constructor
	:Button(
		"../Assets/textures/quit.png",
		"quit",
		QUIT_BUTTON, glm::vec2(280, 734.0f)), m_isClicked(false)
{

}

QuitButton::~QuitButton()
= default;

bool QuitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Quit Button Clicked!" << std::endl;
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
int QuitButton::countsClickOnce() const
{
	return m_pClickFlag;
}

void QuitButton::setClickOnce(int clickCount)
{
	m_pClickFlag = clickCount;
}