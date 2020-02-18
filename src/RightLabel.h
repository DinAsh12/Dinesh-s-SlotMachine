/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __RIGHT_SPIN__
#define __RIGHT_SPIN__


#include "DisplayObject.h"

class RightSpin : public DisplayObject
{
public:
	RightSpin();
	~RightSpin();
	void draw() override;
	void update() override;
	void clean() override;
	void draw(std::string imageID);
};

#endif