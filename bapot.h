#ifndef __BAPOT_H__
#define __BAPOT_H__

#include "potion.h"

class BA:public Potion{
public:
	static bool usedBefore;
	BA();
	~BA();
	
	std::string raceType();
	
	int getATK();
	
	void wearOff();
	
	Player *getUsed(Player *p);
};

#endif
