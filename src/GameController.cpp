
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


		switch (curr_player)
		{

		case 'K':
			//start king class
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




	}


}


