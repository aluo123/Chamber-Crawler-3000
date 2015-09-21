#ifndef __SHADE_H__
#define __SHADE_H__

#include "player.h"

//nothing special about shade

class Shade:public Player{
public:
	Shade();
	~Shade();
	std::string raceType();
};

#endif
