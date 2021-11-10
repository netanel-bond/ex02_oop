
#include "Board.h"
#include "King.h"
#include <string>

class GameController
{
public:
	GameController(string fileName);


private:

	Board m_board;
	King m_king;
	char m_pc[4] = { 'K', 'M', 'W', 'T' };

	void run_game();

};