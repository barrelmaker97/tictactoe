#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

class Board
{
	private:
		char bArray[9] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	public:
		Board();
		void input(const char&);
		void print() const;
		bool isFull() const;
		bool hasWon() const;
		void turn(const char&);
};

#endif
