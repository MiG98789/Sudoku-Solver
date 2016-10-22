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
    }
}

void Sudoku::printGrid()	//Display the grid
{
    cout << "+-----+-----+-----+" << endl;

    for(int i = 0; i < 9; i++)
    {
        cout << "|";

        for(int j = 0; j < 9; j++)
        {
            cout << Sudoku::grid[i][j];

            if(j % 3 < 2)
            {
                cout << " ";
            }
            else
            {
                cout << "|";
            }
        }

        if(i % 3 == 2)
        {
            cout << endl << "+-----+-----+-----+";
        }

        cout << endl;
    }

}

bool Sudoku::checkPlacement(int row, int column, int value) //Check if placement of cell is valid
{
    for(int i = 0; i < 9; i++)
    {
        if(Sudoku::grid[row][i] == value || Sudoku::grid[i][column] == value) //Check row and column
        {
            return false;
        }
    }

    int rowCheck = (row / 3) * 3;
    int columnCheck = (column / 3) * 3;

    for(int i = rowCheck; i < rowCheck + 3; i++)   //Check block
    {
        for(int j = columnCheck; j < columnCheck + 3; j++)
        {
            if(Sudoku::grid[i][j] == value)
            {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::findUnassignedCell(int &row, int &column) //Returns true if any unassigned cell is found
{
    for(int i = 0; i < 81; i++)
    {
        row = i / 9;
        column = i % 9;

        if(Sudoku::grid[row][column] == UNASSIGNED)
        {
            return true;
        }
    }

    return false;
}

bool Sudoku::solveGrid()    //Calls an algorithm to solve the grid
{
    return Sudoku::algoBacktrack() ? true : false;
}

bool Sudoku::algoBacktrack()    //Solve recursively through backtracking
{
    int row = 0, column = 0;

    //---Base case: all cells filled (assume valid due to validation)---//
    if(!Sudoku::findUnassignedCell(row, column))
    {
        return true;
    }

    //---Recursive case: check for every number in {1,2,3,4,5,6,7,8,9}---//
    for(int number = 1; number <= 9; number++)
    {
        //---Check if placement is valid---//
        if(Sudoku::checkPlacement(row, column, number))
        {
            Sudoku::grid[row][column] = number;

            //---Check if next moves are successful---//
            if(Sudoku::algoBacktrack())
            {
                return true;
            }

            //---If cannot solve, move on to next number---//
            Sudoku::grid[row][column] = UNASSIGNED;
        }
    }

    //---If current try is invalid, backtrack---//
    return false;
}
