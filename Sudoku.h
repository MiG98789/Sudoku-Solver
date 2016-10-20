/*
 * Sudoku.h
 *
 *  Created on: 8 Sep 2016
 *      Author: Gian Miguel Del Mundo
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class Sudoku
{
    int grid[9][9];		//9x9 Sudoku grid [column][row]
    int buffer[9][9];	//9x9 buffer grid to store any changes
    bool solved;		//Flag to check if Sudoku is solved
    bool recursiveSolve(int grid[][9], int buffer[][9]); //Recursively solves the grid
    bool checkPlacement(int row, int column, int value);   //Check if placement of cell is valid

public:
    Sudoku(int grid[]);	//Constructor
    void printGrid();	//Display the Sudoku grid
    void solveGrid();	//Calls recursiveSolve()
};

#endif /* CLASS_H */
