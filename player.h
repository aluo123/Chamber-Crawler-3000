#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"
#include <string>

class Item;
class Floor;

class Player:public Character{
	//stores the amount of gold obtained by the player
	int goldAmount;

public:
	const int maxHP;
	//ctor for player
	Player(int hp=0, int atk=0, int def=0);

	virtual ~Player()=0;
	
	virtual void setHP( int hp );
	//what a player does when they die
	virtual void die(Character *killer);
	
	//updates the current tile's player
	void setCurrentPlayer(Player *player);
	
	//increases gold, called by enemy when they die or when picking up dragon hoard
	//should be called every time the monster dies
	virtual void addGold(int amount=0);
	
	virtual void attack(const std::string &dir);
	virtual void getHit(int dmg, Character *attacker);
	
	//lets the player use the item pass in null if using item from enemy
	virtual void useItem(std::string &dir);

	//moves the player to x,y position on the board
	virtual void move(const std::string &dir);
	
	void checkRadius();
	
	int getGold();
	
	virtual void notify();
	
	std::string characType();
};

#endif

