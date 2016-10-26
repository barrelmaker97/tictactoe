// Tic Tac Toe
// By Nolan Cooper

#include "Board.h"

void displayArt(const string&);
string getFileContents(ifstream&);

int main()
{
	bool replay = true;
	while(replay)
	{
		replay = false;
		srand(time(0));
		Board board1;
		int playerNum;
		bool done = false;
		system("clear");
		displayArt("art.txt");
		while (!done)
		{
			cout << "How many players? ";
			cin >> playerNum;
			if (playerNum == 0)
			{
				char letter;
				bool toggle = true;
				while (!board1.isFull() and !board1.hasWon())
				{
					letter = (toggle)?'X':'O';
					board1.turn(letter);
					board1.print();
					toggle = !toggle;
				}
				cout << "GAME OVER" << endl;
				if (board1.hasWon())
					cout << "Letter " << letter << " wins!" << endl;
				else
					cout << "Draw!" << endl;
				done = true;
			}
			else if (playerNum == 1)
			{
				char choice;
				char winner = 'O';
				bool chosen = false;
				while (!chosen)
				{
					cout << "Would you like to play as X or O? ";
					cin >> choice;
					if (choice == 'x' or choice == 'X')
					{
						chosen = true;
						system("clear");
						displayArt("example.txt");
						while (!board1.isFull() and !board1.hasWon())
						{
							board1.input('X');
							board1.print();
							if (board1.isFull() or board1.hasWon())
							{
								winner = 'X';
								break;
							}
							board1.turn('O');
							board1.print();
						}
					}
					else if (choice == 'o' or choice == 'O')
					{
						chosen = true;
						system("clear");
						displayArt("example.txt");
						while (!board1.isFull() and !board1.hasWon())
						{
							board1.turn('X');
							board1.print();
							if (board1.isFull() or board1.hasWon())
							{
								winner = 'X';
								break;
							}
							board1.input('O');
							board1.print();
						}
					}
					else
					{
						cout << "Please select a valid letter (X/O): " << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
				cout << "GAME OVER" << endl;
				if (board1.hasWon())
				{
					cout << "Letter " << winner << " has won!" << endl;
				}
				else
					cout << "Draw!" << endl;
				done = true;
			}
			else if (playerNum == 2)
			{
				bool toggle = true;
				char letter;
				cout << endl;
				system("clear");
				displayArt("example.txt");
				while (!board1.isFull() and !board1.hasWon())
				{
					letter = (toggle)?'X':'O';
					board1.input(letter);
					board1.print();
					toggle = !toggle;
				}
				cout << "GAME OVER" << endl;
				if (board1.hasWon())
					cout << "Letter " << letter << " wins!" << endl;
				else
					cout << "Draw!" << endl;
				done = true;
			}
			else
			{
				cout << "Please select a number from 0-2" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		
		char decision;
		cout << endl << "Would you like to play again? (Y for yes, any other key for no): ";
		cin >> decision;

		if (tolower(decision) == 'y')
			replay = true;
	}
	return 0;
}

void displayArt(const string& filename)
{
	ifstream reader(filename);
	string art = getFileContents(reader);
	cout << art;
	reader.close();
}

string getFileContents(ifstream& file)
{
	string lines = "";
	if (file)
	{
		while (file.good())
		{
			string temp;
			getline(file,temp);
			temp += "\n";
			lines += temp;
		}
		return lines;
	}
	else
		return "ERROR: ASCII art file is missing";
}
