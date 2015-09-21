#ifndef __WAPOT_H__
#define __WAPOT_H__

#include "potion.h"

class WA:public Potion{
public:
	static bool usedBefore;
	WA();
	~WA();
	
	std::string raceType();
	
	int getATK();
	
	void wearOff();
	
	Player *getUsed(Player *p);
};

#endif
