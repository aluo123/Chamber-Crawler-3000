#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "player.h"

class Vampire:public Player{
public:
	Vampire();
	~Vampire();
	std::string raceType();
	void attack(const std::string &dir);

};

#endif
