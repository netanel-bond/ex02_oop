
#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Board {
public:

	Board(string fileName);

	void printBoard() const;
	void delete_figure(const int col, const int row);
	void add_object(const int col, const int row);

	int get_size() const;
	vector<string> get_board() const;
	vector<int*> get_teleport()const;

private:
	void find_tele_tile();
	vector<string> m_board;

	int m_boardSize;
	vector<int*> m_teleport;
};