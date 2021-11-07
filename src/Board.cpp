

#include "Board.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::getline;
using std::cout;

Board::Board() 
{
    ifstream inputFile;

    inputFile.open("Board.txt");
    
    string line;

    inputFile >> m_boardSize;

    int i = 0;
    while (getline(inputFile, line))
    {
        m_board.push_back(line);
    }
}

void Board::printBoard()
{
    for (int i = 0; i < m_boardSize; i++)
        cout << m_board[i];

}