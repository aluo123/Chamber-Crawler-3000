#include "human.h"
#include "player.h"
#include "item.h"
#include "gold.h"
#include "floor.h"
#include "normalgold.h"

using namespace std;

Human::Human():Enemy(140,20,20){}
Human::~Human(){}

void Human::dropItem(Character *player){
	Item *g1 = new NormalGold();
	Item *g2 = new NormalGold();
	
	Player *p = dynamic_cast<Player*>(player);
	g1->drop(p);
	g2->drop(p);
	
	delete g1;
	delete g2;
}

string Human::raceType(){
	return "Human";
}

void Human::notify() {
	f->notify(row,col, 'H');
}
