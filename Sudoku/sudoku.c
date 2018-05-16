/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT:
// I received help from the following sources:

// None

// Name: Xuemeng Dai
// login ID: x33dai
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"
#include "sudoku.h"
#include "array.h"

const int DIM = 9;

static const int EMPTY = 0;
static const char BLANK = '-';
static const int MIN = 1;
static const int MAX = 9;

static const int SUCCESS = 0;
static const int ERROR = -1;
static const int ERASE_EMPTY_CELL = -2;
static const int ERASE_FILLED_CELL = -3;
static const int ERROR_NEXT_CELL = -4;
struct sudoku {
  int puzzle[DIM * DIM];
  int sol[DIM * DIM];
};

// You need to implement the following four functions.

// fill_cell(s,row,col,num) tries to fill num in the cell (row,col).  
// It returns 0 if doing so does not violate any of the row, column, 
// and box constraints.  Otherwise, it returns a negative integer.
// requires: row and col are valid indices. 
//           num is an integer between 1 and 9.
// effects:  mutates *s
// time: O(1)
int fill_cell(struct sudoku *s, int row, int col, int num) {
  assert(s);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);
  assert(MIN <= num && num <= MAX);
  // row:
  int row_judge = 0;
  int row_exist[9] = {0};
  for(int i = 0; i < 9; ++i){
    row_exist[i] = s->sol[row * DIM + i];
  }
  for(int i = 0; i < 9; ++i){
    if(i != col){
      if((s->sol[row * DIM + col] == 0 && 
          num != row_exist[i]) || (s->sol[row * DIM + col] == 0 && row_exist[i] == 0)){
        continue;
      }else{
        row_judge = ERROR;
      }
    }
  } 
  // column:
  int col_judge = 0;
  int col_exist[9] = {0};
  for(int i = 0; i < 9; ++i){
    col_exist[i] = s->sol[i * DIM + col];
  }
  for(int i = 0; i < 9; ++i){
    if(i != row){
      if((s->sol[row * DIM + col] == 0 && 
          num != col_exist[i]) || (s->sol[row * DIM + col] == 0 && col_exist[i] == 0)){
        continue;
      }else{
        col_judge = ERROR;
      }
    }
  }
  // box:
  int box_judge = 0;
  int box_left_top = row / 3 * 27 + col / 3 * 3;
  int box_exist[9] = {0};
  for (int i = 0; i < 3; ++i){
    box_exist[i] = s->sol[box_left_top + i];
  }
  for (int i = 0; i < 3; ++i){
    box_exist[i + 3] = s->sol[box_left_top + 9 + i];
  }
  for (int i = 0; i < 3; ++i){
    box_exist[i + 6] = s->sol[box_left_top + 18 + i];
  }
  for(int i = 0; i < 9; ++i){
    if((s->sol[row * DIM + col] == 0 && 
        num != box_exist[i]) || (s->sol[row * DIM + col] == 0 && box_exist[i] == 0)){
      continue;
    }else{
      box_judge = ERROR;
    }
  }
  // combine row, column, box constraint:
  if(box_judge == 0 && row_judge == 0 && col_judge == 0){
    s->sol[row * DIM + col] = num;
    return 0;
  }else{
    return ERROR;
  }
}

// can_be_filled(s,row,col,num) tries to fill num in the cell (row,col).  
// It returns 1 if doing so does not violate any of the row, column, 
// and box constraints.  Otherwise, it returns 0
// requires: row and col are valid indices. 
//           num is an integer between 1 and 9.
// time: O(1)
static int can_be_filled(const struct sudoku *s, int row, int col, int num){
  assert(s);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);
  assert(MIN <= num && num <= MAX);
  int row_judge = 0;
  int row_exist[9] = {0};
  for(int i = 0; i < 9; ++i){
    row_exist[i] = s->sol[row * DIM + i];
  }
  for(int i = 0; i < 9; ++i){
    if(i != col){
      if((s->sol[row * DIM + col] == 0 && 
          num != row_exist[i]) || (s->sol[row * DIM + col] == 0 && row_exist[i] == 0)){
        continue;
      }else{
        row_judge = ERROR;
      }
    }
  } 
  // column:
  int col_judge = 0;
  int col_exist[9] = {0};
  for(int i = 0; i < 9; ++i){
    col_exist[i] = s->sol[i * DIM + col];
  }
  for(int i = 0; i < 9; ++i){
    if(i != row){
      if((s->sol[row * DIM + col] == 0 && 
          num != col_exist[i]) || (s->sol[row * DIM + col] == 0 && col_exist[i] == 0)){
        continue;
      }else{
        col_judge = ERROR;
      }
    }
  }
  // box:
  int box_judge = 0;
  int box_left_top = row / 3 * 27 + col / 3 * 3;
  int box_exist[9] = {0};
  for (int i = 0; i < 3; ++i){
    box_exist[i] = s->sol[box_left_top + i];
  }
  for (int i = 0; i < 3; ++i){
    box_exist[i + 3] = s->sol[box_left_top + 9 + i];
  }
  for (int i = 0; i < 3; ++i){
    box_exist[i + 6] = s->sol[box_left_top + 18 + i];
  }
  for(int i = 0; i < 9; ++i){
    if((s->sol[row * DIM + col] == 0 && 
        num != box_exist[i]) || (s->sol[row * DIM + col] == 0 && box_exist[i] == 0)){
      continue;
    }else{
      box_judge = ERROR;
    }
  }
  // combine row, column, box constraint:
  if(box_judge == 0 && row_judge == 0 && col_judge == 0){
    return 1;
  }else{
    return 0;
  }
}

