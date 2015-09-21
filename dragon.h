#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"

class Dragon:public Enemy{
public:
	Dragon();
	~Dragon();
	Cell *dragonHoardCell;
	void checkRadius();
	void findDragHoard();
	//dragon does not move
	void move(std::string &dir);
	std::string raceType();
	void notify();
};

#endif
