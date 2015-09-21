#ifndef __TROLL_H__
#define __TROLL_H__

#include "player.h"

class Troll:public Player{
public:
	Troll();
	~Troll();
	std::string raceType();
	void attack(const std::string &dir);
	void move(const std::string &dir);
	void setHP(int hp);
};

#endif
