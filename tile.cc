#include "tile.h"
#include <iostream>
using namespace std;

Tile::Tile(Floor *f, int row, int col): Cell(f, row, col) {
	c = NULL;
}

Cell *Tile::move( string dir ) {
	if ( neighbours.count(dir) > 0) {
		if ( neighbours[dir] != NULL && neighbours[dir]->acceptChar(c) ) {
			c = NULL;
			notify();
			return neighbours[dir];
		}
	}
	return this;
}

bool Tile::acceptChar( Character *c ) {
	if ( this->c == NULL ) {
		this->c = c;
		this->c->setCoord(this);
		this->c->notify();
		return true;
	}
	return false;
}

void Tile::notify() {
	f->notify( row, col, '.');
	if ( c != NULL ) c->notify();
}

Character *Tile::getCharacter() {
	return c;
}

Character *Tile::transferObj(){
	Character *tmp = c;
	c = NULL;
	notify();
	return tmp;
}

void Tile::setCharacter( Character * c ){
	this->c = c;
	if ( this->c != NULL ) {
		this->c->setCoord(this);
	}
	else {
		notify();
	}
}
