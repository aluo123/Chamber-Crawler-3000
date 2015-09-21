#include "cell.h"
using namespace std;

Cell::Cell(){}

Cell::~Cell(){}

int Cell::getRow(){
	return row;
}

int Cell::getCol(){
	return col;
}

void Cell::setCoord( int row, int col ) {
	this->row = row;
	this->col = col;
}

void Cell::setFloor( Floor *floor ) {
	this->floor = floor;
}

void Cell::addNeighbour( string dir, Cell *neighbour ) {
	neighbours.insert(pair<string, Cell*>(dir, neighbour));
}

map<string, Cell*> Cell::getNeighbours() {
	return neighbours;
}
