#ifndef __PHPOT_H__
#define __PHPOT_H__
#include "potion.h"

class PH:public Potion{
public:
	static bool usedBefore;
	PH();
	~PH();
	std::string raceType();
	void wearOff();
	Player *getUsed(Player *p);
};

#endif
