#ifndef __WALL_H__
#define __WALL_H__
#include "cell.h"
#include "floor.h"

class Wall: public Cell {
	bool empty;
	bool vertical;
	
   public:
    Wall(bool vertical, Floor * f, int row, int col, bool empty=false);
	virtual Cell* move( std::string dir );
	virtual bool acceptChar( Character *c );
	virtual void notify();
	virtual Character *getCharacter();
};

#endif
