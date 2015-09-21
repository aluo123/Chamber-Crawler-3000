#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include "textdisplay.h"
#include "game.h"
#include <fstream>

class Controller: public GameNotification{
	TextDisplay *td;       //text display
	Game *g;        //game
	std::ifstream *floorPlan;
	int seed;
	bool gameover;
	void init();    //initializes the game state
	void newGame(); //starts a new game
	bool checkWin();//checks if the game is won
	
public:
	Controller();   //constructor
	~Controller();  //destructor
	void setfstream( std::string fs );
	void setSeed( char * seed );
	void play();    //runs the game
	void endGame();
	virtual void setRace( std::string race );
	virtual void notify( int r, int c, char ch );  //notify the game and textdisplay of changes
	virtual void notify( std::string action );
	virtual void notify( std::string stat, int newStat ); 
};
#endif
