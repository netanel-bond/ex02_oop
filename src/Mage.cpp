

#include "keyValues.h"
#include "Mage.h"
#include "Board.h"
#include "io.h"
#include <iostream>
#include <conio.h>

using std::cout;

Mage::Mage(Board& board)
	: m_loc(0, 0)
{

	const vector<string> currBoard = board.get_board();
	const int board_size = board.get_size();
	bool is_found = false;

	//		searches where the object appears on board
	for (int row_index = 0; row_index < board_size; row_index++)
	{
		for (int col_index = 1; col_index < board_size; col_index += 2)
		{
			//				when found store coordinates and delete it from the board
			if (currBoard[row_index][col_index] == 'M')
			{
				m_loc.row = row_index;
				m_loc.col = col_index;
				board.delete_figure(row_index, col_index);

				is_found = true;
			}

			if (is_found)
				break;
		}

		if (is_found)
			break;

	}

}

//	return true if king was able to move
bool Mage::move( Board& board, bool& p_preesed)
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

	//		create new location according to current location + offset
	Location new_loc(m_loc.row + row_offset, m_loc.col + col_offset);

	//		if the new location is not within borders exit
	if (!(check_border(board, new_loc)))
		return false;

	char tile = currBoard[new_loc.row][new_loc.col];
	//		check new location's tile char to determine what action does the object do
	switch (tile)
	{
	case '*':
		// end game
		m_loc = new_loc;
		board.delete_figure(m_loc.col, m_loc.row);
		break;

	case ' ':
	case 'F':
		m_loc = new_loc;
		break;

	case 'X':
		//call function to teleport
		break;

	default:
		break;
	}

	return true;

}

bool Mage::check_border(const Board& board, int index)
{
	return (index < 1 || index > board.get_size() + 1);
}




void print(const struct Location curr_loc)
{
	Screen::setLocation(curr_loc);
	cout << 'M';
}