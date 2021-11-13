
#pragma once

#include "Location.h"

class Board;

class Warrior {

public:
	Warrior(Board& board);
	Warrior() = delete;

	
	bool move(Board& board, bool& p_pressed, bool& esc_pressed);
	void print()const;

private:
	Location m_loc;
	bool m_is_on_fire = false;

	void move_to_tele(Board board, Location new_loc);

	//		return false if location is not within board borders
	bool check_border(const Board& board, const Location& loc);
};