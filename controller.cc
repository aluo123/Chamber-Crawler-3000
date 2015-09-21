#include "controller.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

//initializes the game
void Controller::init() {
	if ( floorPlan == NULL ) {
		g->init();
	}
	else {
		g->init( *floorPlan );
	}
}

void Controller::newGame() {
	g->clearGame();
	string race = "";
	while ( race != "s" && race != "d" && race != "v" && race != "t" && race != "g" ) {
		cout << "Select a race: (s)hade, (d)row, (v)ampire, (t)roll, (g)oblin" << endl;
		cin >> race;
		if (cin.fail()) break;
	}
	g->createPlayer(race);
	td->print();
}

//Constructor
Controller::Controller() {
	seed = time(NULL);
	floorPlan = NULL;
	td = new TextDisplay( 25, 79 );
	g = new Game(this);
	gameover = false;
}

//Destructor
Controller::~Controller() {
	delete g;
	delete td;
	delete floorPlan;
}

void Controller::setfstream( string fs ) {
	floorPlan = new ifstream(fs.c_str());
}

void Controller::setSeed( char * seed ) {
	stringstream ss;
	ss << seed;
	int newSeed;
	ss >> newSeed;
	this->seed = newSeed;
}

//returns true if str is a valid direction
bool isDir( string str ) {
	return ( str == "no" || str == "so" || str == "ea" || str == "we" || 
str == "ne" || str == "nw" || str == "se" || str == "sw" );
}

//executes the game
void Controller::play() {
	srand(seed);
	init();
	newGame();
	string cmd;
	while ( cin >> cmd && gameover == false ) {
		if ( isDir(cmd) ) {
			g->move(cmd);
		}
		else if ( cmd == "u" ) {
			string dir;
			cin >> dir;
			if ( isDir(dir) ) {
				g->use(dir);
			}
		}
		else if ( cmd == "a" ) {
			string dir;
			cin >> dir;
			if ( isDir(dir) ) {
				g->attack(dir);
			}
		}
		else if ( cmd == "r" ) {
			init();
		}
		else if ( cmd == "q" ) {
			break;
		}
		if ( gameover ) break;
		g->enemyMove();
		td->print();
	}
}

void Controller::endGame(){
	gameover = false;
}

void Controller::setRace( string race ) {
	td->setRace(race);
}

void Controller::notify( int r, int c, char ch ){
	td->notify(r,c,ch);
}

void Controller::notify( string action ){
	td->notify(action);
}

void Controller::notify( string stat, int newStat ){
	td->notify(stat,newStat);
}
