#include "textdisplay.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

//asdfsadf
TextDisplay::TextDisplay( int gw, int gl, std::string race ): View(gw, gl, race) {
	theDisplay = new char*[gridWidth];
	for ( int i = 0; i < gridWidth; i++ ) {
		theDisplay[i] = new char[gridLength];
	}
	for ( int x = 0; x < gridWidth; x++ ) {
		for ( int y = 0; y < gridLength; y++ ) {
			theDisplay[x][y] = ' ';
		}
	}
}

TextDisplay::~TextDisplay() {
	for ( int i = 0; i < gridWidth; i++ ) {
		delete[] theDisplay[i];
	}
	delete theDisplay;
}

void TextDisplay::notify( int r, int c, char ch ) {
	theDisplay[r][c] = ch;
}

void TextDisplay::printBoard() {
	for ( int i = 0; i < gridWidth; i++ ) {
		for ( int j = 0; j < gridLength; j++ ) {
			std::cout << theDisplay[i][j];
		}
		std::cout << std::endl;
	}
}

void TextDisplay::printStats() {
	std::stringstream ss;
	ss << "Race: " << race << " Gold: " << gold;
	std::cout << std::setw(gridLength - 10) << std::left << ss.str();
	std::cout << "Floor " << stats["floor"] << std::endl;
	std::cout << "HP: " << stats["hp"] << std::endl;
	std::cout << "Atk: " << stats["atk"] << std::endl;
	std::cout << "Def: " << stats["def"] << std::endl;
	std::cout << "Action: " << action << std::endl;
}

void TextDisplay::print() {
	printBoard();
	printStats();
}
