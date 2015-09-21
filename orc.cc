#include "orc.h"
#include <cmath>
#include "cell.h"

Orc::Orc():Enemy(180,30,25){}
Orc::~Orc(){}

void Orc::attack(const std::string &dir){
	Cell *nextCell = currentCell->getNeighbour(dir);
	Character *target = nextCell->getCharacter();
	if(target->raceType() == "Goblin"){
		if ( target == NULL ) {
			f->notify("PC swings and hits nothing. ");
			return;
		}
		float fTDef = (float)target->getDEF();
		float fATK = (float)getATK();
		float fdmg = ceil((100/(100+fTDef))*fATK);
		int dmg = (int)(1.5*fdmg);
		target->getHit(dmg,this);	
	}else{
		Enemy::attack(dir);
	}
}

std::string Orc::raceType(){
	return "Orc";
}

void Orc::notify(){
	f->notify(row,col,'O');
}

