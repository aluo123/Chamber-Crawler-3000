#include "floor.h"
#include "wall.h"
#include "cell.h"
#include "tile.h"
#include "game.h"
#include "passage.h"
#include "textdisplay.h"
#include "normalgold.h"
#include "smallgold.h"
#include "merchhoard.h"
#include "draghoard.h"
#include "rhpot.h"
#include "bapot.h"
#include "bdpot.h"
#include "phpot.h"
#include "wdpot.h"
#include "wapot.h"
#include "potion.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "stairs.h"
#include "dragon.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

//Groups tiles in chambers
void Floor::placeChamber( int r, int c ) {
	if ( r >= 3 && r <= 6 && c >= 3 && c <= 28 ) {
		theChambers[0][pair<int, int>(r,c)] = theGrid[r][c];
	}
	else if ( r >= 15 && r <= 21 && c >= 4 && c <= 24 ) {
		theChambers[1][pair<int, int>(r,c)] = theGrid[r][c];
	}
	else if ( (( r==3 || r == 4) && c >= 39 && c <= 61) ||
			(r == 5 && c >= 39 && c <= 69) ||
			(r == 6 && c >= 39 && c <= 72) ||
			(r >= 7 && r <= 12 && c >= 61 && c <= 75 )) {
		theChambers[2][pair<int,int>(r,c)] = theGrid[r][c];
	}
	else if ( r >= 10 && r <= 12 && c >= 38 && c <= 49 ) {
		theChambers[3][pair<int, int>(r,c)] = theGrid[r][c];
	}
	else if ( (r >= 16 && r <= 18 && c >= 65 && c <= 75 ) || 
			( r >= 19 && r <= 21 && c >= 37 && c <= 75 )) {
		theChambers[4][pair<int,int>(r,c)] = theGrid[r][c];		
	}
}

//Creates cell based on character
void Floor::createCell(int r, int c, char ch) {
	if ( ch == '|' ) {
		theGrid[r][c] = new Wall(true, this, r, c);
	}
	else if ( ch == '-' ) {
		theGrid[r][c] = new Wall(false, this, r, c);
	}
	else if ( ch == '.' ) {
		theGrid[r][c] = new Tile(this,r,c);
	}
	else if ( ch == '+' ) {
		theGrid[r][c] = new Passage(true, this, r, c);
	}
	else if ( ch == '#' ) {
		theGrid[r][c] = new Passage(false, this, r, c);
	}
	else if ( ch == ' ' ) {
		theGrid[r][c] = new Wall(false, this, r, c, true);
	}
}

//Adds Neighbours to cells
void Floor::addNeighbours( int row, int col) {
	if ( theGrid[row][col] == NULL ) return;
	if ( row > 0 && theGrid[row-1][col] != NULL ) {
		theGrid[row][col]->addNeighbour("no", theGrid[row-1][col]);
		if ( col > 0 && theGrid[row-1][col-1] != NULL ) {
			theGrid[row][col]->addNeighbour("nw", theGrid[row-1][col-1]);
		}
	}
	if ( col > 0 && theGrid[row][col-1] != NULL ) {
		theGrid[row][col]->addNeighbour("we", theGrid[row][col-1]);
		if ( row < 24 && theGrid[row+1][col-1] != NULL ) {
			theGrid[row][col]->addNeighbour("sw", theGrid[row+1][col-1]);
		}
	}
	if ( row < 24 && theGrid[row+1][col] != NULL ) {
		theGrid[row][col]->addNeighbour("so", theGrid[row+1][col]);
		if( col < 78 && theGrid[row+1][col+1] != NULL ) {
			theGrid[row][col]->addNeighbour("se", theGrid[row+1][col+1]);
		}
	}
	if ( col < 78 && theGrid[row][col+1] != NULL ) {
		theGrid[row][col]->addNeighbour("ea", theGrid[row][col+1]);
		if( row > 0 && theGrid[row-1][col+1] != NULL ) {
			theGrid[row][col]->addNeighbour("ne", theGrid[row-1][col+1]);
		}
	}
}

