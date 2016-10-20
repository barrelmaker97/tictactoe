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
		void input(char);
		void print();
		bool isFull();
		bool hasWon();
		void turn(char);
};

#endif
