#ifndef __GAME_H__
#define __GAME_H__
#include "player.h"
#include "floor.h"

class GameNotification {
	public:
		virtual void notify(){}
};

class Game {
	GameNotification *notification;
	Player *player;
	Floor[5];
	
   public:
    Game();
	~Game();
	void init();
	void notify( int r, int c, char ch );
};

#endif
