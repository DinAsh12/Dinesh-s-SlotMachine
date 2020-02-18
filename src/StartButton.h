/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __START_BUTTON__
#define __START_BUTTON__

#include "Button.h"

class StartButton : public Button
{
public:
	StartButton();
	~StartButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__START_BUTTON__) */