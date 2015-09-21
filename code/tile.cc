#include "tile.h"
using namespace std;

Tile::Tile() {
	c = NULL;
}

Tile::~Tile() {
	delete c;
}

void Tile::setCoord( int row, int col ) {
	Cell::setCoord( row, col );
	notify();
}

Cell *Tile::move( string dir ) {
	if ( neighbours.count(dir) > 0) {
		if ( neighbours[dir].acceptChar(c) ) {
			c = NULL;
			notify();
			return neighbours[dir];
		}
	}
	return this;
}

bool Tile::acceptChar( Character *c ) {
	this->c = c;
	return true;
}

void Tile::notify() {
	floor->notify( row, col, '.');
}
