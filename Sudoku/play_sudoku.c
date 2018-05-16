// Version 1.1

#include "cs136.h"
#include "sudoku.h"
#include "array.h"

int main(void) {
  printf("Welcome to ASCII sudoku!\n");

  struct sudoku *s = read_sudoku();
  print_sol(s);

  while (1) {
    // stop if puzzle is solved.
    if (solved_puzzle(s)) {
      printf("Congratulations!  You solved the puzzle!\n");
      break;
    }

    int cmd = read_symbol();
    if (cmd == lookup_symbol("bye")) {
      printf("Goodbye!\n");
      break;
    } else if (cmd == lookup_symbol("reset")) {
      reset_sol(s);
    } else if (cmd == lookup_symbol("print")) {
      print_sol(s);
    } else if (cmd == lookup_symbol("fill")) {
      int row = 0;
      int col = 0;
      int num = 0;
      scanf("%d", &row);
      scanf("%d", &col);
      scanf("%d", &num);

      int rv = fill_cell(s, row, col, num);
      if (rv < 0) {
        printf("Error putting %d in the cell (%d,%d)\n", num, row, col);
      } else {
        printf("Successfully put %d in the cell (%d, %d)\n", num, row, col);
      }
    } else if (cmd == lookup_symbol("erase")) {
      int row = 0;
      int col = 0;
      scanf("%d", &row);
      scanf("%d", &col);
      int rv = erase_cell(s, row, col);
      if (rv < 0) {
        printf("Error erasing cell (%d,%d)\n", row, col);
      } else { 
        printf("The cell (%d,%d) is now empty.\n", row, col);
      }
    } else if (cmd == lookup_symbol("choices")) {
      int row = 0;
      scanf("%d", &row);
      int col = 0;
      scanf("%d", &col);

      int choices[DIM];
      int num_choices = 0;
      choices_cell(s, row, col, choices, &num_choices);
      if (num_choices == 0) {
        printf("No possible value for cell (%d,%d)\n", row, col);
      } else {
        printf("Cell (%d,%d) could have values ", row, col);
        print_array(choices, num_choices);
      }
    } else if (cmd == lookup_symbol("hint")) {
      int row = -1;
      int col = -1;
      int rv = next_cell(s, &row, &col);
      if (rv < 0) {
        printf("Could not find a cell with only one possible value\n");
      } else {
        printf("Try filling cell (%d,%d)\n", row, col);
      }
    } else if (cmd == lookup_symbol("solve")) {
      if (solve(s)) {
        print_sol(s);
      } else {
        printf("Could not solve the puzzle using search and backtracking :(\n");
      }
    } else if (cmd == INVALID_SYMBOL) {
      printf("EOF Reached\n");
      break;
    } else {
      printf("Invalid Command: ");
      print_symbol(cmd);
      printf("\n");
      break;
    }
  }

  sudoku_destroy(s);
}