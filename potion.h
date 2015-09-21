#ifndef __POTION_H__
#define __POTION_H__

#include "item.h"

class Potion:public Item{
public:
	Potion();
	virtual ~Potion();
	virtual void wearOff()=0;
	void drop(Player *player);
	virtual Player *getUsed(Player *p)=0;
	virtual void notify();
};

#endif
