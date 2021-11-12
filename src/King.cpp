

#include "keyValues.h"
#include "King.h"
#include "Board.h"
#include "io.h"
#include <iostream>
#include <conio.h>


using std::cout;

King::King(Board& board)
	: m_loc(0 ,0)
{

	const vector<string> currBoard = board.get_board();

	for (int i = 0; i < board.get_size(); i++)
		for (int k = 0; k < board.get_size(); k++)
		{
			if (currBoard[i][k] == 'K')
			{
				m_loc.row = i;
				m_loc.col = k;
                board.delete_figure(i, k);
			}
		}
}

}

//	return true if king was able to move
bool King::move(const Board& board, bool &p_preesed)
{
//		get input from user
	char key_input_ch = _getch();
	//cout << key_input;
	if (key_input_ch == 'p' || key_input_ch == 'P')
	{
		p_preesed = true;
		return false;
	}
	auto key_input = _getch();
	
	int col_offset = 0, row_offset = 0;
//		set the coordinate offset according to the input
	switch (key_input)
	{
	case KB_Up:
		row_offset = -1;
		break;
	case KB_Down:
		row_offset = 1;
		break;
	case KB_Left:
		col_offset = -2;
		break;
	case KB_Right:
		col_offset = 2;
		break;

	default:
		break;
	}

    vector <string> currBoard = board.get_board();

    if (!(check_border(board, new_col) && check_border(board, new_row)))
        return;

    char tile = currBoard[new_col][new_row];

    switch (tile)
    {
    case '@':
        // end game
        break;

    case ' ':

    case 'F':
        m_loc.col = new_col;
        m_loc.row = new_row;
        break;

    case 'X':
        //call function to teleport
        break;

    default:
        break;
    }


}

bool King::check_border(const Board& board, int index)
{
    return (index < 1 || index > board.get_size() + 1);
}

void King::arrowKeyHandler()
{
    auto c = _getch();
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
}


void print(const struct Location curr_loc)
{
    Screen::setLocation(curr_loc);
    cout << 'K';
}