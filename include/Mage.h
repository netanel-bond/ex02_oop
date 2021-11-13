#pragma once

#include "Location.h"

class Board;

class Mage {

public:
	Mage(Board& board);
	Mage() = delete;

	bool move(Board& board, bool& p_pressed, bool& esc_pressed);
	void print()const;

private:
	Location m_loc;
	bool m_is_on_fire = false;

	//		return false if location is not within board borders
	bool check_border(const Board& board, const Location& loc);
};