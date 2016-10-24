#include "Board.h"

Board::Board() {}

void Board::input(const char& letter)
{
	int location;
	bool inserted = false;
	while (!inserted)
	{
		cout << "Enter a location using the numpad: ";
		cin >> location;
		if (location >= 1 && location <= 9)
		{
			if (bArray[location - 1] == ' ')
			{
				location--;
				bArray[location] = letter;
				inserted = true;
			}
			else
			{
				cout << "This spot has already been played, try again" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		else
		{
			cout << "Please select a valid space using the numpad" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void Board::print() const
{
	system("clear");
	cout << endl;
	cout << ' ' << bArray[6] << " | " << bArray[7] << " | " << bArray[8] << endl;
	cout << "---+---+---" << endl;
	cout << ' ' << bArray[3] << " | " << bArray[4] << " | " << bArray[5] << endl;
	cout << "---+---+---" << endl;
	cout << ' ' << bArray[0] << " | " << bArray[1] << " | " << bArray[2] << endl << endl;
}

bool Board::isFull() const
{
	bool full = true;
	for (char x : bArray)
	{
		if (x == ' ')
			full = false;
	}
	return full;
}

bool Board::hasWon() const
{
	bool winner = false;
	if (bArray[0] == bArray[1] && bArray[1] == bArray[2] && bArray[0] != ' ')
		winner = true;
	else if (bArray[3] == bArray[4] && bArray[4] == bArray[5] && bArray[5] != ' ')
		winner = true;
	else if (bArray[6] == bArray[7] && bArray[7] == bArray[8] && bArray[8] != ' ')
		winner = true;
	else if (bArray[0] == bArray[3] && bArray[3] == bArray[6] && bArray[6] != ' ')
		winner = true;
	else if (bArray[1] == bArray[4] && bArray[4] == bArray[7] && bArray[7] != ' ')
		winner = true;
	else if (bArray[2] == bArray[5] && bArray[5] == bArray[8] && bArray[8] != ' ')
		winner = true;
	else if (bArray[0] == bArray[4] && bArray[4] == bArray[8] && bArray[8] != ' ')
		winner = true;
	else if (bArray[2] == bArray[4] && bArray[4] == bArray[6] && bArray[6] != ' ')
		winner = true;
	return winner;
}

void Board::turn(const char& letter)
{
	bool inserted = false;
	usleep(750000);
	while (!inserted)
	{
		int location = rand() % 9;
		if (bArray[location] == ' ')
		{
			bArray[location] = letter;
			inserted = true;
		}
	}
}
