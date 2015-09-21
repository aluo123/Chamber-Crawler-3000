#include "game.h"
#include "floor.h"
#include "shade.h"
#include "enemy.h"
#include "controller.h"
#include <iterator>
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Game::Game( GameNotification *notification ): notification(notification) {
	for ( int i = 0; i < 5; i++ ){
		floors[i] = new Floor(this);
	}
	floorNum = 0;
	notify( "floor", 1 );
}

Game::~Game(){
	clearGame();
	for ( int i = 0; i < 5; i++ ) {
		delete floors[i];
	}
}

void Game::init(){
	for ( int i = 0; i < 5; i++ ) {
		floors[i]->init();
	}
	floors[floorNum]->notify();
}

void Game::init( ifstream &fs ) {
	for ( int i = 0; i < 5; i++ ) {
		floors[i]->init(fs);
	}
	floors[floorNum]->notify();
}

void Game::endGame() {
	int total = player->getGold();
	if ( player->raceType() == "Shade" ) {
		total = total * 3 / 2;
	}
	cout << "Game Over!" << endl;
	cout << "Score is " << total << endl;
	notification->endGame();
	clearGame();
}

void Game::clearGame(){
	delete player;
	floorNum = 0;
}

void Game::createPlayer( string race ) {
	if ( race == "s" ) {
		player = new Shade();
		setRace("Shade");
	}
	else if ( race == "d" ) {
		player = new Drow();
		setRace("Drow");
	}
	else if ( race == "v" ) {
		player = new Vampire();
		setRace("Vampire");
	}
	else if ( race == "t" ) {
		player = new Troll();
		setRace("Troll");
	}
	else if ( race == "g" ) {
		player = new Goblin();
		setRace("Goblin");
	}
	player->setFloor(floors[floorNum]);
	floors[floorNum]->setPlayer(player);
	floors[floorNum]->notify();
	notify("PC has spawned!");
}

void Game::attack( string dir ) {
	player->attack(dir);
}

void Game::move( string dir ) {
	player->move(dir);
}

void Game::use( string dir ) {
	#ifdef DEBUG
	cout << "Use " << dir << endl;
	#endif
	player->useItem(dir);
}

void Game::setRace( string race ) {
	notification->setRace(race);
}

void Game::notify( int r, int c, char ch ) {
	notification->notify(r,c,ch);
}

void Game::notify( string action ) {
	notification->notify(action);
}

void Game::notify( string stat, int newStat ) {
	notification->notify(stat,newStat);
}

void Game::advanceFloor(){
	floorNum++;
	if ( floorNum == 6 ) {
		endGame();
		return;
	}
	floors[floorNum]->notify();
	notify( "floor", floorNum+1 );
	floors[floorNum]->setPlayer(player);
}

void Game::enemyMove(){
	floors[floorNum]->enemyMove();
}
