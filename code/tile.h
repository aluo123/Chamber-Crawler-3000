#ifndef __TILE_H__
#define __TILE_H__
#include "cell.h"

class Character;

class Tile: public Cell {
	Character *c; //Stores a character to move
	
   public:
	Tile();  //Constructor
	~Tile();  //Destructor
	virtual void setCoord( int row, int col );
	virtual Cell* move( std::string dir ); //moves the player in the specified
	virtual bool acceptChar( Character *p );  //accept a new char
	virtual void notify(); //notify the game of changes
};
#endif
