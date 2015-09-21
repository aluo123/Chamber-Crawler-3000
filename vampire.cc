#include "vampire.h"
#include <iostream>

using namespace std;
Vampire::Vampire():Player(50,25,25){}

Vampire::~Vampire(){}

void Vampire::attack(const std::string &dir){
	Character::attack(dir);
	cout << "vampire attack" << getHP() + 5 << endl;
	setHP(getHP()+5);
}

std::string Vampire::raceType(){
	return "Vampire";
}

