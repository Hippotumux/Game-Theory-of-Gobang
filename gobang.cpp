#include "gobang.h"

void showmap (int chessboard[17][17]) {
    for (int board_y = 0 ; board_y <= 15 ; board_y++) {
        for (int board_x = 0 ; board_x <= 15 ; board_x++) {
            if (board_x == 0) printf("%5d", board_y);
            else if (board_y == 0) printf("%5d", board_x); 
            else {
                if (chessboard[board_x][board_y] == 0) {
                    printf("   ‧");
                } else if (chessboard[board_x][board_y] == 1) {
                    printf("   ●");
                } else {
                    printf("   ○");
                }
            }
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
    // reset best_value and eval_chessboard
    this->best_value = -1e8;
    memset(this->eval_chessboard, 0, sizeof(this->eval_chessboard));

    // output MAX point
    std::cout <<  "Max point:" 
        << this->minmax_algorithm(1, this->max_depth, this->player, this->chessboard) << std::endl;
    
    
    for (int chess_y = 1 ; chess_y <= 15 ; chess_y++) {
        for (int chess_x = 1 ; chess_x <= 15 ; chess_x++) {
            printf("%6d", this->eval_chessboard[chess_x][chess_y]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
