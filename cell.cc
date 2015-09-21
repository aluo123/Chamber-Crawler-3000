#include "cell.h"
using namespace std;

Cell::Cell( Floor *f, int row, int col ) : f(f), row(row), col(col) {}

Cell::~Cell(){}

int Cell::getRow(){
	return row;
}

int Cell::getCol(){
	return col;
}

void Cell::addNeighbour( string dir, Cell *neighbour ) {
	neighbours.insert(pair<string, Cell*>(dir, neighbour));
}

Cell *Cell::getNeighbour(const std::string &dir){
	if ( neighbours.count(dir) > 0 )	return neighbours[dir];
	else return NULL;
}

Character *Cell::transferObj(){
	return NULL;
}

void Cell::setCharacter(Character *p){
	return;
}
