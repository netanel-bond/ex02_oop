
#pragma once

#include "Location.h"

class Board;

class King {

public:

	King(Board& board);

	bool move(const Board& board, bool &p_preesed);	//moves the object and returns true if move successful 


private:
	Location m_loc;
	void arrowKeyHandler();
	void move(const Board& board, int new_col, int new_row);
	bool check_border(const Board& board, int new_col);

};