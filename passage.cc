#include "passage.h"
#include "player.h"
#include "character.h"
using namespace std;

Passage::Passage( bool isDoor, Floor *f, int row, int col ): Cell(f, row, col), player(NULL), isDoor(isDoor) {}

Cell *Passage::move( string dir ){
	if ( neighbours.count(dir) > 0 ) {
		if ( neighbours[dir] != NULL && neighbours[dir]->acceptChar(player) ) {
			player = NULL;
			notify();
			return neighbours[dir];
		}
	}
	return this;
}

bool Passage::acceptChar( Character *c ) {
	Player *p = dynamic_cast<Player*>(c);
	if ( p == NULL ) return false;
	player = p;
	player->setCoord(this);
	return true;
}

//Updates the game
void Passage::notify() {
	if ( isDoor ) {
		f->notify( row, col, '+' );
	}
	else f->notify( row, col, '#' );
	if ( player != NULL ) player->notify();
}

Character *Passage::getCharacter(){
	return player;
}

void Passage::setCharacter(Character *c){
	Player *tempPlay = dynamic_cast<Player*>(c);
	if (!tempPlay) return;
	player = tempPlay;
	player->setCoord(this);
}
