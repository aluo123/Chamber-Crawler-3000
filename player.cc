#include "player.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "cell.h"
#include "gold.h"
#include "potion.h"
#include "draghoard.h"
#include "floor.h"

using namespace std;

Player::Player(int hp, int atk, int def):Character(hp,atk,def),goldAmount(0),maxHP(hp){}

Player::~Player(){}

void Player::setCurrentPlayer(Player *player){
	currentCell->setCharacter(player);
}

void Player::addGold(int amount){
	goldAmount += amount;
	stringstream ss;
	ss << amount;
	string action = "PC gains " + ss.str() + " gold. ";
	f->notify(action);
	notify();
}

void Player::setHP( int hp ) {
	HP=hp;
	if ( HP <= 0 ) {
		die(NULL);
	}
}

void Player::die(Character *killer){
	f->notify("PC has been slain! ");
	f->endGame();
}

void Player::attack( const std::string &dir ) {
	Character::attack(dir);
	notify();
}

void Player::getHit(int dmg, Character *attacker ) {
	stringstream ss;
	ss << dmg;
	string attackAction = attacker->raceType() + " dealt " + ss.str() + " to PC. ";
	f->notify(attackAction);
	Character::getHit(dmg, attacker);
	f->notify();
}

string convertDir( string dir ) {
	if ( dir == "no" ) return "North";
	if ( dir == "ne" ) return "North-East";
	if ( dir == "nw" ) return "North-West";
	if ( dir == "ea" ) return "East";
	if ( dir == "we" ) return "West";
	if ( dir == "so" ) return "South";
	if ( dir == "se" ) return "South-East";
	if ( dir == "sw" ) return "South-West";
	return "Not a direction";
}

void Player::move(const string &dir){
	Cell *nextCell = currentCell->getNeighbour(dir);
	Character *onTile = nextCell->getCharacter();
	string moveAction = "PC moves " + convertDir(dir);
	f->notify(moveAction);
	if(onTile){
		if(onTile->raceType() == "Gold"){
			Gold *gold = dynamic_cast<Gold*>(nextCell->transferObj());
			gold->drop(this);
		}else if(onTile->raceType() == "Dragon Hoard"){
			DragHoard *gold = dynamic_cast<DragHoard*>(onTile);
			if(gold->dragonDied()){
				gold = dynamic_cast<DragHoard*>(nextCell->transferObj());
				gold->pickUp(this);
			}else{
				f->notify(" but there's something in the way. ");
				return; //doesn't do anything if dragon is not dead
			}
		} else if(onTile->raceType() == "Stairs") {
			f->notify("PC descends further into darkness... ");
			f->advanceFloor();
			return;
		}
	}
	Character::move(dir);
	checkRadius();
	notify();
}

void Player::checkRadius(){
	string found = " and sees ";
	for(int i=0;i<8;i++){
		Cell *nextCell = currentCell->getNeighbour(radius[i]);
		if(nextCell){
			Character *object = nextCell->getCharacter();
			if(object){
				Potion *pot = dynamic_cast<Potion*>(object);
				if(pot){
					string article;
					if(pot->raceType() == "unknown"){
						article = "an ";
					}else{
						article = "a ";
					}
					if(found == " and sees "){
						found = found + article + pot->raceType() + " potion";
					}else{
						found = found + " and " + article +pot->raceType() + " potion";
					}
				}
			}
		}
	}
	if(found == " and sees ") found = "";
	f->notify(found + ". ");
}

void Player::useItem(string &dir){
	Cell *nextTile = currentCell->getNeighbour(dir);
	Potion *pot = dynamic_cast<Potion*>(nextTile->transferObj());
	if ( pot == NULL ) {
		f->notify("There's no potion there!");
		return;
	}
	Player *potPlayer = pot->getUsed(this);
	string useAction = "PC uses " + pot->raceType();
	f->notify(useAction);
	notify();
	setCurrentPlayer(potPlayer);
}

int Player::getGold(){
	return goldAmount;
}

void Player::notify() {
	f->notify(row,col,'@');
	f->notify("hp", getHP());
	f->notify("atk", getATK());
	f->notify("def", getDEF());
	f->notify("gold", getGold());
}

string Player::characType(){
	return "player";
}
