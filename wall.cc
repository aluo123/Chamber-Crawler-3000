#include "wall.h"
using namespace std;

Wall::Wall(bool vertical, Floor *f, int row, int col, bool empty): Cell(f, row, col), empty(empty), vertical(vertical) {}

Cell* Wall::move( string dir ){	return NULL; }

bool Wall::acceptChar( Character * c ) { return false; }

void Wall::notify(){
	if(empty) f->notify(row,col,' ');
	else {
		if (vertical) f->notify(row, col, '|');
		else f->notify(row, col, '-');
	}
}

Character *Wall::getCharacter(){
	return NULL;
}
