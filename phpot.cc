#include "phpot.h"

bool PH::usedBefore = false;

PH::PH(){}
PH::~PH(){}

std::string PH::raceType(){
	if(usedBefore){
		return "PH";
	}else{
		return "unknown";
	}
}

void PH::wearOff(){return;}

Player *PH::getUsed(Player *p){
	usedBefore = true;
	if(p->getHP()-10 < 0){
		p->setHP(0);
	}else{
		p->setHP(p->getHP()-10);
	}
	return p;
}
