# Sudoku Solver

[![https://gyazo.com/da403f31beb018e5b9f864ba1efe8b87](https://i.gyazo.com/da403f31beb018e5b9f864ba1efe8b87.png)](https://gyazo.com/da403f31beb018e5b9f864ba1efe8b87)

## Introduction
This program uses recursive backtracking to solve a 9x9 Sudoku puzzle. It was made using C++.

## Backtracking
Each recursion call occurs whenever an unassigned cell is reached. If the number placement is valid, it will be placed, then the program will move to the next unassigned cell, which would be the next recursion depth level. If, at some point, there are no valid inputs, backtracking will be carried out to the last valid cell, and other values will be tried out. However, since there is no currently no heuristic, the program may take a very long time to solve more complex puzzles.