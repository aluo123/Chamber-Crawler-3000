#include "elf.h"
#include <string>
#include "cell.h"

Elf::Elf():Enemy(40,30,10){}
Elf::~Elf(){}

void Elf::attack(const std::string &dir){
	Cell *nextCell = currentCell->getNeighbour(dir);
	Character *target = nextCell->getCharacter();
	if(target->raceType() == "Drow"){
		Enemy::attack(dir);
		Enemy::attack(dir);
	}else{
		Enemy::attack(dir);
	}
}

std::string Elf::raceType(){
	return "Elf";
}

void Elf::notify(){
	f->notify(row,col,'E');
}

