#ifndef __GAME_H__
#define __GAME_H__
#include "player.h"
#include <fstream>
#include <map>
#include <string>

class Floor;
class Enemy;
class Item;

class GameNotification {
	public:
		virtual void notify( int r, int c, char ch ) = 0;
		virtual void notify( std::string action ) = 0;
		virtual void notify( std::string stat, int newStat ) = 0;
		virtual void setRace( std::string race ) = 0;
		virtual void endGame() = 0;
		virtual ~GameNotification(){}
};

class Game {
	GameNotification *notification;
	Player *player; //player of the session
	Floor *floors[5]; //floors of the dungeon
	int floorNum; //current floor number
	
   public:
    Game( GameNotification *notification );
	~Game();
	void init();
	void init( std::ifstream &fs );
	void makeCharacter( int r, int c, char cell );
	void endGame();
	void clearGame();
	void createPlayer( std::string race );
	void move( std::string dir );
	void attack( std::string dir );
	void use( std::string dir );
	void setRace( std::string race );
	void notify( int r, int c, char ch );
	void notify( std::string action );
	void notify( std::string stat, int newStat );
	void advanceFloor();
	void enemyMove();
};

#endif
