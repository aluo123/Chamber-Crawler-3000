#ifndef __BDPOT_H__
#define __BDPOT_H__

#include "potion.h"

class BD:public Potion{
public:
	static bool usedBefore;
	BD();
	~BD();
	
	std::string raceType();
	
	int getDEF();
	
	void wearOff();
	
	Player *getUsed(Player *p);
};

#endif
