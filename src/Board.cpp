#include "Board.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::getline;
using std::cout;
using std::endl;
using std::cin;


Board::Board(string fileName)
{
    ifstream inputFile;

    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        cout << "file failed to open" << endl;
        EXIT_FAILURE;
    }
    
    string line;

    inputFile >> m_boardSize;       //stores board size from file input

    inputFile.ignore();

//      stores the board from file input
    while (getline(inputFile, line))
    {
        m_board.push_back(line);
    }
}

//  delete object char from board
void Board::delete_figure(const int row, const int col)
{
    m_board[row][col] = ' ';
}
void Board::add_object(const int row, const int col)
{
    m_board[row][col] = 'F';
}

void Board::printBoard()    //add const
{
    for (int i = 0; i < m_boardSize + 2; i++)
        cout << m_board[i] << endl;

}

int Board::get_size() const
{
    return m_boardSize;
}

vector <string> Board::get_board() const
{
    return m_board;
}