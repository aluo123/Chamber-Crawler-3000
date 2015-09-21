#include "enemy.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "item.h"
#include "gold.h"
#include "normalgold.h"
#include "smallgold.h"
#include "cell.h"
#include "floor.h"
#include <iostream>
#include <sstream>

using namespace std;

Enemy::Enemy(int hp,int atk,int def):Character(hp,atk,def),item(NULL){
}

Enemy::~Enemy(){}

void Enemy::attack(const string &dir){
	int random = rand() % 2;
	if(random==1){
		Character::attack(dir);
	}
	else {
		string miss = this->raceType() + " tried to hit PC but missed! ";
		f->notify(miss);
	}
}

void Enemy::die(Character *killer){
	dropItem(killer);
    if(killer->raceType() == "Goblin"){
		Player *p = dynamic_cast<Player*>(killer);
		p->addGold(5);
	}
	string death = this->raceType() + " has been slain!. ";
	f->notify(death);
	f->enemyDeath(this);
	currentCell->setCharacter(NULL);
}

void Enemy::getHit( int dmg, Character *attacker ) {
	stringstream ss;
	ss << dmg;
	ss << " " << HP;
	string damage;
	string health;
	ss >> damage;
	ss >> health;
	string attackAction = "PC dealt " + damage + " to " + this->raceType() + " (" + health + "). ";
	f->notify(attackAction);
	Character::getHit(dmg, attacker);
}

void Enemy::dropItem(Character *player){
	int random = rand() % 2;
	Player *p = dynamic_cast<Player*>(player);
	if(random){
		item = new SmallGold();
	}else{
		item = new NormalGold();
	}
	item->setFloor(getFloor());
	item->drop(p);
}

void Enemy::move(const string &dir){
		while(true){
			int i = rand() %8;
			string direct = radius[i];
			Cell *prev = currentCell;
			currentCell->move(direct);
			if(prev!=currentCell) break;
		}
}

void Enemy::checkRadius(){
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
	notify();
	move("not used for anything");
}

string Enemy::characType(){
	return "Enemy";
}
