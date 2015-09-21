#include "item.h"
using namespace std;

Item::Item():player(NULL){}
Item::~Item(){}

void Item::setHP(int hp) {
	if(player) player->setHP(hp);
}

void Item::setDEF(int def) {
	if(player) player->setDEF(def);
}

void Item::setATK(int atk) {
	if(player) player->setATK(atk);
}

int Item::getHP() {
	if(player) return player->getHP();
	return 0;
}

int Item::getDEF() {
	if(player) return player->getDEF();
	return 0;
}

int Item::getATK(){
	if(player) return player->getATK();
	return 0;
}

void Item::addGold(int amount) {
	if(player) player->addGold(amount);
}

void Item::attack( const string &dir ) {
	if(player) player->attack(dir);
}

void Item::getHit(int dmg, Character * attacker) {
	if(player) player->getHit(dmg,attacker);
}

void Item::useItem(std::string &dir){
	if(player) player->useItem(dir);
}

void Item::move( const string &dir ) {
	if(player) player->move(dir);
} 

std::string Item::characType(){
	if(player==NULL){
		return "item";
	}else{	
		return "player";
	}
}

