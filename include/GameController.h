
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

	Board m_board;
	King m_king;
	Mage m_mage;
	Thief m_thief;

	Warrior m_warrior;
	const char m_pc[4] = { 'K', 'M', 'W', 'T' };

};