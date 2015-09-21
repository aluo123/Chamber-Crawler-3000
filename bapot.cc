#include "bapot.h"
#include <iostream>

using namespace std;

bool BA::usedBefore = false;

BA::BA(){}

BA::~BA(){
	player->setCurrentPlayer(player);
	delete this;
}

string BA::raceType(){
	if(usedBefore){
		return "BA";
	}else{
		return "unknown";
	}
}

int BA::getATK(){
	if(player->raceType()=="Drow"){
	return player->getATK() + 7;
	}
	return player->getATK() + 5;
}

void BA::wearOff(){
	setCurrentPlayer(player);
	delete this;
}

Player *BA::getUsed(Player *p){
	player = p;
	setHP(player->getHP());
	setDEF(player->getDEF());
	setATK(getATK());
	usedBefore=true;
	return this;
}
