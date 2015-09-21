#include "shade.h"
#include <string>

Shade::Shade():Player(125,25,25){}

Shade::~Shade(){}

std::string Shade::raceType(){
	return "Shade";
}
