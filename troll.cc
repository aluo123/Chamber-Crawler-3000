#include "troll.h"

Troll::Troll():Player(120,25,15){}

Troll::~Troll(){}

void Troll::attack(const std::string &dir){
	Player::attack(dir);
	setHP(getHP()+5);
}

void Troll::move(const std::string &dir){
	Player::move(dir);
	setHP(getHP()+5);
}

void Troll::setHP(int hp) {
	if (hp > maxHP) {
		HP = maxHP;
	} else {
		HP = hp;
	}
}

std::string Troll::raceType(){
	return "Troll";
}

