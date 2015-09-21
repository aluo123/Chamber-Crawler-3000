#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

#include "player.h"

class Item:public Player{
protected:
	Player *player;
	
public:
	Item();
	virtual ~Item()=0;
	virtual void setHP(int hp);
	virtual void setDEF(int def);
	virtual void setATK(int atk);
	virtual int getHP();
	virtual int getDEF();
	virtual int getATK();
	virtual void addGold(int amount=0);
	virtual void attack(const std::string &dir);
	virtual void getHit(int dmg, Character * attacker);
	virtual void useItem(std::string &dir);
	virtual void move(const std::string &dir);
	virtual void notify()=0;
	virtual void drop(Player *player)=0;
	virtual std::string raceType()=0;
	std::string characType();
};


#endif
