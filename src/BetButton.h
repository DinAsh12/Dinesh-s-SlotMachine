/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/

#pragma once
#ifndef __BET_BUTTON__
#define __BET_BUTTON__

#include "Button.h"

class BetButton : public Button
{
public:
	BetButton();
	~BetButton();

	bool ButtonClick() override;
	int countsClickOnce();
	void setClickOnce(int clickCount);

private:
	bool m_isClicked;
	int m_pClickFlag;
};

#endif /* defined (__BET_BUTTON__) */