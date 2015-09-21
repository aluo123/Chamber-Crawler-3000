#include "wdpot.h"

using namespace std;

bool WD::usedBefore = false;

WD::WD(){}

WD::~WD(){
	player->setCurrentPlayer(player);
	delete this;
}

string WD::raceType(){
	if(usedBefore){
		return "WD";
	}else{
		return "unknown";
	}
}

int WD::getDEF(){
	if(player->raceType()=="Drow"){
		return player->getDEF() - 7;
	}
		return player->getDEF() - 5;
}

void WD::wearOff(){
	setCurrentPlayer(player);
	delete this;
}

Player *WD::getUsed(Player *p){
	player = p;
	setHP(player->getHP());
	setDEF(getDEF());
	setATK(player->getATK());
	usedBefore=true;
	return this;
}
