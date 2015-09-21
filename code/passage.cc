#include "passage.h"

Passage::Passage(): player(NULL){}

Passage::Passage( bool isDoor ): player(NULL), isDoor(NULL) {}

void Passage::setCoord( int row, int col ){
	Cell::setCoord( row, col );
	notify();
}

Cell *Passage::move( string dir ){
	if ( neighbours.count(dir) > 0 ) {
		if ( neighbours[dir]->acceptChar(player) ) {
			player = NULL;
			notify();
			return neighbours[dir];
		}
	}
	return this;
}

bool Passage::acceptChar( Character *c ) {
	Player *p = dynamic_cast<Player*>(c);
	if ( p == NULL ) return false;
	player = p;
	return true;
}

void Passage::notify() {
	if ( isDoor ) {
		floor->notify( row, col, '+' );
	}
	else floor->notify( row, col, '#' );
}
	