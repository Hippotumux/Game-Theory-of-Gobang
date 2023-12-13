#include "game_algorithm.h"
#include "gobang.h"

bool game_algorithm::check_round(int pos_x, int pos_y, int round_size) {
    if (chess[pos_x][pos_y] != 0) return false;
    for (int shift_x = -round_size ; shift_x <= round_size ; shift_x ++) {
        for (int shift_y = -round_size ; shift_y <= round_size ; shift_y ++) {
            if (pos_x + shift_x <= 0 || pos_x + shift_x > 15 || pos_y + shift_y < 0 || pos_y + shift_y > 15) continue;
            if (this->chessboard[pos_x + shift_x][pos_y + shift_y] != 0) return true;
        }
    }
    return false;
}

int game_algorithm::minmax_algorithm(int depth, int maxdepth, int player) {
    if (depth >= max_depth) {
        int point_max = -1e8;
        for (int chess_y = 1 ; chess_y <= 15 ; chess_y ++) {
            for (int chess_x = 1 ; chess_x <= 15 ; chess_x ++) {
                if (check_round(chess_x, chess_y, 1)) {
                    int total_point = 0;
                    this->live_die = this->get_live_die(chess_x, chess_y, player);
                    for (auto item : this->live_die) {
                        total_point += this->value[item.first][item.second];
                    }
                    point_max = std::max(point_max, total_point);   
                }
            }
        }
        return point_max;
    }

    int point_max = -1e8, point_min = 1e8;
    for (int chess_y = 1 ; chess_y <= 15 ; chess_y ++) {
        for (int chess_x = 1 ; chess_x <= 15 ; chess_x ++) {
            if (check_round(chess_x, chess_y, this->roundsize)) {
                if (this->checkwin(chess_x, chess_y, player)) {
                    if (player == 2)
                        return this->winpoint;
                    else
                        return -1 * this->winpoint;
                }
                if (player == 2) {
                    point_min = std::min(point_min, minmax_algorithm(depth, maxdepth, 1));
                } else {
                    point_max = std::max(point_max, minmax_algorithm(depth + 1, maxdepth, 2));
                }

                if (player == 2 && depth == 1) {
                    if (point_min > this->best_value) {
                        this->best_value = point_min;
                        this->choose_x = chess_x;
                        this->choose_y = chess_y;
                    }
                } 
            }
        }
    }
    if (player == 2) {
        return point_min;
    } else {
        return point_max;
    }
}

chess_coordinate game_algorithm::alpha_beta_pruning() {
    chess_coordinate test;
    return test;
}

chess_coordinate game_algorithm::optimization_alpha_beta_pruning() {
    chess_coordinate test;
    return test;
}
