#include "wall.h"
using namespace std;

void Wall::setOrientation( bool orientation ) {
	vertical = orientation;
}

void Wall::setCoord( int row, int col ) {
	Cell::setCoord( row, col );
	if (vertical) notify(row, col, '|');
	else notify(row, col, '-');
}

Cell* Wall::move( string dir ){}

bool Wall::acceptChar( Character * c ) { return false }
