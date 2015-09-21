#ifndef __FLOOR_H__ 
#define __FLOOR_H__
#include <map>

typedef map<pair<int, int>, Cell*> chamber;

class Game;
class Cell;

class Floor{
	Game *g;
	chamber theChambers[5];
	int gridWidth, gridLength;
	Cell* theGrid[79][25];
	
   public:
	Floor();
	~Floor();
	void init();
	void makeEnemies();
	void makeItems();
	
};

#endif
