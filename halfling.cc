#include "halfling.h"
#include <cstdlib>
#include <ctime>


Halfling::Halfling():Enemy(100,15,20){}
Halfling::~Halfling(){}

std::string Halfling::raceType(){
	return "Halfling";
}
void Halfling::getHit(int dmg, Character *attacker){
	srand(time(NULL));
	int random = rand() % 2;
	if(random==1){
		Enemy::getHit(dmg,attacker);
	}else{
		f->notify("You swing at the Halfling but it was too fast for you. ");
	}
}

void Halfling::notify(){
	f->notify(row,col,'L');
}
