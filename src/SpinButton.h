/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __SPIN_BUTTON__
#define __SPIN_BUTTON__

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();


	bool ButtonClick() override;
	int countsClickOnce();
	void setClickOnce(int clickCount);

private:
	bool m_isClicked;
	int m_pClickFlag;
};

#endif /* defined (__SPIN_BUTTON__) */