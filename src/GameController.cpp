
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


		switch (c)
		{

		case 'p':
		case 'P':
			if (curr_player == '')


		default:
			break;
		}


	}


}


