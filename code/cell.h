#ifndef __CELL_H__
#define __CELL_H__
#include <map>
#include <string>

class Character;
class Game;

class Cell {
   protected:
	int row, col;					//coordinates of the cell
	Game * game;					//game of the cell
	std::map<std::string, Cell*> neighbours;//cells adjacent to the cell
	
   public:
	Cell();		//Constructor
	virtual ~Cell();	//Destructor
	int getRow();
	int getCol();
	virtual void setCoord( int row, int col );  //set the coordinates of the cell
	void setGame( Game * game );    //sets the game
	virtual Cell* move( std::string dir ) = 0;  //moves the character in the cell, if it has one
	virtual bool acceptChar( Character *c ) = 0;  //accepts a new character, if it can
	virtual void notify() = 0;  //notifies the floor
	void addNeighbour( std::string dir, Cell* neighbour );
	std::map<std::string, Cell*> getNeighbours();
};

#endif
