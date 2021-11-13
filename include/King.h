
#pragma once

#include "Location.h"

class Board;

class King {

public:

	King(Board& board);		//c-tor
	King() = delete;

	bool move(const Board& board, bool & p_pressed);	//moves the object and returns true if move successful 

	bool get_win_status() const;	//returns true if game is won
	
	void print() const;				//prints itself according to its location

private:
	void move_to_tele(Board board,Location new_loc);
	Location m_loc;					//its location (row/col as y/x coordinates)

	bool m_is_won = false;			//stores true if game is won

//		return false if location is not within board borders
	bool check_border(const Board& board, const Location& loc);

};