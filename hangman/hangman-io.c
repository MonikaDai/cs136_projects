#include <assert.h>
#include <stdio.h>
#include "hangman-io.h"

const int max_strikes = 6;

const char *enter_game_number = 
  "Please enter a valid game number between 1 and %d.\n";

const char *invalid_game_number = 
  "Error, the number entered was not valid.\n";

const char *letter_prompt = 
  "Please enter a letter.\n";

const char *not_a_letter = 
  "The character %c is not a letter.\n";

const char *already_guessed_letter = 
  "You have already guessed the letter %c. Please enter another letter.\n";

const char *not_in_word = 
  "The letter %c is not in the word.\n";

const char *not_last_guess = 
  "Watch out! You only have %d more guesses left before your man is hung!\n";

const char *play_again = 
  "Do you want to play again? (Y for yes, N for no).\n";

const char *invalid_play_again_response = 
  "Error, invalid response.\n";

const char *game_over = 
  "Game over. The correct word was %s.\n";

const char *congratulations = 
  "You win! The correct word was %s.\n";

static char *hangman_ascii[7] = {
"\
0000000000000\n\
0           0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",
"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",
"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0           2\n\
0           2\n\
0           2\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",
"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          32\n\
0         3 2\n\
0        3  2\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",
"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          324\n\
0         3 2 4\n\
0        3  2  4\n\
0\n\
0\n\
0\n\
0\n\
0\n\
0\n",
"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          324\n\
0         3 2 4\n\
0        3  2  4\n\
0          5\n\
0         5\n\
0        5\n\
0       5\n\
0\n\
0\n",
"\
0000000000000\n\
0           0\n\
0           1\n\
0          1 1\n\
0           1\n\
0          324\n\
0         3 2 4\n\
0        3  2  4\n\
0          5 6\n\
0         5   6\n\
0        5     6\n\
0       5       6\n\
0\n\
0\n" };


void print_hangman(int strike) {
  assert(strike >= 0);
  assert(strike <= max_strikes);
  printf("%s", hangman_ascii[strike]);
}
