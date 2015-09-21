#ifndef __DROW_H__
#define __DROW_H__

#include "player.h"

class Drow:public Player{
	void useItem(std::string &dir);
public:
	Drow();
	~Drow();
	std::string raceType();
};

#endif
