
#pragma once

#include "Board.h"
#include "King.h"
#include <string>
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

class GameController
{
public:
	GameController(string fileName);

	void run_game();

private:

//		members
	Board m_board;
	King m_king;
	Mage m_mage;
	Thief m_thief;
	Warrior m_warrior;
	const char m_pc_arr[4] = { 'K', 'M', 'W', 'T' };

//		helper functions
	void print_info(const char curr_player, const int num_of_moves) const;
	void print_board(const char curr_player) const;
	void print_win_msg() const;
	void print_pc(const char curr_player) const;
	void print_all_pc(const char curr_player) const;


};