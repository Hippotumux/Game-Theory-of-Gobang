#include "gobang.h"

void showmap (int chessboard[17][17]) {
    for (int board_y = 0 ; board_y < 17 ; board_y++) {
        for (int board_x = 0 ; board_x < 17 ; board_x++) {
            if (board_x == 0) printf("%5d", board_y);
            else if (board_y == 0) printf("%5d", board_x); 
            else printf("%5d", chessboard[board_x][board_y]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// init user player
void user::_init_(int player){
    this->player = player;
}

// init computer player
void computer::_init_(int player, int round_size, int max_depth) {
    this->player = player;
    this->round_size = round_size;
    this->max_depth = max_depth;
}


// Computer choose
void computer::Computer_Choose() {
    this->best_value = -1e8;
    memset(this->eval, 0, sizeof(this->eval));
    std::cout <<  "Max point:" 
        << this->minmax_algorithm(1, this->max_depth, this->player, this->chessboard) << std::endl;
    
    
    for (int i = 1 ; i <= 15 ; i++) {
        for (int j = 1 ; j <= 15 ; j++) {
            printf("%6d", this->eval[j][i]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
