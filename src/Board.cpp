

#include "Board.h"
#include <iostream>

using std::cout;

void Board::printBoard()
{
    cout << " ";
    char letter = 'A';
    for (int i = 0; i < m_boardSize; i++)
    {
        cout << "   " << letter;
        letter++;
    }

    cout << '\n';
    for (int rowNum = 1; rowNum < m_boardSize + 1; rowNum++) { // row index
        cout << "  ";
        printRow();
        cout << '\n';
        if (rowNum >= 10)
            cout << rowNum;
        else
            cout << rowNum << " ";

        for (int columnNum = 1; columnNum < m_boardSize + 1; columnNum++) { // col index
            cout << "| " << " " << " ";       // here add the appropriate icons (king etc)
        }
        cout << "|\n";
    }

    cout << "  ";
    printRow();
}

void Board::printRow()
{
    for (int j = 0; j < m_boardSize; j++) {
        cout << "----";
    }
    cout << "-";
}