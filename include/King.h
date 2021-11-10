
#pragma once

#include "Location.h"

class Board;

class King {

public:

	King(Board& board);

	void move(Board& board);


private:
	Location m_loc;
	void arrowKeyHandler();
	void move(const Board& board, int new_col, int new_row);
	bool check_border(const Board& board, int new_col);

};