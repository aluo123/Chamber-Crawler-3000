#include "wapot.h"
#include <iostream>

using namespace std;

bool WA::usedBefore = false;

WA::WA(){}

WA::~WA(){
	player->setCurrentPlayer(player);
	delete this;
}

string WA::raceType(){
	if(usedBefore){
		return "WA";
	}else{
		return "unknown";
	}
}

int WA::getATK(){
	if(player->raceType()=="Drow"){
		return player->getATK() - 7;
	}
	return player->getATK() - 5;
}

void WA::wearOff(){
	setCurrentPlayer(player);
	delete this;
}

Player *WA::getUsed(Player *p){
	player = p;
	setHP(player->getHP());
	setDEF(player->getDEF());
	setATK(getATK());
	usedBefore=true;
	return this;
}
