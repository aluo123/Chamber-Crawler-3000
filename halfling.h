#ifndef __HALFLING_H__
#define __HALFLING_H__

#include "enemy.h"

class Halfling:public Enemy{
public:
	Halfling();
	~Halfling();
	
	std::string raceType();
	void getHit(int dmg, Character *attacker);
	void notify();
};

#endif

