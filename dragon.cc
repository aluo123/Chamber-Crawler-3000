#include "dragon.h"
#include "draghoard.h"
#include "cell.h"
#include <cmath>

Dragon::Dragon():Enemy(150,20,20){}

Dragon::~Dragon(){}

void Dragon::checkRadius(){
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
	for(int i=0; i<8; i++) {
		Cell *neighbour = dragonHoardCell->getNeighbour(radius[i]);
		if(neighbour!=NULL) {
			Character *c = neighbour->getCharacter();
			if(c){
				if(c->characType()=="player") {
					float fTDef = (float)c->getDEF();
					float fATK = (float)getATK();
					float fdmg = ceil((100/(100+fTDef))*fATK);
					int dmg = (int)fdmg;
					c->getHit(dmg, this);
				}
			}
		}
	}
	notify();
}

void Dragon::findDragHoard(){
	DragHoard *dh;
	for(int i=0;i<8;i++){
		Cell *nextCell = currentCell->getNeighbour(radius[i]);
		if(nextCell){
			Character *c = nextCell->getCharacter();
			dh = dynamic_cast<DragHoard*>(c);
			if(dh) {
				dragonHoardCell = nextCell;
				break;
			}
		}
	}
	item = dh;
}

void move(std::string &dir){}

void Dragon::notify(){
	f->notify(row,col,'D');
}

std::string Dragon::raceType(){
	return "Dragon";
}

