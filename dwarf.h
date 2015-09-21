#ifndef __DWARF_H__
#define __DWARF_H__

#include "enemy.h"
#include <string>

class Dwarf:public Enemy{
public:
	Dwarf();
	~Dwarf();
	
	void getHit(int dmg, Character *attacker);
	std::string raceType();
	void notify();
};

#endif