//Constructor
Floor::Floor( Game * g ): g(g), gridWidth(25), gridLength(79) {
	#ifdef DEBUG
	cout << "Entering floor creation" << endl;
	#endif
	//Takes basic floor from a source file
	ifstream fs("basefloor.txt");
	string temp;
	//Creates the basic floor plan
	for ( int i = 0; i < gridWidth; i++ ) {
		getline(fs, temp);
		istringstream ss(temp);
		for ( int j = 0; j < gridLength; j++ ) {
			char cell;
			ss >> noskipws >> cell;
			//Creates each cell
			createCell(i,j, cell);
		}
	}
	//Groups neighbours and chambers
	for ( int i = 0; i < gridWidth; i++ ) {
		for( int j = 0; j < gridLength; j++ ) {
			addNeighbours(i,j);
			placeChamber(i,j);
		}
	}
	numEnemies = 0;
	numPotions = 0;
	numGold = 0;
}

//Destructor: deletes the grid and the items and enemies
Floor::~Floor() {
	for ( int i = 0; i < gridWidth; i++ ) {
		for ( int j = 0; j < gridLength; j++ ) {
			delete theGrid[i][j];
		}
	}
	for ( map<Enemy *,int>::iterator it = enemies.begin(); it != enemies.end(); it++ ) {
		delete it->first;
	}
	for ( map<Potion *,int>::iterator it = potions.begin(); it != potions.end(); it++ ) {
		delete it->first;
	}
	for ( map<Gold *,int>::iterator it = goldPiles.begin(); it != goldPiles.end(); it++ ) {
		delete it->first;
	}
}

//Sets the player start position
void Floor::setPlayerPosn( int row, int col ) {
	playerPosn = pair<int,int>(row,col);
}

//Sets the player at the start position
void Floor::setPlayer( Player *player ) {
	int row = playerPosn.first;
	int col = playerPosn.second;
	theGrid[row][col]->setCharacter(player);
}

//Finds a random tile in a chamber
pair<int,int> Floor::randTile( int chamberNum ) {
	chamber::iterator it = theChambers[chamberNum].begin();
	int randChamPosn = rand() % theChambers[chamberNum].size();
	advance( it, randChamPosn );
	int r = it->second->getRow();
	int c = it->second->getCol();
	return pair<int,int>(r,c);
}

//Randomly initializes the floor
void Floor::init() {
	int playerChamber = rand() % 5;
	playerPosn = randTile(playerChamber);
	int stairsChamber = playerChamber;
	while ( stairsChamber == playerChamber ) {
		stairsChamber = rand() % 5;
	}
	pair<int,int> stairPosn = randTile(stairsChamber);
	makeCharacter( stairPosn.first, stairPosn.second, '\\');
	while ( numPotions < 10 ) {
		int potionChance = rand() % 6;
		int potionChamber = rand() % 5;
		pair<int,int> potionPosn = randTile(potionChamber);
		makeCharacter( potionPosn.first, potionPosn.second, potionChance + '0');
	}
	while ( numGold < 10 ) {
		int goldChance = rand() % 8;
		int goldChamber = rand() % 5;
		pair<int,int> goldPosn = randTile(goldChamber);
		if ( goldChance <= 4 ) {
			makeCharacter( goldPosn.first, goldPosn.second, '6' );
		}
		else makeCharacter( goldPosn.first, goldPosn.second, '7' );
	}
	while ( numEnemies < 20 ) {
		int enemyChance = rand() % 18;
		int enemyChamber = rand() % 5;
		pair<int,int> enemyPosn = randTile(enemyChamber);
		if ( enemyChance >= 0 && enemyChance <= 3 ) {
			makeCharacter( enemyPosn.first, enemyPosn.second, 'H' );
		}
		else if ( enemyChance >= 4 && enemyChance <= 6 ) {
			makeCharacter( enemyPosn.first, enemyPosn.second, 'W' );
		}
		else if ( enemyChance >= 7 && enemyChance <= 11 ) {
			makeCharacter( enemyPosn.first, enemyPosn.second, 'L' );
		}
		else if ( enemyChance >= 12 && enemyChance <= 13 ) {
			makeCharacter( enemyPosn.first, enemyPosn.second, 'E' );
		}
		else if ( enemyChance >= 14 && enemyChance <= 15 ) {
			makeCharacter( enemyPosn.first, enemyPosn.second, 'O' );
		}
		else if ( enemyChance >= 16 && enemyChance <= 17 ) {
			makeCharacter( enemyPosn.first, enemyPosn.second, 'M' );
		}
	}
}

