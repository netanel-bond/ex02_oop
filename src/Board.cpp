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
        exit(EXIT_FAILURE);
    }
    
    string line;

    inputFile >> m_boardSize;       //stores board size from file input

    int* array = new int [m_boardSize * 2];

    for (int i = 0; i < m_boardSize; i++)
    {
        m_teleport.push_back(array);
    }


    inputFile.ignore();

//      stores the board from file input
    while (getline(inputFile, line))
    {
        m_board.push_back(line);
    }
    find_tele_tile();
}

void Board::find_tele_tile()
{
    int tele_index = 1, count_pair = 0;
    //		searches where the object appears on board
    for (int row_index = 0; row_index < m_boardSize; row_index++)
    {
        for (int col_index = 1; col_index < m_boardSize * 2; col_index += 2)
        {
            m_teleport[row_index][col_index] = 0;

            if (m_board[row_index][col_index] == 'X')
            {
                if (count_pair == 2)
                {
                    tele_index++;
                    count_pair = 0;
                }

                m_teleport[row_index][col_index] = tele_index ;
                count_pair++;

            }
           
            
        }

        
    }
}

vector<int*> Board::get_teleport() const
{
    return m_teleport;
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

void Board::printBoard() const
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