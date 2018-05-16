
// This hangman-io module provides constant strings
// for printing within the hangman game

extern const int max_strikes;

extern const char *enter_game_number;
extern const char *invalid_game_number ;
extern const char *letter_prompt;
extern const char *not_a_letter;
extern const char *already_guessed_letter;
extern const char *not_in_word;
extern const char *not_last_guess;
extern const char *play_again;
extern const char *invalid_play_again_response;
extern const char *game_over;
extern const char *congratulations;

// print_hangman(strike) prints the hangman picture
//   for the given number of strikes
// requires: 0 <= strike <= max_strikes
void print_hangman(int strike);
