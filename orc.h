#ifndef __ORC_H__
#define __ORC_H__

#include "enemy.h"

class Orc: public Enemy{
public:
	Orc();
	~Orc();
	void attack(const std::string &dir);
	std::string raceType();
	void notify();
};

#endif
