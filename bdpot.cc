#include "bdpot.h"

using namespace std;

bool BD::usedBefore = false;

BD::BD(){}

BD::~BD(){
	player->setCurrentPlayer(player);
	delete this;
}

string BD::raceType(){
	if(usedBefore){
		return "BD";
	}else{
		return "unknown";
	}
}

int BD::getDEF(){
	if(player->raceType()=="Drow"){
		return player->getDEF() + 7;
	}
	return player->getDEF() + 5;
}

void BD::wearOff(){
	setCurrentPlayer(player);
	delete this;
}

Player *BD::getUsed(Player *p){
	player = p;
	setHP(player->getHP());
	setDEF(getDEF());
	setATK(player->getATK());
	usedBefore=true;
	return this;
}
