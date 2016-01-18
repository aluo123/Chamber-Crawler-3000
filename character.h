#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>


//An abstract class Character to provide an interface for 
//player and enemy races
//children class must implement set and get methods for HP DEF and ATK


class Cell;
class Floor;

class Character{
protected:
	Floor *f;
	//status of the character
	int HP;
	int ATK;
	int DEF;
	
	//the position of the player on the board
	int row,col;

	//tile that the character is currently standing on
	Cell *currentCell;
	
	//character default ctor
	Character(int hp=0,int atk=0, int def=0);
		
	//instructions for dying
	virtual void die(Character *killer)=0;
	
	static const std::string radius[8];
	
public:
	// makes Character abstract
	virtual ~Character()=0;
	
	Floor* getFloor();
	void setFloor( Floor * f );
	//updates player stats
	virtual void setHP(int hp);
	virtual void setDEF(int def);
	virtual void setATK(int atk);
	virtual int getHP();
	virtual int getDEF();
	virtual int getATK();
	

	//sets the coordinates for the character
	virtual void setCoord(Cell *cell);
	
	//attacks the target
	virtual void attack(const std::string &dir);
	
	//moves the character around
	virtual void move(const std::string &dir);
	
	//called by the enemy to hit the this character
	virtual void getHit(int dmg, Character *attacker);
	
	virtual void notify();
	
	virtual std::string raceType()=0;
	
	virtual std::string characType()=0;
};

#endif

