#include "cs136.h"
#include "checkmate.h"

// An  I/O-based test client for checkmate
// You should not need to modify this file

// reveiw sample.in and sample.expect for usage

// print_bool(b) prints b: either "true\n" or "false\n"
void print_bool(bool b) {
  if (b) {
    printf("true\n");
  } else {
    printf("false\n");
  }
}


int main(void) {
  char board[64] = {0};
  for (int i = 0; i < 64; ++i) {
    board[i] = '*';
  }
  int cmd = 0;
  while (1) {
    cmd = read_symbol();
    if (cmd == INVALID_SYMBOL || cmd == lookup_symbol("quit")) {
      break;
      
    } else if (cmd == lookup_symbol("read")) {
      for (int i = 0; i < 64; ++i) {
        assert(scanf(" %c", &board[i]) == 1);
      }
      
    } else if (cmd == lookup_symbol("print")) {
      print_board(board);
      
    } else if (cmd == lookup_symbol("cdr")) {
      int a = 0;
      int b = 0;
      assert(scanf("%d", &a) == 1);
      assert(scanf("%d", &b) == 1);
      print_bool(same_cdr(a, b));
      
    } else if (cmd == lookup_symbol("capture")) {
      print_bool(can_capture_king(board));
      
    } else if (cmd == lookup_symbol("checkmate")) {
      print_bool(is_checkmate(board));
      
    } else {
      printf("invalid symbol: ");
      print_symbol(cmd);
      printf("\n");
      break;
    }
  }
}
