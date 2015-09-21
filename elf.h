#ifndef __ELF_H__
#define __ELF_H__

#include "enemy.h"
#include <string>

class Elf: public Enemy{
public:
	Elf();
	~Elf();
	void attack(const std::string &dir);
	
	std::string raceType();
	void notify();
};

#endif
