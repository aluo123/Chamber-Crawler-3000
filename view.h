#ifndef __VIEW_H__
#define __VIEW_H__
#include <string>
#include <map>

class View {
	const int gridWidth, gridLength;
	std::map<std::string, int> stats;
	std::string race;
	std::string action;
public:
	View( int gw, int gl );
	virtual ~View();
	void setRace( std::string race );
	virtual void notify( int r, int c, char ch );
	virtual void notify( std::string action );
	virtual void notify( std::string stat, int newStat );
	virtual void print() = 0;
};
#endif
