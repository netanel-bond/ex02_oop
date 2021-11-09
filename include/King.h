
#pragma once

#include "Location.h"

class Board;

class King {

public:

	King(const Board& board);

	void move(Board& board);



private:
	Location m_loc;
	check_tile()
};