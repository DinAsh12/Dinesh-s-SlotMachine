/*
 Dinesh Balakrishnan 300991342
 C++ slot machine
 Created: Feb 16 2020
 Last Edited: Feb 18th 2020
*/
#pragma once

#ifndef __MACHINE_REEL__
#define __MACHINE_REEL__

#include "GameObject.h"

class MachineReel : public GameObject
{

public:

	MachineReel();
	~MachineReel();

	void draw() override;
	void update() override;
	void clean() override;

	void spin();
	int getSlotNumber();



private:

	int m_wheelSlotNumber;


};



#endif /*Defined __MACHINE_REEL__ */