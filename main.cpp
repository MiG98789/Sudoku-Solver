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
    /*
    int data[81];
    for(int i = 0; i < 81; i++)
    {
        cin >> data[i];
    }
    */

    int data[81] =
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

    Sudoku s(data);
    s.solveGrid();
    s.printGrid();

    return 0;
}
