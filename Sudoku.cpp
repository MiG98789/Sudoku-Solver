/*
 * Sudoku.cpp
 *
 *  Created on: 8 Sep 2016
 *      Author: Gian Miguel
 */

#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(int grid[])	//Constructor
{
    for(int i = 0; i < 81; i++)
    {
        Sudoku::grid[i / 9][i % 9] = grid[i];
        Sudoku::buffer[i / 9][i % 9] = grid[i];
    }

    solved = 0;
}

void Sudoku::printGrid()	//Display the grid
{
    for(int i = 0; i < 81; i++)
    {
        cout << Sudoku::buffer[i / 9][i % 9];

        if(i % 3 == 2 && i % 9 != 8)
        {
            cout << '|';
        }

        if(i % 9 == 8)
        {
            cout << endl;
        }

        if((i / 10) % 3 == 2 && i % 9 == 8 && i != 80)
        {
            cout << "---+---+---" << endl;
        }
    }
}

void Sudoku::solveGrid()	//Calls recursiveSolve()
{
    recursiveSolve(Sudoku::grid, Sudoku::buffer);
}

bool Sudoku::recursiveSolve(int grid[][9], int buffer[][9]) //Recursively solves the grid
{
    //---Base case: Sudoku is solved---//
    for(int i = 0; i < 81; i++)
    {
        int count = 0;
        if(grid[i / 9][i % 9] != 0)
        {
            count++;
        }

        if(count == 81)
        {
            return true;
        }
    }

    //---Recursive case---//
    for(int i = 0; i < 81; i++)
    {
        int currentRow = i / 9;
        int currentColumn = i % 9;

        if(grid[currentRow][currentColumn] == 0)
        {

            for(int j = 1; j <= 9; j++)
            {
                if(checkPlacement(currentRow, currentColumn, j))
                {
                    cout << "Trying " << j << " at " << currentRow << ", " << currentColumn << endl;

                    buffer[currentRow][currentColumn] = j;
                    recursiveSolve(grid, buffer);
                }
            }
        }
    }

    return false;
}

bool Sudoku::checkPlacement(int row, int column, int value)
{
    int rowCheck = (row / 3) * 3;
    int columnCheck = (column / 3) * 3;

    for(int i = 0; i < 9; i++)
    {
        if(Sudoku::buffer[row][i] == value || Sudoku::buffer[i][column] == value) //Check row and column
        {
            return false;
        }
    }

    for(int i = 0; i < rowCheck; i++)
    {
        for(int j = 0; j < columnCheck; j++)
        {
            if(Sudoku::buffer[i][j] == value)
            {
                return false;
            }
        }
    }

    return true;
}