// choices_cell(s,row,col,choices,num_choices) determines all the 
// possible values for the cell (row,col) that do not violate
// any of the row, column, and box constraints.  It mutates choices 
// to contain the possible values and mutates *num_choices to be
// the number of possible values.
// requires: row and col are valid indices.
//           choices is a valid array with length DIM
// effects:  mutates choices and *num_choices
// time: O(1)
void choices_cell(const struct sudoku *s, int row, int col, 
                  int choices[], int *num_choices) {
  assert(s);
  assert(num_choices);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);
  int check_array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int choices_index = 0;
  for(int i = 0; i < 9; ++i){
    if(can_be_filled(s, row, col, check_array[i])){
      choices[choices_index] = check_array[i];
      ++choices_index;
      ++(*num_choices);
    }
  }
  for(int i = choices_index; i < 9; ++i){
    choices[i] = 0;
  }
}

// solved_puzzle(s) returns true if s has a valid solution to the puzzle, 
// and returns false otherwise.
// time: O(1)
bool solved_puzzle(const struct sudoku *s) {
  assert(s);
  for(int i = 0; i < DIM * DIM; ++i){
    if(s->sol[i] == 0) return false;
  }
  return true;
}

// solve(s) solves the Sudoku puzzle by search and backtracking.  
// It mutates the 
// It returns true if s has a valid solution to the puzzle, 
// and returns false otherwise.
// effects: mutates *s
// time: O(1)
bool solve(struct sudoku *s) {
  assert(s);
  if(solved_puzzle(s)){
    return 1;
  }else{        
    for(int i = 0; i < DIM * DIM; ++i) {
      int choices[9] = {0};
      int num_choices = 0;
      if(s->sol[i] == 0){
        choices_cell(s, i / 9, i % 9, choices, &num_choices);
        if(num_choices == 0){
          return 0;
        }else{
          for(int j = 0; j < num_choices; ++j) {
            s->sol[i] = choices[j];
            if(solve(s) == 0) {
              s->sol[i] = 0;
              continue;
            } else {
              return 1;
            }
          }
          return 0;
        }
      }
    }
    return 0;
  }
}

// There is no need to modify the rest of the functions.

struct sudoku *read_sudoku(void) {
  struct sudoku *s = malloc(sizeof(struct sudoku));
  char c = 0;
  for (int row = 0; row < DIM; ++row) {
    for (int col = 0; col < DIM; ++col) {
      scanf(" %c", &c);
      if (c == BLANK) {
        s->puzzle[row * DIM + col] = 0;
      } else {
        s->puzzle[row * DIM + col] = c - '0';
      }
    }
  }

  // copy puzzle to solution
  reset_sol(s);

  return s;
}

void sudoku_destroy(struct sudoku *s) {
  assert(s);
  free(s);
}

void print_sol(const struct sudoku *s) {
  assert(s);

  printf("\n");
  for (int row = 0; row < DIM; ++row) {
    for (int col = 0; col < DIM; ++col) {
      int num = s->sol[row * DIM + col];
      if (num == EMPTY) {
        printf("%c", BLANK);
      } else {
        printf("%d", num);
      }  
    }
    printf("\n");
  }
  printf("\n");
}

void reset_sol(struct sudoku *s) {
  assert(s);
  for (int row = 0; row < DIM; ++row) {
    for (int col = 0; col < DIM; ++col) {
      s->sol[row * DIM + col] = s->puzzle[row * DIM + col];
    }
  }  
}

// cell_empty(board, row, col) returns true
// if cell (row,col) is empty on board.
// requires: board is a valid sudoku puzzle.
static bool cell_empty(const int board[], int row, int col) {
  assert(board);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);

  return board[row * DIM + col] == EMPTY; //0
}

int erase_cell(struct sudoku *s, int row, int col) {
  assert(s);
  assert(0 <= row && row <= DIM - 1);
  assert(0 <= col && col <= DIM - 1);

  if (cell_empty(s->sol, row, col)) {
    return ERASE_EMPTY_CELL; //-2
  }
  if (!cell_empty(s->puzzle, row, col)) {
    return ERASE_FILLED_CELL; //-3
  }
  s->sol[row * DIM + col] = EMPTY;
  return SUCCESS; //0
}


int next_cell(const struct sudoku *s, int *row, int *col) {
  assert(s);
  assert(row);
  assert(col);
  int choices[DIM];
  int num_choices = 0;
  for (int i = 0; i < DIM; ++i) {
    for (int j = 0; j < DIM; ++j) {
      if (!cell_empty(s->sol, i, j)) continue;
      choices_cell(s, i, j, choices, &num_choices);
      if (num_choices == 1) {
        *row = i;
        *col = j;
        return SUCCESS;
      }
    }
  }
  return ERROR_NEXT_CELL;
}
