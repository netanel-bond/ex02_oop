
#include "GameController.h"
#include "io.h"

#include <iostream>
#include <conio.h>
#include <cstdlib>

using std::cout;
using std::endl;



GameController::GameController(string fileName)
	:m_board(fileName), m_king(m_board),m_mage(m_board)
{
	
	run_game();

}


void GameController::run_game()
{
	char curr_player = m_pc[0];
	int player_index = 0, num_of_moves=0;
	char key_input;

	m_board.printBoard();
	cout << "curr player: " << curr_player <<endl ;
	cout <<"num of moves: "<< num_of_moves;

	m_king.print();
	m_mage.print();

	
	while (true)
	{
		bool is_moved = true, p_pressed = false;

	
//			stores false if pc was not moved
	

		switch (curr_player)
		{

		case 'K':
			is_moved = m_king.move(m_board, p_pressed);

			break;
		case 'M':
			//cout << "test";
			is_moved = m_mage.move(m_board, p_pressed);
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
			num_of_moves++;
			m_board.printBoard();
			cout << "curr player: " << curr_player << endl;
			cout << "num of moves: " << num_of_moves;
			m_king.print();
			m_mage.print();
		}
		else
		{
			if (p_pressed)
			{
				if (player_index >= 4)
					player_index = 0;

				player_index++;
				curr_player = m_pc[player_index];

				system("cls");
				m_board.printBoard();
				cout << "curr player: " << curr_player << endl;
				cout << "num of moves: " << num_of_moves;
				m_king.print();
				m_mage.print();
			
			}
		}
		

//			if won game exit game
		if (m_king.get_win_status())
		{
			cout << "Hurray! The kingdom is saved!" << endl;
			return;
		}
	}
}