
#include <string>
#include <vector>

using std::string;
using std::vector;

class Board {
public:

	Board(string fileName);
	void printBoard();
	void delete_figure(const int col, const int row);
	void add_object(const int col, const int row);

	int get_size() const;
	vector<string> get_board() const;


private:

	vector<string> m_board;

	//vector<vector<int>> m_teleArray;

	int m_boardSize;
};