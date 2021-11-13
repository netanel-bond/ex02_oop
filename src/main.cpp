
#include "GameController.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


//	PROTOTYPES
void start_game(const string);

int main()
{

	start_game("Board_1.txt");

	start_game("Board_2.txt");

	start_game("Board_3.txt");

	cout << "Thank you for playing the beta, the final release will be out in the upcoming month!" << endl;

	return 0;
}

//	function to start the game
void start_game(const string fileName)
{
	GameController gameController(fileName);

	system("cls");
}