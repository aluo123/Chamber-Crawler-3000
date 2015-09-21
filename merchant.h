#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "enemy.h"
#include "merchhoard.h"

class Merchant:public Enemy{
	static bool hostile;
public:
	Merchant();
	~Merchant();
	
	void dropItem(Character *player);
	
	void getHit(int dmg, Character *attacker);
	void checkRadius();
	std::string raceType();
	void notify();
};

#endif
