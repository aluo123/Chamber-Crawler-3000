#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include "cell.h"
#include "floor.h"

class Player; 

class Passage: public Cell {
	Player *player;
	bool isDoor;
   public:
	Passage( bool isDoor, Floor *f, int row, int col );
	virtual Cell* move( std::string dir );
	virtual bool acceptChar( Character *c );
	virtual Character *getCharacter();
	virtual void setCharacter( Character *c );
	virtual void notify();
};

#endif
