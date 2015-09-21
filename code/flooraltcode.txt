
void buildHorizontalWalls( int firstCol, int endCol, int row ) {
	for ( int i = firstCol; i <= endCol; i++ ) {
		theGrid[row][i] = new Wall(false, g, row, i);
	}
}

void buildVerticalWalls( int firstRow, int endRow, int col ) {
	for ( int i = firstRow; i <= endRow; i++ ) {
		theGrid[i][col] = new Wall(true, g, i, col);
	}
}

void addDoor( int row, int col ) {
	delete theGrid[row][col];
	theGrid[row][col] = new Passage(true, g, row, col);
	passages[pair<int,int>(row,col)] = theGrid[row][col];
}

void addTiles( int firstRow, int endRow, int firstCol, int endCol, int cham ) {
	for ( int row = firstRow; row <= endRow; row++ ) {
		for ( int col = firstCol; col <= endCol; col++ ) {
			theGrid[row][col] = new Tile(g, row, col);
			theChambers[cham][pair<int, int>(row,col)] = theGrid[row][col];
		}
	}
}

Floor::Floor( Game * g ) : g(g){
	gridWidth = 25;
	gridLength = 79;
	//Setting grid to NULL
	for ( int i = 0; i < gridWidth; i++ ) {
		for ( int j = 0; j < gridLength; j++) {
			theGrid[i][j] == NULL;
		}
	}
	
	//Building floor perimeter
	buildVerticalWalls( 0, 24, 0 );
	buildVerticalWalls( 0, 24, 78 );
	buildHorizontalWalls( 1, 77, 0 );
	buildHorizontalWalls( 1, 77, 24 );
		
	//Building Chamber 0 walls
	buildVerticalWalls( 2, 7, 2 );
	buildVerticalWalls( 2, 7, 29 );
	addDoor( 4, 29 );
	buildHorizontalWalls( 3, 28, 2 );
	buildHorizontalWalls( 3, 28, 7 );
	addDoor( 7, 14 );
	
	//Building Chamber 0 floor tiles
	addTiles( 3,6,3,28,0 );
	
	//Building Chamber 1 walls
	buildVerticalWalls( 14, 22, 3 );
	buildVerticalWalls( 14, 22, 25 );
	addDoor( 20,25 );
	buildHorizontalWalls( 3,25,14 );
	buildHorizontalWalls( 3,25,22 );
	addDoor( 14, 14 );
	
	//Building Chamber 1 tiles
	addTiles( 15,21,3,25,1 );
	
	//Building Chamber 2 walls
	buildVerticalWalls( 2, 7, 38);
	addDoor( 4, 38 );
	buildVerticalWalls( 7, 14, )

}
