#include "view.h"
#include <iostream>

View::View( int gw, int gl ): gridWidth(gw), gridLength(gl) {}

View::~View(){}

void View::setRace( std::string race ) {
	std::cout << "HI" << std::endl;
	this->race = race;
}

void View::notify( std::string action ) {
	this->action = action;
}

void View::notify( std::string stat, int newStat ) {
	stats[stat] = newStat;
}
