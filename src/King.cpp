

#include "King.h"
#include "Board.h"
#include <iostream>
#include <conio.h>


using std::cout;

enum SpecialKeys
{
	KB_Up = 72,
	KB_Down = 80,
	KB_Left = 75,
	KB_Right = 77,
};

King::King(const Board& board)
{

	const vector<string> currBoard = board.get_board();

	for (int i = 0; i < board.get_size(); i++)
		for (int k = 0; k < board.get_size(); k++)
		{
			if (currBoard[i][k] == 'K')
			{
				m_loc.m_row = i;
				m_loc.m_col = k;
				return;
			}
		}
}

void King::move(Board& board)
{
    auto c = getch();
    switch (c)
    {
    case KB_Up:
        std::cout << "Arrow Up pressed\n";
        break;
    case KB_Down:
        std::cout << "Arrow Down pressed\n";
        break;
    case KB_Left:
        std::cout << "Arrow Left pressed\n";
        break;
    case KB_Right:
        std::cout << "Arrow Right pressed\n";
        break;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        break;
    }

    if (check_tile(const Board& board, const SpecialKeys key))
}