#include "merchant.h"
#include <string>
#include "cell.h"
#include "merchhoard.h"

bool Merchant::hostile = false;

Merchant::Merchant():Enemy(30,70,5){}
Merchant::~Merchant(){};

void Merchant::dropItem(Character *player){
	item = new MerchHoard();
	Player *p = dynamic_cast<Player*>(player);
	item->drop(p);
}

void Merchant::getHit(int dmg, Character *attacker){
	Enemy::getHit(dmg,attacker);
	hostile = true;
}

std::string Merchant::raceType(){
	return "Merchant";
}

void Merchant::checkRadius(){
	if(hostile){
		for(int i=0;i<8;i++){
			Cell *neighbour = currentCell->getNeighbour(radius[i]);
			if(neighbour!=NULL){
				Character *c = neighbour->getCharacter();
				if(c){
					if(c->characType()=="player"){
						attack(radius[i]);
						return;
					}
				}
			}
		}
	}
	notify();
	move("not used for anything");
}

void Merchant::notify(){
	f->notify(row,col,'M');
}

