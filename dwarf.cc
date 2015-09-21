#include "dwarf.h"
#include <string>

Dwarf::Dwarf():Enemy(100,20,30){}

Dwarf::~Dwarf(){}

void Dwarf::getHit(int dmg, Character *attacker){
	if(attacker->raceType()=="Vampire"){
		attacker->getHit(5,this);
	}else{
		Enemy::getHit(dmg,attacker);
	}
}

std::string Dwarf::raceType(){
	return "Dwarf";
}

void Dwarf::notify(){
	f->notify(row,col,'W');
}

