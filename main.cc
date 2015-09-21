#include "controller.h"
#include <sstream>

int main( int argc, char* argv[] ) {
	Controller c;
	if ( argc > 1 ) {
		c.setfstream(argv[1]);
	}
	if ( argc > 2 ) {
		c.setSeed(argv[2]);
	}
	c.play();
}
