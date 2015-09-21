#include "rhpot.h"

bool RH::usedBefore = false;

RH::RH(){}
RH::~RH(){}

std::string RH::raceType(){
	if(usedBefore){
		return "RH";
	}else{
		return "unknown";
	}
}

//hp pots don't wear off
void RH::wearOff(){return;}

Player *RH::getUsed(Player *p){
	usedBefore = true;
	if(p->raceType()=="Drow"){
		if(p->getHP()+15 > p->maxHP){
			p->setHP(p->maxHP);
		}else{
			p->setHP(p->getHP()+15);
		}
	}else{
		if(p->getHP()+10 > p->maxHP){
			p->setHP(p->maxHP);
		}else{
			p->setHP(p->getHP()+10);
		}
	}
	return p;
}
