#pragma once
#include <iostream>
#include <vector>

typedef std::pair<int,int> chess_coordinate;

std::vector<chess_coordinate> get_live_die(int pos_x, int pos_y, int player, int chessboard[17][17]);
bool check_round (int pos_x, int pos_y, int round_size, int chessboard[17][17]);

class game_algorithm
{
public:
    int choose_x, choose_y, round_size, best_value = -1e8, max_depth;
    int value[7][5] = {0};
    int eval_chessboard[17][17] = {0};
    std::vector<chess_coordinate> live_die;
    const int winpoint = 10000;
    game_algorithm() {
        this->value[2][1] = 10;
        this->value[2][2] = 50;
        this->value[3][1] = 40;
        this->value[3][2] = 100; 
        this->value[4][1] = 200;
        this->value[4][2] = 1000;
        this->value[5][0] = winpoint;
        this->value[5][1] = winpoint;
        this->value[5][2] = winpoint;
    }
    bool checkwin (int pos_x, int pos_y, int player, int chessboard[17][17]);
    int minmax_algorithm(int depth, int maxdepth, int player, int chessboard[17][17]);
    chess_coordinate alpha_beta_pruning();
    chess_coordinate optimization_alpha_beta_pruning();
};

