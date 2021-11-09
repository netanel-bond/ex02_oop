
#include <string>
#include <vector>

using std::string;
using std::vector;

class Board {
public:
	Board();
	void printBoard();

	int get_size() const;
	vector<string> get_board() const;

private:

	vector<string> m_board;

	int m_boardSize;
};