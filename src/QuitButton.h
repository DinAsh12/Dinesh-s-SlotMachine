/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __QUIT_BUTTON__
#define __QUIT_BUTTON__

#include "Button.h"

class QuitButton : public Button
{
public:
	QuitButton();
	~QuitButton();

	bool ButtonClick() override;
	int countsClickOnce() const;
	void setClickOnce(int clickCount);

private:
	bool m_isClicked;
	int m_pClickFlag{};
};

#endif /* defined (__QUIT_BUTTON__) */