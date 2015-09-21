#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "enemy.h"

class Human:public Enemy{
public:
	Human();
	~Human();
	void dropItem(Character *player);
	
	std::string raceType();
	void notify();
};

#endif
