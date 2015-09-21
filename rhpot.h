#ifndef __RHPOT_H__
#define __RHPOT_H__
#include "potion.h"

class RH:public Potion{
public:
	static bool usedBefore;
	RH();
	~RH();
	
	std::string raceType();
	
	//hp pots don't wear off
	void wearOff();
	
	Player *getUsed(Player *p);
};

#endif
