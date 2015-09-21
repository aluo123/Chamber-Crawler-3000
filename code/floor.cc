#include "floor.h"
#include "wall.h"
#include "cell.h"
#include "tile.h"
#include "passage.h"
#include "textdisplay.h"
using namespace std;

Floor::Floor(){
	TextDisplay td(79, 25, "Shade");
	gridWidth = 79;
	gridLength = 25;
	for ( int i = 0; i < gridWidth; i++ ) {
		for ( int j = 0; j < gridLength; j++) {
			theGrid[i][j] == NULL;
			td.notify(i,j,' ');
		}
	}
	
	for ( int j = 2; j <= 7; j++ ) {
		int i = 2;
		int k = i + 27;
		theGrid[i][j] = new Wall(true);
		td.notify(i,j, '|');
		if ( j != 4 ) {
			theGrid[k][j] = new Wall(true);
			td.notify(k,j, '|');
		}
		else {
			theGrid[k][4] = new Passage(true);
			td.notify(k,4, '+');
		}
	}
	
	for ( int i = 3; i <= 28; i++ ) {
		int j = 3;
		int k = j + 3;
		theGrid[i][j] = new Wall(false);
		td.notify(i,j, '-');
		if ( i != 11 ) {
			theGrid[i][k] = new Wall(false);
			td.notify(i,k, '-');
		}
		else {
			theGrid[11][k] = new Passage(true);
			td.notify(11, k, '-');
		}
	}
		
}

int main(){
	Floor floor;
}
