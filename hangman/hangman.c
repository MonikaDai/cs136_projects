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

#include <string.h>
#include "hangman-io.h"
#include "words.h"
#include "cs136.h"


// case_equal(a, b) compares whether two characters a, b are the same regardless of whether they are capital or not
bool case_equal(char a, char b){
  if((a >= 'a' && a <= 'z') && (b >= 'a' && b <= 'z')){
    return a == b;
  }else if((a >= 'a' && a <= 'z') && (b >= 'A' && b <= 'Z')){
    return a == b + 32;
  }else if((b >= 'a' && b <= 'z') && (a >= 'A' && a <= 'Z')){
    return b == a + 32;
  }else if((a >= 'A' && a <= 'Z') && (b >= 'A' && b <= 'Z')){
    return a == b;
  }else{
    return a == b;
  }
}

// to_upper_case(a) converts all lower-case characters to upper-case characters
char to_upper_case(char a){
  if(a >= 'a' && a <= 'z'){
    return a - 32;
  }else{
    return a;
  }
}

// main() plays the game Hangman
int main(void) {
  int quit_or_not = 0;
  // for the entire game
  while(1){
    printf(enter_game_number, max_words);
    int num_entered = 0;
    int strike = 0;
    int gam_over = 0;  
    // to draw the initial hangman
    while(1){
      int rv = scanf("%d", &num_entered);
      if(rv != 1 || num_entered < 1 || num_entered > max_words){
        printf("%s", invalid_game_number);
        printf(enter_game_number, max_words);
      }else{
        break;
      }
    }
    const char *hid_word = get_word(num_entered);
    print_hangman(strike);
    printf("%s", letter_prompt);
    int len = strlen(hid_word);
    char board[51] = {0};
    for(int i = 0; i < len; ++i){
      if(hid_word[i] != ' '){
        board[i] = '*';
      }else{
        board[i] = ' ';
      }
    }
    printf("%s\n", board);
    char entered_c = 0;
    char board_exist[128] = {0};
    // follow the rules
    while(1){
      int can_quit = 0;
      int in_word = 0;
      if(gam_over) break;

      scanf(" %c", &entered_c);
      ++board_exist[to_upper_case(entered_c) - 0];
      // not a character
      if(!((entered_c >='a' && entered_c <='z') ||
           (entered_c >='A' && entered_c <='Z'))){
        printf(not_a_letter, entered_c);
        print_hangman(strike);
        printf("%s", letter_prompt);
        printf("%s\n", board);
        continue;
      }
      // exist characters
      if(board_exist[to_upper_case(entered_c) - 0] >= 2){
        printf(already_guessed_letter, to_upper_case(entered_c));
        print_hangman(strike);
        printf("%s", letter_prompt);
        printf("%s\n", board);
        continue;
      }
      
      for(int i = 0; i < len; ++i){
        if(case_equal(entered_c, hid_word[i])){
          board[i] = to_upper_case(entered_c);
          in_word = 1;
        }
      }
      // character is/(is not) in the word
      if(!in_word){
        printf(not_in_word, to_upper_case(entered_c));
        ++strike;
        if(strike < max_strikes){
          printf(not_last_guess, max_strikes - strike);
        }else{
          print_hangman(strike);
          printf(game_over, hid_word);  
          break;
        }
      }
      // solve
      for(int i = 0; i < len; ++i){
        if(i == (len - 1) && board[i] != '*'){
          printf(congratulations, hid_word);
          can_quit = 1;
          break;
        }
        if(board[i] == '*') break;
      }
      if(can_quit) break;
      
      print_hangman(strike);
      printf("%s", letter_prompt);
      printf("%s\n", board);
    }
    // whether to play again
    while(1){
      printf("%s", play_again);
      char play_agn = 0;
      scanf(" %c", &play_agn);
      if(case_equal(play_agn, 'Y')){
        quit_or_not = 0;
        break;
      }else if(case_equal(play_agn, 'N')){
        quit_or_not = 1;
        break;
      }else{
        printf("%s", invalid_play_again_response);
      }
    }
    if(quit_or_not) break;
    else continue;
  }
}

