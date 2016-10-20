/*
 * main.cpp
 *
 *  Created on: 7 Sep 2016
 *      Author: Gian Miguel
 */

#include "Sudoku.h"
using namespace std;

int main(int argc, char** argv)
{

    /* For testing
    int grid[81];
    for(int i = 0; i < 81; i++)
    {
        grid[i] = 0;
    }
    */

    /* For testing
    int grid[81] =
    {
        4, 0, 0, 0, 0, 0, 8, 0, 5,
        0, 3, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 7, 0, 0, 0, 0, 0,
        0, 2, 0, 0, 0, 0, 0, 6, 0,
        0, 0, 0, 0, 8, 0, 4, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 6, 0, 3, 0, 7, 0,
        5, 0, 0, 2, 0, 0, 0, 0, 0,
        1, 0, 4, 0, 0, 0, 0, 0, 0
    };
    */

    int grid[81];
    for(int i = 0; i < 81; i++)
    {
        cin >> grid[i];
    }

    Sudoku s(grid);

    if(s.solveGrid())
    {
        s.printGrid();
    }
    else
    {
        cout << "Cannot solve Sudoku";
    }

    return 0;
}
