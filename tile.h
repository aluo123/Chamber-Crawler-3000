#ifndef __TILE_H__
#define __TILE_H__
#include "cell.h"
#include "character.h"
#include "floor.h"

class Tile: public Cell {
	Character *c; //Stores a character to move
	
   public:
	Tile(Floor *f, int row, int col);  //Constructor
	virtual Cell* move( std::string dir ); //moves the player in the specified
	virtual bool acceptChar( Character *c );  //accept a new char
	virtual Character *getCharacter();
	virtual Character *transferObj();
	virtual void setCharacter( Character *p );
	virtual void notify(); //notify the game of changes
};
#endif
