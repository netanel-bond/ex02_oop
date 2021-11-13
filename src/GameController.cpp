
#include "GameController.h"
#include "io.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using std::cout;
using std::endl;



GameController::GameController(string fileName)
	:m_board(fileName), m_king(m_board), m_mage(m_board),
	m_warrior(m_board), m_thief(m_board)
{
	run_game();
}


void GameController::run_game()
{
	char curr_player = m_pc_arr[0];
	int player_index = 0, num_of_moves=0;

	print_board(curr_player);
	print_info(curr_player, num_of_moves);

	bool is_moved, p_pressed, esc_pressed;
	
	while (true)
	{
//			stores false if pc was not moved
		is_moved = false;
		p_pressed = false;
		esc_pressed = false;

		switch (curr_player)
		{

		case 'K':
			is_moved = m_king.move(m_board, p_pressed, esc_pressed);
			break;

		case 'M':
			is_moved = m_mage.move(m_board, p_pressed, esc_pressed);
			break;

		case 'W':
			is_moved = m_warrior.move(m_board, p_pressed, esc_pressed);
			break;

		case 'T':
			is_moved = m_thief.move(m_board, p_pressed, esc_pressed);
			break;

		default:
			break;
		}


		
//			if object moved delete console and print from scratch
		if (is_moved)
		{
			num_of_moves++;
			print_board(curr_player);
			print_info(curr_player, num_of_moves);
		}

		else if (p_pressed)
		{
			if (player_index >= 3)
				player_index = -1;		//in order to get to 0 (K)

			player_index++;
			curr_player = m_pc_arr[player_index];

			print_board(curr_player);
			print_info(curr_player, num_of_moves);
		}

		else if (esc_pressed)
			return;

//			if won game exit game
		if (m_king.get_win_status())
		{
			print_win_msg();
			return;
		}
	}
}

void GameController::print_win_msg() const
{
	Screen::setLocation(Location(m_board.get_size() / 2, m_board.get_size() * 2 + 5));
	cout << "Hurray! The kingdom is saved!" << endl;
	Screen::setLocation(Location(m_board.get_size() / 2 + 1, m_board.get_size() * 2 + 5));
	cout << "Press any key to continue..." << endl;
	_getch();
}

void GameController::print_board(const char curr_player) const
{
	system("cls");
	m_board.printBoard();

	print_all_pc(curr_player);
}

void GameController::print_all_pc(const char curr_player) const
{
	int num_of_pc = sizeof(m_pc_arr);
	for (int i = 0; i < num_of_pc; i++)
	{
		if (m_pc_arr[i] != curr_player)
			print_pc(m_pc_arr[i]);
	}

	print_pc(curr_player);
}

void GameController::print_pc(const char c_pc) const
{
	switch (c_pc)
	{

	case 'K':
		m_king.print();
		break;

	case 'M':
		m_mage.print();
		break;

	case 'W':
		m_warrior.print();
		break;

	case 'T':
		m_thief.print();
		break;

	default:
		break;
	}
}

void GameController::print_info(const char curr_player, const int num_of_moves) const
{

	Screen::setLocation(Location(m_board.get_size() + 2, 0));

	cout << "Current Player: " << curr_player << endl;
	cout << "Number of moves: " << num_of_moves << endl;
	if (m_thief.has_key())
		cout << "Thief equipped the key" << endl;
	else
		cout << "Thief doesn't have key" << endl;
}

