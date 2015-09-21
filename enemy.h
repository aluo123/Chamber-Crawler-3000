#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"
#include "floor.h"

class Player;
class Item;

class Enemy: public Character{	
protected:
	Item *item;
	//instructions for an enemy to dies
	virtual void die(Character *killer);
	
public:
	virtual void checkRadius();
	Enemy(int hp,int atk,int def);
	virtual ~Enemy()=0;
	//enemies miss 50% of the time 
	virtual void attack(const std::string &dir);
	virtual void getHit(int dmg, Character *attacker);
	virtual void dropItem(Character *player);
	virtual void move(const std::string &dir);
	std::string characType();
};

#endif
