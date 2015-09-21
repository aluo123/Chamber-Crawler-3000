#include "stairs.h"
#include "floor.h"

std::string Stairs::characType() {
	return "Stairs";
}

std::string Stairs::raceType() {
	return "Stairs";
}

void Stairs::notify() {
	f->notify(row, col, '\\');
}

void Stairs::die(Character* killer){}
