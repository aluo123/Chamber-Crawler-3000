#include "drow.h"

Drow::Drow():Player(150,25,15){}

Drow::~Drow(){}

void Drow::useItem(std::string &dir){
	Player::useItem(dir);
}

std::string Drow::raceType(){
	return "Drow";
}

