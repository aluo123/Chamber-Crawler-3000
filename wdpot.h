#ifndef __WDPOT_H__
#define __WDPOT_H__

#include "potion.h"

class WD:public Potion{
public:
	static bool usedBefore;
	WD();
	~WD();
	
	std::string raceType();
	
	int getDEF();
	
	void wearOff();
	
	Player *getUsed(Player *p);
};

#endif
