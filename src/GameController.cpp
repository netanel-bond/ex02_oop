
#include "GameController.h"
#include "io.h"

#include <iostream>
#include <conio.h>
#include <cstdlib>

using std::cout;
using std::endl;



GameController::GameController(string fileName)
	:m_board(fileName), m_king(m_board)
{
	
	run_game();

}


void GameController::run_game()
{

	m_board.printBoard();
	m_king.print();

	char curr_player = m_pc[0];
	int player_index = 0;
	char key_input;

	while (true)
	{

		//key_input = _getch();

		//if (key_input == 'p' || key_input == 'P')
		//{
		//	if (player_index >= 4)
		//		player_index = 0;

		//	player_index++;
		//	curr_player = m_pc[player_index];

		//	key_input = _getch();
		//}

//			stores false if pc was not moved
		bool is_moved = true;

		switch (curr_player)
		{

		case 'K':
			is_moved = m_king.move(m_board);

			break;
		case 'M':
			//start Mage class
			break;
		case 'W':
			//start Warrior class
			break;
		case 'T':
			//start Thief class
			break;


		default:
			break;
		}

//			if object moved delete console and print from scratch
		if (is_moved)
		{
			system("cls");

			m_board.printBoard();
			m_king.print();
		}

//			if won game exit game
		if (m_king.get_win_status())
		{
			cout << "Hurray! The kingdom is saved!" << endl;
			return;
		}
	}
}