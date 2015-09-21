#ifndef __STAIRS_H__
#define __STAIRS_H__
#include <string>
#include "character.h"

class Stairs:public Character {
public:
	std::string characType();
	std::string raceType();
	void notify();
	void die( Character* killer );
};

#endif
