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

// Version 1.1

#include "cs136.h"

/////////////////////////////////////////////////////////////
// DO NOT MODIFY THE THREE DEFINITIONS BELOW.

struct gem_combo {
  int red;
  int green;
  int blue;
  int white;
};

struct merchant {
  int id;
  int prestige_points;
  struct gem_combo temp;
  struct gem_combo perm;
};

struct mine_card {
  int prestige_points;
  struct gem_combo cost;
  struct gem_combo reward;
};

// DO NOT MODIFY THE THREE DEFINITIONS ABOVE
/////////////////////////////////////////////////////////////


// Implement the following functions

bool can_collect_gems(struct merchant *player, struct gem_combo *gems, struct gem_combo *bank) {
  int total = player->temp.red + player->temp.green
    + player->temp.blue + player->temp.white;
  if (total < 10) {
    if (gems->red == 2 && gems->green == 0 &&
        gems->blue == 0 && gems->white == 0) {
      if (bank->red >= 4) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 0 && gems->green == 2 &&
               gems->blue == 0 && gems->white == 0) {
      if (bank->green >= 4) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 0 && gems->green == 0 &&
               gems->blue == 2 && gems->white == 0) {
      if (bank->blue >= 4) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 0 && gems->green == 0 &&
               gems->blue == 0 && gems->white == 2) {
      if (bank->white >= 4) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 1 && gems->green == 1 &&
               gems->blue == 1 && gems->white == 0) {
      if (bank->red >= 1 && bank->green >= 1
          && bank->blue >= 1) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 1 && gems->green == 1 &&
               gems->blue == 0 && gems->white == 1) {
      if (bank->red >= 1 && bank->green >= 1
          && bank->white >= 1) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 1 && gems->green == 0 &&
               gems->blue == 1 && gems->white == 1) {
      if (bank->red >= 1 && bank->blue >= 1
          && bank->white >= 1) {
        return true;
      } else {
        return false;
      }
    } else if (gems->red == 0 && gems->green == 1 &&
               gems->blue == 1 && gems->white == 1) {
      if (bank->green >= 1 && bank->blue >= 1
          && bank->white >= 1) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return false;
}

bool collect_gems(struct merchant *player, struct gem_combo *gems, struct gem_combo *bank) {
  player->temp.red += gems->red;
  player->temp.green += gems->green;
  player->temp.blue += gems->blue;
  player->temp.white += gems->white;
  bank->red -= gems->red;
  bank->green -= gems->green;
  bank->blue -= gems->blue;
  bank->white -= gems->white;
  return false;
}

bool can_build_mine(struct merchant *player, struct mine_card *mine) {
  if (player->temp.red + player->perm.red >= mine->cost.red
      && player->temp.green + player->perm.green >= mine->cost.green
      && player->temp.blue + player->perm.blue >= mine->cost.blue
      && player->temp.white + player->perm.white >= mine->cost.white) {
    return true;
  }
  return false;
}

bool build_mine(struct merchant *player, struct mine_card *mine, struct gem_combo *bank) {
  mine->cost.red -= player->perm.red;
  if (mine->cost.red < 0) {
    mine->cost.red = 0;
  }
  mine->cost.green -= player->perm.green;
  if (mine->cost.green < 0) {
    mine->cost.green = 0;
  }
  mine->cost.blue -= player->perm.blue;
  if (mine->cost.blue < 0) {
    mine->cost.blue = 0;
  }
  mine->cost.white -= player->perm.white;
  if (mine->cost.white < 0) {
    mine->cost.white = 0;
  }
  bank->red += mine->cost.red;
  bank->green += mine->cost.green;
  bank->blue += mine->cost.blue;
  bank->white += mine->cost.white;
  player->temp.red -= mine->cost.red;
  player->temp.green -= mine->cost.green;
  player->temp.blue -= mine->cost.blue;
  player->temp.white -= mine->cost.white;
  player->perm.red += mine->reward.red;
  player->perm.green += mine->reward.green;
  player->perm.blue += mine->reward.blue;
  player->perm.white += mine->reward.white;
  player->prestige_points += mine->prestige_points;
  return false;
}

struct gem_combo read_gem_combo(void) {
  struct gem_combo combo = {};
  int red = read_int();
  combo.red = red;
  int green = read_int();
  combo.green = green;
  int blue = read_int();
  combo.blue = blue;
  int white = read_int();
  combo.white = white;
  return combo;
}

struct mine_card read_mine(void) {
  struct mine_card m = {};
  int a = read_int();
  m.cost.red = a;
  int b = read_int();
  m.cost.green = b;
  int c = read_int();
  m.cost.blue = c;
  int d = read_int();
  m.cost.white = d;
  int e = read_int();
  m.reward.red = e;
  int f = read_int();
  m.reward.green = f;
  int g = read_int();
  m.reward.blue = g;
  int h = read_int();
  m.reward.white = h;
  int i = read_int();
  m.prestige_points = i;
  return m;
}

////////////////////////////////////////////////////////////
// DO NOT MODIFY THE SIX FUNCTIONS BELOW

// print_gem_combo(combo) prints the number of gems
// of each colour in the collection.
// requires: combo is not null
// effects: produces output
void print_gem_combo(struct gem_combo *combo) {
  printf("R(%d) G(%d) B(%d) W(%d)\n",
         combo->red, combo->green, combo->blue, combo->white);
}

// print_player(player) prints the player's
// prestige points, permanent gems, and temporary gems.
// requires: player is not null
// effects: produces output
void print_player(struct merchant *player) {
  printf("Player %d: prestige points: %d\n",
         player->id, player->prestige_points);

  printf("Permanent gems: ");
  print_gem_combo(&(player->perm));

  printf("Temporary gems: ");
  print_gem_combo(&(player->temp));

  printf("\n");
}

// print_game_status(bank, player1, player2) prints the
// information of a game, including the gems in the bank
// and the information of each of the two players.
// requires: bank, player1, and player2 are not null.
// effects: produces output
void print_game_status(struct gem_combo *bank, struct merchant *player1, struct merchant *player2) {
  printf("Gem bank: ");
  print_gem_combo(bank);
  printf("\n");
  print_player(player1);
  printf("\n");
  print_player(player2);
}

// print_invalid_cmd_error() prints the Invalid
// command! message.
// effects: produces output
void print_invalid_cmd_error(void) {
  printf("Invalid command!\n");
}

// player_won(player) returns true if the player has
// at least 15 prestige points and false otherwise.
// requires: player is not null
bool player_won(struct merchant *player) {
  return player->prestige_points >= 15;
}

// play_game() simulates a game of Splendor with
// 2 players.
// effects: produces output
void play_game(void) {
  struct gem_combo bank = {7, 7, 7, 7};
  struct merchant merchant1 = {.id=1};
  struct merchant merchant2 = {.id=2};

  while (1) {
    int cmd = read_symbol();
    if (cmd == lookup_symbol("bye")){
      printf("Goodbye!\n");
      break;
    } else if (cmd == lookup_symbol("status")) {
      int param = read_symbol();
      if (param == lookup_symbol("game")) {
        // print game information
        print_game_status(&bank , &merchant1, &merchant2);
      } else if (param == lookup_symbol("player")) {
        // print player information
        int pid = read_int();
        if (pid == 1) {
          print_player(&merchant1);
        } else {
          print_player(&merchant2);
        }
      } else if (param == lookup_symbol("bank")) {
        // print gem bank information
        printf("Gem bank: ");
        print_gem_combo(&bank);
      }
    } else if (cmd == lookup_symbol("collect")) {

      int pid = read_int();
      struct gem_combo gems = read_gem_combo();

      // collect gems
      if (pid == 1) {
        if (can_collect_gems(&merchant1, &gems, &bank)) {
          collect_gems(&merchant1, &gems, &bank);
        } else {
          print_invalid_cmd_error();
        }
      } else {
        if (can_collect_gems(&merchant2, &gems, &bank)) {
          collect_gems(&merchant2, &gems, &bank);
        } else {
          print_invalid_cmd_error();
        }
      }

    } else if (cmd == lookup_symbol("build")) {

      int pid = read_int();
      struct mine_card mine = read_mine();

      // build the mine
      if (pid == 1) {
        if (can_build_mine(&merchant1, &mine)) {
          build_mine(&merchant1, &mine, &bank);
          if (player_won(&merchant1)) {
            printf("Player 1 won the game!\n");
            return;
          }
        } else {
          print_invalid_cmd_error();
        }
      } else {
        if (can_build_mine(&merchant2, &mine)) {
          build_mine(&merchant2, &mine, &bank);
          if (player_won(&merchant2)) {
            printf("Player 2 won the game!\n");
            return;
          }
        } else {
          print_invalid_cmd_error();
        }
      }

    }
  }
}

// DO NOT MODIFY THE SIX FUNCTIONS ABOVE
//////////////////////////////////////////////////

int main(void) {
  play_game();
}
