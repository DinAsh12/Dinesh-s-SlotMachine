/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __START_BACKGROUND__
#define __START_BACKGROUND__
#include "DisplayObject.h"

class StartBackground : public DisplayObject
{
public:
	StartBackground();
	~StartBackground();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__START_BACKGROUND__) */