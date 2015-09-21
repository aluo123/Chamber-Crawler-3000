#ifndef __DRAGHOARD_H__
#define __DRAGHOARD_H__

#include "gold.h"

class DragHoard:public Gold{
	bool dragonKilled;
public:
	DragHoard():Gold(6),dragonKilled(false){}
	~DragHoard(){}
	bool dragonDied(){
		return dragonKilled;
	}
	
	void pickUp(Player *player){
		player->addGold(value);
	}
	
	void drop(Player *player){
		dragonKilled = true;
	}
	
	std::string raceType(){
		return "Dragon Hoard";
	}

};

#endif
