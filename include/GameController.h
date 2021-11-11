
#include "Board.h"
#include "King.h"
#include <string>

class GameController
{
public:
	GameController(string fileName);

	void run_game();

private:

	Board m_board;
	King m_king;
	const char m_pc[4] = { 'K', 'M', 'W', 'T' };

};