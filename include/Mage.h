#pragma once

#include "Location.h"

class Board;

class Mage {


	Mage(Board& board);
	Mage() = delete;

	bool move( Board& board, bool& p_pressed);
	bool put_out_fire() const;
	void print() const;

private:
	Location m_loc;
	bool m_is_on_fire = false;

	//		return false if location is not within board borders
	bool check_border(const Board& board, const Location& loc);
};