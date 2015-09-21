#ifndef __WALL_H__
#define __WALL_H__
#include "cell.h"

class Wall: public Cell {
	bool vertical;
	
   public:
	void setOrientation( bool orientation );
	virtual void setCoord( int row, int col );
	virtual Cell* move( std::string dir );
	virtual bool acceptChar( Character *c );
	virtual void notify();
};

#endif
