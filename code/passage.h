#ifndef __PASSAGE_H__
#define __PASSAGE_H__
#include "cell.h"

class Passage: public Cell {
	Character *player;
	bool isDoor;
   public:
	Passage();
	Passage( bool isDoor );
	virtual void setCoord( int r, int c, char ch );
	virtual Cell* move( std::string dir );
	virtual bool acceptChar( Character *c );
	virtual void notify();
};

#endif
