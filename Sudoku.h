/*
 * Sudoku.h
 *
 *  Created on: 8 Sep 2016
 *      Author: Gian Miguel Del Mundo
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

const int UNASSIGNED = 0;

class Sudoku
{
    int grid[9][9];		//9x9 Sudoku grid [column][row]
    bool algoBacktrack(); //Solve recursively through backtracking
    bool checkPlacement(int row, int column, int value);   //Check if placement of cell is valid
    bool findUnassignedCell(int &row, int &column); //Returns true if unassigned cell is found

public:
    Sudoku(int grid[]);	//Constructor
    void printGrid();	//Display the Sudoku grid
    bool solveGrid();	//Calls an algorithm to solve the grid
};

#endif /* CLASS_H */
