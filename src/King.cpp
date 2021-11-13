

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
	const int board_size = board.get_size();
	bool is_found = false;

//		searches where the object appears on board
	for (int row_index = 0; row_index < board_size + 1; row_index++)
	{
		for (int col_index = 1; col_index < board_size * 2; col_index += 2)
		{
//				when found store coordinates and delete it from the board
			if (currBoard[row_index][col_index] == 'K')
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
bool King::move(const Board& board, bool& p_pressed, bool& esc_pressed)
{
//		get input from user
	char key_input_ch = getch();
	//cout << key_input;
	if (key_input_ch == 'p' || key_input_ch == 'P')
	{
		p_pressed = true;
		return false;
	}

	if (key_input_ch == KB_Escape)
	{
		esc_pressed = true;
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
	case '@':
		// end game
		m_loc = new_loc;
		m_is_won = true;
		break;

	case ' ':
	case 'F':
		m_loc = new_loc;
		break;

	case 'X':
//			call function to move object through teleporter
		move_to_tele(board,new_loc);
		break;

	default:
		return false;
		break;
	}

	return true;

}
void King::move_to_tele(Board board, Location new_loc)
{
	vector<int*> tele_board = board.get_teleport();
	int tele_index = tele_board[new_loc.row][new_loc.col];

	for (int i = 0; i < board.get_size(); i++)
	{
		for (int j= 1; j < board.get_size() * 2; j += 2)
		{
			if (tele_board[i][j] == tele_index)
			{
				if (i == new_loc.row && j == new_loc.col)
					continue;
				m_loc.row = i;
				m_loc.col = j;
			}
		}
	}
}

//  returns true if location is within borders of board
bool King::check_border(const Board& board, const Location& loc)
{
	int board_size = board.get_size();

	return (loc.col > 0 && loc.col < board_size * 2 + 1 &&
			loc.row > -1 && loc.row < board_size + 1);
}

//	returns true if won the game
bool King::get_win_status() const
{
	return m_is_won;
}

//	the object prints itself to console on its location
void King::print() const
{
	Screen::setLocation(m_loc);
	cout << 'K';
}