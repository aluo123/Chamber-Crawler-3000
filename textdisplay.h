#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <string>
#include <map>

class TextDisplay{
	const int gridWidth, gridLength;
	int floor;
	std::map<std::string, int> stats;
	std::string race;
	std::string action;
	char **theDisplay;
	void printBoard();
	void printStats();
	
public:
	TextDisplay( int gw, int gl );
	~TextDisplay();
	void setRace( std::string race );
	void notify( int r, int c, char ch );
	void notify( std::string action );
	void notify( std::string stat, int newStat );
	void notify( int floor );
	void print();
};
#endif
