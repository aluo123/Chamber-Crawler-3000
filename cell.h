#ifndef __CELL_H__
#define __CELL_H__
#include <map>
#include <string>

class Character;
class Game;
class Floor;

class Cell {
   protected:
   	Floor * f;						//game of the cell
	int row, col;					//coordinates of the cell
	std::map<std::string, Cell*> neighbours;//cells adjacent to the cell
	
   public:
	Cell( Floor *f, int row, int col);		//Constructor
	virtual ~Cell();	//Destructor
	int getRow();
	int getCol();
	void setGame( Game * game );    //sets the game
	virtual Cell* move( std::string dir ) = 0;  //moves the character in the cell, if it has one
	virtual bool acceptChar( Character *c ) = 0;  //accepts a new character, if it can
	virtual void notify() = 0;  //notifies the floor
	void addNeighbour( std::string dir, Cell* neighbour );
	virtual Character *getCharacter() = 0;
	virtual Character *transferObj();
	virtual void setCharacter(Character *p);
	Cell *getNeighbour(const std::string &dir);
};

#endif
