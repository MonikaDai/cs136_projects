# cs136_projects
### Here are the codes of some projects:

### Checkmate

A chessboard is an 8 by 8 grid of squares which we will think of as a length 64 one dimensional character array. The board should be read such that the first 8 characters of the array represents the first row, the characters in the next 8 positions represent the second row and so on until the final row.

Empty spaces will be denoted with an asterisk * and spaces with either a king or a queen will be denoted by a K or a Q respectively (capital letters). A king can move one space horizontally, vertically or diagonally. A queen can move any number of spaces but only in one direction from vertically, horizontally or diagonally. Both pieces must remain on the chessboard at all times and pieces cannot move through other pieces (but can capture pieces, see below). In this simplified version, I will assume that there is exactly one king on the board and some number (possibly zero) of queens. In the game, all of the queens are on the same side trying to capture the lone king. A queen captures a king (or vice versa) if and only if the queen moves to the same square as the king (or vice versa).

  * [checkmate.c](checkmate/checkmate.c)
  * [main.c](./checkmate/test-checkmate.c)
  ***
  
  ### Sudoku
  
A valid solution of a Sudoku puzzle must satisfy three constraints.

Row constraint: each integer from 1 to 9 appears exactly once in every row.
Column constraint: each integer from 1 to 9 appears exactly once in every column.
Box constraint: each integer from 1 to 9 appears exactly once in every box.

The module stores a Sudoku puzzle in a struct with two arrays. When a puzzle is read in, it is stored in both the puzzle and the sol arrays. As you attempt to solve the puzzle, you can modify the sol array until it contains a valid solution.

The rows and columns of a Sudoku puzzle are zero indexed. Each cell is represented by (row,col). For example, for the following puzzle from Wikipedia, cell (0,0) has the value 5, cell (1,3) has the value 1, and cell (0, 2) has the value 0. An empty cell has a value of 0 in it.

  * [sudoku.c](sudoku/sudoku.c)
  * [main.c](./sudoku/play_sudoku.c)
  ***
