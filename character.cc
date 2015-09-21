#include "character.h"
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include "cell.h"
#include "floor.h"

using namespace std;

const string Character::radius[8] = {"no","ne","ea","se","so","sw","we","nw"};

Character::Character(int hp,int atk, int def):HP(hp),ATK(atk),DEF(def){}

Character::~Character(){}

Floor* Character::getFloor() {
	return f;
}

void Character::setFloor( Floor * f ) {
	this->f = f;
}

void Character::setHP(int hp){
	HP=hp;
}

void Character::setDEF(int def){
	DEF=def;
}

void Character::setATK(int atk){
	ATK=atk;
}

void Character::attack(const string &dir){
	Cell *nextCell = currentCell->getNeighbour(dir);
	Character *target = nextCell->getCharacter();
	if ( target == NULL ) {
		f->notify("PC swings and hits nothing. ");
		return;
	}
	float fTDef = (float)target->getDEF();
	float fATK = (float)getATK();
	float fdmg = ceil((100/(100+fTDef))*fATK);
	int dmg = (int)fdmg;
	target->getHit(dmg,this);	
}

void Character::setCoord(Cell *cell){
	currentCell = cell;
	row = cell->getRow();
	col = cell->getCol();
}

void Character::move(const string &dir){
	setCoord( currentCell->move(dir) );
}

void Character::getHit(int dmg,Character *attacker){
	HP = HP - dmg;
	if(HP <= 0){
		die(attacker);
	}
}

void Character::notify(){};

int Character::getHP(){
	return HP;
}
int Character::getDEF(){
	return DEF;
}
int Character::getATK(){
	return ATK;
}

