#include "goblin.h"

Goblin::Goblin():Player(110,15,20){}

Goblin::~Goblin(){}

std::string Goblin::raceType(){
	return "Goblin";
}
