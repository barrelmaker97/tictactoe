// Tic Tac Toe
// By Nolan Cooper

#include "Board.h"

void titleDisplay();

int main()
{
	srand(time(0));
	Board board1;
	int playerNum;
	bool done = false;
	titleDisplay();
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
			cout << "Try again" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	return 0;
}

void titleDisplay()
{
	system("clear");
	cout << "        88" << endl;
	cout << "  ,d    \"\"              ,d                            ,d" << endl;
	cout << "  88                    88                            88" << endl;
	cout << "MM88MMM 88  ,adPPYba, MM88MMM ,adPPYYba,  ,adPPYba, MM88MMM ,adPPYba,   ,adPPYba," << endl;
	cout << "  88    88 a8\"     \"\"   88    \"\"     `Y8 a8\"     \"\"   88   a8\"     \"8a a8P_____88" << endl;
	cout << "  88    88 8b           88    ,adPPPPP88 8b           88   8b       d8 8PP\"\"\"\"\"\"\"" << endl;
	cout << "  88,   88 \"8a,   ,aa   88,   88,    ,88 \"8a,   ,aa   88,  \"8a,   ,a8\" \"8b,   ,aa" << endl;
	cout << "  \"Y888 88  `\"Ybbd8\"'   \"Y888 `\"8bbdP\"Y8  `\"Ybbd8\"'   \"Y888 `\"YbbdP\"'   `\"Ybbd8\"'" << endl << endl;
}
