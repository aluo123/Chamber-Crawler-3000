#include "gold.h"
#include "floor.h"
#include <sstream>
using namespace std;

Gold::Gold(int value):value(value){}

Gold::~Gold(){}

void Gold::drop(Player *player){
	player->addGold(value);
}

void Gold::notify() {
	f->notify(row,col, 'G');
}

std::string Gold::raceType(){
	return "Gold";
}
