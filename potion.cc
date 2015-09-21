#include "potion.h"
#include "floor.h"
#include <string>

using namespace std;

Potion::Potion(){}

//returns the player without power ups to the tile
// and deletes the power upped player
Potion::~Potion(){
}

void Potion::drop(Player *player){
	return;
}

void Potion::notify(){
	if ( player != NULL ) {
		f->notify(row,col,'@');
	}
	else {
		f->notify(row,col,'P');
	}
}