void Floor::makeCharacter( int r, int c, char cell ) {
	if ( theGrid[r][c] == NULL ) return;
	if ( theGrid[r][c]->getCharacter() ) return;
	if ( cell == '0' ) {
		theGrid[r][c]->setCharacter(new RH);
		numPotions++;
	}
	else if ( cell == '1' ) {
		theGrid[r][c]->setCharacter(new BA);
		numPotions++;
	}
	else if ( cell == '2' ) {
		theGrid[r][c]->setCharacter(new BD);
		numPotions++;
	}
	else if ( cell == '3' ) {
		theGrid[r][c]->setCharacter(new PH);
		numPotions++;
	}
	else if ( cell == '4' ) {
		theGrid[r][c]->setCharacter(new WA);
		numPotions++;
	}
	else if ( cell == '5' ) {
		theGrid[r][c]->setCharacter(new WD);
		numPotions++;
	}
	else if ( cell == '6' ) {
		theGrid[r][c]->setCharacter(new NormalGold);
		numGold++;
	}
	else if ( cell == '7' ) {
		theGrid[r][c]->setCharacter(new SmallGold);
		numGold++;
	}
	else if ( cell == '8' ) {
		theGrid[r][c]->setCharacter(new MerchHoard);
		numGold++;
	}
	else if ( cell == '9' ) {
		theGrid[r][c]->setCharacter(new DragHoard);
		numGold++;
	}
	else if ( cell == '@' ) {
		setPlayerPosn(r,c);
	}
	else if ( cell == 'H' ) {
		Enemy *human = new Human;
		theGrid[r][c]->setCharacter(human);
		enemies[human] = numEnemies++;
	}
	else if ( cell == 'O' ) {
		Enemy *orc = new Orc;
		theGrid[r][c]->setCharacter(orc);
		enemies[orc] = numEnemies++;
	}
	else if ( cell == 'E' ) {
		Enemy *elf = new Elf;
		theGrid[r][c]->setCharacter(elf);
		enemies[elf] = numEnemies++;
	}
	else if ( cell == 'W' ) {
		Enemy *dwarf = new Dwarf;
		theGrid[r][c]->setCharacter(dwarf);
		enemies[dwarf] = numEnemies++;
	}
	else if ( cell == 'M' ) {
		Enemy *merchant = new Merchant;
		theGrid[r][c]->setCharacter(merchant);
		enemies[merchant] = numEnemies++;
	}
	else if ( cell == 'L' ) {
		Enemy *halfling = new Halfling;
		theGrid[r][c]->setCharacter(halfling);
		enemies[halfling] = numEnemies++;
	}
	else if ( cell == 'D' ) {
		Dragon *dragon = new Dragon;
		theGrid[r][c]->setCharacter(dragon);
		dragon->findDragHoard();
		enemies[dragon] = 0;
	}
	else if ( cell == '\\' ) {
		theGrid[r][c]->setCharacter(new Stairs);
	}
	if ( theGrid[r][c]->getCharacter() != NULL ) {
		theGrid[r][c]->getCharacter()->setFloor(this);
	}
}

void Floor::init( ifstream &fs ) {
	string temp;
	for ( int i = 0; i < gridWidth; i++ ) {
		getline( fs, temp );
		istringstream ss(temp);
		for ( int j = 0; j < gridLength; j++ ) {
			char cell;
			ss >> noskipws >> cell;
			makeCharacter(i, j, cell);
		}
	}
}

void Floor::enemyMove(){
	for ( map<Enemy *, int>::iterator it = enemies.begin(); it != enemies.end(); it++ ) {
		it->first->checkRadius();
	}
}

void Floor::enemyDeath( Enemy * enemy ) {
	enemies.erase(enemy);
	delete enemy;
}

void Floor::notify() {
	for ( int i = 0; i < gridWidth; i++ ) {
		for ( int j = 0; j < gridLength; j++ ) {
			if ( theGrid[i][j] != NULL ) {
				theGrid[i][j]->notify();
			}
		}
	}
}

void Floor::notify( int r, int c, char ch ) const {
	g->notify(r,c,ch);
}

void Floor::notify( string action ) const {
	g->notify(action);
}

void Floor::notify( string stat, int newStat ) const {
	g->notify(stat,newStat);
}

void Floor::endGame() {
	g->endGame();
}

void Floor::advanceFloor() {
	g->advanceFloor();
}
