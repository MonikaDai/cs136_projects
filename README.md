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
  
### Hangman
  
The user will ask to play a game, a number N from 1 to max_word corresponding to the word entered in position N. If an invalid number is entered, an error message should be displayed and the user should be asked to enter a valid number. You will get your hidden word from our words module whose interface file is provided. The game will then print out a blank hangman based on the provided function print_hangman, prompt the user to enter a letter and a series of asterisks representing the word or phrase we are trying to guess. We call this series of asterisks a board.

See this website for a demonstration:
http://www.playhangman.com/PH.asp?g=olympicsW&l=B

  * [hangman.c](./hangman/hangman.c)
  ***
  
### The Game of Splender

In Splendor, you are a rich merchant during the Renaissance. You will use your resources to acquire mines in order to get the most prestige points. During the game, you will take gem tokens and use these tokens to build mines. Each mine is worth prestige points and/or permanent gems. The permanent gems allow you to purchase subsequent mines for a lesser cost.

The gem bank has gems of 4 different colours: red, green, blue, and white. At the start of the game. The bank starts with 7 gems of each colour.

On your turn, if you have less than 10 temporary gems, you may collect temporary gems. You may collect either 2 or 3 temporary gems. You can collect 3 temporary gems only if the 3 temporary gems all have different colours. You can collect 2 temporary gems only if the 2 gems have the same colour and there are 4 or more gems of that colour in the bank before you try to collect the 2 gems. Remember that gems are real objects, so it is impossible to collect more gems of a colour than what is available in the gem bank. It is also impossible to collect a negative number of gems of any colour.

After collecting gems, you may choose to build a mine. Building a mine requires a collection of gems. A mine gives you permanent gems, prestige points, or both. A valid mine must cost a non-negative number of gems of each colour to build, reward the player with a non-negative number of gems of each colour and a non-negative number of prestige points. To build a mine, you must spend your permanent gems first, and then your temporary gems if you don't have enough permanent gems. You do not lose permanent gems by spending them. Permanent gems can be repeatedly used towards building every mine. When you spend a temporary gem to build a mine, you must return the gem to the gem bank.

For example, suppose that you have 2 permanent blue gems and 2 temporary green gems. To build a mine requiring 2 blue gems and 1 green gem, you will only need to spend 1 temporary green gem.

A player wins the game as soon as they have 15 prestige points.

  * [main.c](./the_game_of_splender/main.c)
  ***
  
  
