#include "Board.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::getline;
using std::cout;
using std::endl;
using std::cin;


Board::Board() 
{
    ifstream inputFile;

    inputFile.open("Board.txt");

    if (!inputFile.is_open())
    {
        cout << "file failed to open" << endl;
        EXIT_FAILURE;
    }
    
    string line;

    inputFile >> m_boardSize;

    inputFile.ignore();

    while (getline(inputFile, line))
    {
        m_board.push_back(line);
    }
}

void Board::printBoard()
{
    for (int i = 0; i < m_boardSize; i++)
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