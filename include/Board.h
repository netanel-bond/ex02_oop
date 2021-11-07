
#include <string>
#include <vector>

using std::string;
using std::vector;

class Board {
public:
	Board();
	void printBoard();
private:

	vector<string> m_board;
	int m_boardSize = 0;
};