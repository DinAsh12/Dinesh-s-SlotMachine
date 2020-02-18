/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once
#ifndef __MACHINE__
#define __MACHINE__
#include "DisplayObject.h"

class Machine : public DisplayObject
{
public:
	Machine();
	~Machine();

	void draw() override;
	void update() override;
	void clean() override;
};

#endif /* defined (__MACHINE__) */