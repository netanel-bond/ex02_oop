#pragma once

#include "Location.h"

class Board;

class Thief {

public:
	Thief(Board& board);
	Thief() = delete;

	bool move(Board& board, bool& p_pressed, bool& esc_pressed);
	void print()const;
	bool has_key()const;
private:
	Location m_loc;
	bool m_has_key = false;
	void move_to_tele(Board board, Location new_loc);

	//		return false if location is not within board borders
	bool check_border(const Board& board, const Location& loc);
};