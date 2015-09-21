#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <string>
#include "view.h"

class TextDisplay: public View {
	char **theDisplay;
	void printBoard();
	void printStats();
public:
	TextDisplay( int gw, int gl, std::string race );
	~TextDisplay();
	virtual void notify( int r, int c, char ch );
	void print();
};
#endif
