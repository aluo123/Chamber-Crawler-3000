#ifndef __FLOOR_H__ 
#define __FLOOR_H__
#include <map>
#include <vector>
#include <string>
#include <fstream>

class Cell;
class Player;
class Game;
class Enemy;
class Item;
class Gold;
class Potion;

typedef std::map<std::pair<int, int>, Cell*> chamber;

class Floor{
	Game *g;
	std::pair<int,int> playerPosn;
	int numEnemies;
	std::map<Enemy *, int> enemies;
	int numGold;
	std::map<Gold *, int> goldPiles;
	int numPotions;
	std::map<Potion *, int> potions;
	chamber theChambers[5];
	int gridWidth, gridLength;
	Cell* theGrid[25][79];
	void placeChamber( int r, int c );
	void createCell( int r, int c, char ch );
	void addNeighbours( int row, int col );
	std::pair<int,int> randTile( int chamberNum );
	void makeCharacter( int r, int c, char cell );
	
   public:
	Floor( Game * g );
	~Floor();
	void setPlayerPosn( int row, int col );
	void setPlayer( Player *player );
	void init();
	void init( std::ifstream &fs );
	void enemyMove();
	void enemyDeath( Enemy * );
	void notify();
	void notify( int r, int c, char ch ) const;
	void notify( std::string action ) const ;
	void notify( std::string stat, int newStat ) const;
	void endGame();
	void advanceFloor();
	
};

#endif
