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
#include "checkmate.h"

// print_board(board) prints out the 8 by 8 chessboard to the  //   screen with 8 characters per line
// effects: output a message
void print_board(const char board[64]){
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      int index = i * 8 + j;
      printf("%c", board[index]);
    }
    printf("\n");
  }
}

// same_cdr(a, b) returns true if and only if positions [indices] a and b on a printed board would be on the same column,same diagonal or same row
// requires: a and b are distinct integers between 0 and 63
//           inclusive
bool same_cdr(int a, int b){
  if((a % 8 == b % 8) || (a / 8 == b / 8)){
    return 1;
  }else if((a < b) && (a % 8 == 0)){
    while(1){
      if(a == b){
        return 1;
      }else if(a >= 63){
        return 0;
      }else{
        a += 9;
      }
    }
  }else if((b < a) && (b % 8 == 0)){
    while(1){
      if(a == b){
        return true;
      }else if(b >= 63){
        return false;
      }else{
        b += 9;
      }
    }
  }else if((a < b) && (a % 8 == 7)){
    while(1){
      if(a == b){
        return true;
      }else if(a >= 63){
        return false;
      }else{
        a += 7;
      }
    }
  }else if((b < a) && (b % 8 == 7)){
    while(1){
      if(a == b){
        return true;
      }else if(b >= 63){
        return false;
      }else{
        b += 7;
      }
    }
  }else if(a < b){
    int initial = a;
    while(1){
      if(a == b){
        return 1;
      }else if(a % 8 == 7){
        break;
      }else{
        a += 9;
      }
    }
    a = initial;
    while(1){
      if(a == b){
        return 1;
      }else if(a % 8 == 0){
        break;
      }else{
        a += 7;
      }
    }
    return 0;
  }else{
    int initial = b;
    while(1){
      if(a == b){
        return 1;
      }else if(b % 8 == 7){
        break;
      }else{
        b += 9;
      }
    }
    b = initial;
    while(1){
      if(a == b){
        return 1;
      }else if(b % 8 == 0){
        break;
      }else{
        b += 7;
      }
    }
    return 0;
  }
}

// can_capture_king(board) returns true if and only if the king can be captured by a queen in the current position and false otherwise
// requires: there is exactly one king on the board and some number [possibly zero] of queens
bool can_capture_king(const char board[64]){
  int king = -1;
  for(int i = 0; i < 64; ++i){
    if(board[i] == 'K'){
      king = i;
    }
  }
  int queen_num[64] = {0};
  for(int i = 0; i < 64; ++i){
    if(board[i] == 'Q'){
      queen_num[i] = 1;
    }
  }
  for(int i = 0; i < 64; ++i){
    if(queen_num[i] == 1){
      if(same_cdr(i, king)){
        return 1;
      }
    }
  }
  return 0;
}

// is_checkmate(board) returns true if and only if positions [indices] a and b on a printed board would be on the same column, same diagonal or same row
// requires: a and b are distinct integers between 0 and 63 inclusive
bool is_checkmate(char board[64]){
  int king = 0;
  int check[8] = {1,1,1,1,1,1,1,1};  
  for(int i = 0; i < 64; ++i){
    if(board[i] == 'K'){
      king = i;
    }
  }
  if((king - 9 >= 0) && (king % 8 != 0)){
    char temp = board[king - 9];
    board[king - 9] = 'K';
    board[king] = '*';
    check[0] = can_capture_king(board);
    board[king - 9] = temp;
    board[king] = 'K';
  }
  if(king - 8 >= 0){
    char temp = board[king - 8];
    board[king - 8] = 'K';
    board[king] = '*';
    check[1] = can_capture_king(board);
    board[king - 8] = temp;
    board[king] = 'K';
  }
  if((king - 7 >= 0) && (king % 8 != 7)){
    char temp = board[king - 7];
    board[king - 7] = 'K';
    board[king] = '*';
    check[2] = can_capture_king(board);
    board[king - 7] = temp;
    board[king] = 'K';
  }
  if(king % 8 != 0){
    char temp = board[king - 1];
    board[king - 1] = 'K';
    board[king] = '*';
    check[3] = can_capture_king(board);
    board[king - 1] = temp;
    board[king] = 'K';
  }
  if(king % 8 != 7){
    char temp = board[king + 1];
    board[king + 1] = 'K';
    board[king] = '*';
    check[4] = can_capture_king(board);
    board[king + 1] = temp;
    board[king] = 'K';
  }
  if((king + 7 <= 62) && (king % 8 != 0)){
    char temp = board[king + 7];
    board[king + 7] = 'K';
    board[king] = '*';
    check[5] = can_capture_king(board);
    board[king + 7] = temp;
    board[king] = 'K';
  }
  if(king + 8 <= 63){
    char temp = board[king + 8];
    board[king + 8] = 'K';
    board[king] = '*';
    check[6] = can_capture_king(board);
    board[king + 8] = temp;
    board[king] = 'K';
  }
  if((king + 9 <= 63) && (king % 8 != 7)){
    char temp = board[king + 9];
    board[king + 9] = 'K';
    board[king] = '*';
    check[7] = can_capture_king(board);
    board[king + 9] = temp;
    board[king] = 'K';
  }
  for(int i = 0; i < 8; ++i){
    if(check[i] == 0){
      return 0;
    }
  }
  return can_capture_king(board);
}
