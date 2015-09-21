#ifndef __GOLD_H__
#define __GOLD_H__

#include "item.h"

class Gold:public Item{
protected:
	int value;
public:
	Gold(int value);
	virtual ~Gold()=0;
	void drop(Player *player);
	virtual void notify();
	std::string raceType();
};

#endif
