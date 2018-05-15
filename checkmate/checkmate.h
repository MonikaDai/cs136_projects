// This module is to play the game "checkmate"

// print_board(board) prints out the 8 by 8 chessboard to the  //   screen with 8 characters per line
// effects: output a message
void print_board(const char board[64]);

// same_cdr(a, b) returns true if and only if positions [indices] a and b on a printed board would be on the same column,same diagonal or same row
// requires: a and b are distinct integers between 0 and 63
//           inclusive
bool same_cdr(int a, int b);

// can_capture_king(board) returns true if and only if the king can be captured by a queen in the current position and false otherwise
// requires: there is exactly one king on the board and some number [possibly zero] of queens
bool can_capture_king(const char board[64]);

// is_checkmate(board) returns true if and only if positions [indices] a and b on a printed board would be on the same column, same diagonal or same row
// requires: a and b are distinct integers between 0 and 63 inclusive
bool is_checkmate(char board[64]);
  