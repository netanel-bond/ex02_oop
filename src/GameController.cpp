
#include "GameController.h"
#include "io.h"

#include <iostream>
#include <conio.h>

using std::cout;



GameController::GameController(string fileName)
	:m_board(fileName), m_king(m_board)
{
	
	run_game();

}


void GameController::run_game()
{


	while (true)
	{

		char c = _getch();
		char curr_player = m_pc[0];
		int  i = 1;
		if (c == 'p')
		{
			if (i >= 4)
				i = 0;

			curr_player = m_pc[i];
			i++;
		}


	m_board.printBoard();
	m_king.print();

	char curr_player = m_pc[0];
	int player_index = 0;
	char key_input=NULL;
	
	while (true)
	{

			

//			stores false if pc was not moved
		bool is_moved = true, p_pressed = false;


		switch (curr_player)
		{

		case 'K':
			//start king class

			is_moved = m_king.move(m_board ,p_pressed);

			break;
		case 'M':
			cout << "test M ";
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


			m_board.printBoard();
			m_king.print();
		}
		else
		{
			if (p_pressed)
			{
				if (player_index >= 4)
					player_index = 0;

				player_index++;
				curr_player = m_pc[player_index];
			}
		}

//			if won game exit game
		if (m_king.get_win_status())
		{
			cout << "Hurray! The kingdom is saved!" << endl;
			return;
		}

		/*key_input = _getch();

		if (key_input == 'p' || key_input == 'P')
		{
			if (player_index >= 4)
				player_index = 0;

			player_index++;
			curr_player = m_pc[player_index];

			key_input = _getch();
		}
		*/

	}


}


