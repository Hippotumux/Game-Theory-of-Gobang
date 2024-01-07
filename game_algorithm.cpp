#include "game_algorithm.h"

std::mt19937 rng(std::random_device{}());

std::vector<chess_coordinate> get_live_die(int pos_x, int pos_y, int player, int chessboard[17][17]) {
    // left to right and up to doun
    int sum_leftright = 1, sum_leftright_live = 0, sum_updown = 1, sum_updown_live = 0;
    for (int shift = -1 ; shift >= -5, pos_x + shift > 0 ; shift --) {
        if (chessboard[pos_x + shift][pos_y] == player) {
            sum_leftright += 1;
        } else if (chessboard[pos_x + shift][pos_y] == 0) {
            sum_leftright_live += 1;
            break;
        } else {
            break;
        }
    }
    for (int shift = -1 ; shift >= -5 && pos_y + shift > 0 ; shift --) {
        if (chessboard[pos_x][pos_y + shift] == player) {
            sum_updown += 1;
        } else if (chessboard[pos_x][pos_y + shift] == 0) {
            sum_updown_live += 1;
            break;
        } else {
            break;
        }
    }
    for (int shift = 1; shift <= 5 && pos_x + shift <= 15 ; shift ++) {
        if (chessboard[pos_x + shift][pos_y] == player) {
            sum_leftright += 1;
        } else if (chessboard[pos_x + shift][pos_y] == 0) {
            sum_leftright_live += 1;
            break;
        } else {
            break;
        }
    }
    for (int shift = 1; shift <= 5 && pos_x + shift <= 15 ; shift ++) {    
        if (chessboard[pos_x][pos_y + shift] == player) {
            sum_updown += 1;
        } else if (chessboard[pos_x][pos_y + shift] == 0) {
            sum_updown_live += 1;
            break;
        } else {
            break;
        }
    }

    
 
    // left up to left down and right down to right up 
    int sum_leftup = 1, sum_leftup_live = 0, sum_rightup = 1, sum_rightup_live = 0;
    for (int shift = -1 ; shift >= -5 && pos_x + shift > 0 && pos_y + shift > 0; shift --) {
        if (chessboard[pos_x + shift][pos_y + shift] == player) {
            sum_leftup += 1;
        } else if (chessboard[pos_x + shift][pos_y + shift] == 0) {
            sum_leftup_live += 1;
            break;
        } else {
            break;
        }
    }

    for (int shift = -1 ; shift >= -5 && pos_x + shift > 0 && pos_y - shift <= 15; shift --) {
        if (chessboard[pos_x + shift][pos_y - shift] == player) {
            sum_rightup += 1;
        } else if (chessboard[pos_x + shift][pos_y - shift] == 0) {
            sum_rightup_live += 1;
            break;
        } else {
            break;
        }
    }

    for (int shift = 1; shift <= 5 && pos_x + shift <= 15 && pos_y + shift <= 15 ; shift ++) {
        if (chessboard[pos_x + shift][pos_y + shift] == player) {
            sum_leftup += 1;
        } else if (chessboard[pos_x + shift][pos_y + shift] == 0) {
            sum_leftup_live += 1;
            break;
        } else {
            break;
        }
    }
    for (int shift = 1; shift <= 5 && pos_x + shift <= 15 && pos_y - shift > 0 ; shift ++) {
        if (chessboard[pos_x + shift][pos_y - shift] == player) {
            sum_rightup += 1;
        } else if (chessboard[pos_x + shift][pos_y - shift] == 0) {
            sum_rightup_live += 1;
            break;
        } else {
            break;
        }
    }

    //return all situation
    std::vector<chess_coordinate> result(4);
    result[0] = std::make_pair(sum_leftright, sum_leftright_live);
    result[1] = std::make_pair(sum_updown, sum_updown_live);
    result[2] = std::make_pair(sum_leftup, sum_leftup_live);
    result[3] = std::make_pair(sum_rightup, sum_rightup_live);
    return result;
}

// check win 
bool game_algorithm::checkwin(int pos_x, int pos_y, int player, int chessboard[17][17]) {
    this->live_die = get_live_die(pos_x, pos_y, player, chessboard);
    for (int direct = 0 ; direct < 4 ; direct++) {
        if (this->live_die[direct].first >= 5)
            return true;
    }
    return false;
}


// check the coordinate round whether exist another;
bool check_round(int pos_x, int pos_y, int round_size, int chessboard[17][17]) {
    if (chessboard[pos_x][pos_y] != 0) return false;
    for (int shift_x = -round_size ; shift_x <= round_size ; shift_x ++) {
        for (int shift_y = -round_size ; shift_y <= round_size ; shift_y ++) {
            if (pos_x + shift_x <= 0 || pos_x + shift_x > 15 || pos_y + shift_y < 0 || pos_y + shift_y > 15) continue;
            if (chessboard[pos_x + shift_x][pos_y + shift_y] != 0) return true;
        }
    }
    return false;
}

// minmax 
int game_algorithm::minmax_algorithm(int depth, int maxdepth, int player, int chessboard[17][17]) {
    if (depth >= max_depth) {
        int point_max = -1e8;
        for (int chess_y = 1 ; chess_y <= 15 ; chess_y ++) {
            for (int chess_x = 1 ; chess_x <= 15 ; chess_x ++) {
                if (check_round(chess_x, chess_y, 1, chessboard)) {
                    int total_point = 0; 
                    this->live_die = get_live_die(chess_x, chess_y, player, chessboard);
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
            if (player == 2 && depth == 1) point_max = -1e8;

            if (check_round(chess_x, chess_y, this->round_size, chessboard)) {
                if (this->checkwin(chess_x, chess_y, player, chessboard)) {
                    if (depth == 1) {
                        this->choose_x = chess_x;
                        this->choose_y = chess_y;
                    }
                    if (player == 2)
                        return this->winpoint;
                    else
                        return -1 * this->winpoint;
                }
                if (player == 2) {
                    chessboard[chess_x][chess_y] = player;
                    point_max = std::max(point_max, minmax_algorithm(depth , maxdepth, 1, chessboard));
                    chessboard[chess_x][chess_y] = 0;
                } else {
                    chessboard[chess_x][chess_y] = player;
                    point_min = std::min(point_min, minmax_algorithm(depth + 1, maxdepth, 2, chessboard));
                    chessboard[chess_x][chess_y] = 0;
                }

                if (player == 2 && depth == 1) {
                    point_max = (point_max * this->weight[chess_x][chess_y] * (10+rng()%10))/10;
                    if (point_max > this->best_value) {
                        this->best_value = point_max;
                        this->choose_x = chess_x;
                        this->choose_y = chess_y;
                    }
                    this->eval_chessboard[chess_x][chess_y] = point_max;
                }
            }
        }
    }

    if (player == 2  && depth == 1) return best_value;
    
    if (player == 2) {
        return point_max;
    } else {
        return point_min;
    }
}

// alpha: min  beta:max   
int game_algorithm::alpha_beta_pruning(AlphaBeta last_eval, int depth, int maxdepth, int player, int chessboard[17][17]) {
    AlphaBeta now_eval = last_eval;
    if (depth >= max_depth) {
        int point_max = -1e8;
        for (int chess_y = 1 ; chess_y <= 15 ; chess_y ++) {
            for (int chess_x = 1 ; chess_x <= 15 ; chess_x ++) {
                if (check_round(chess_x, chess_y, 1, chessboard)) {
                    int total_point = 0; 
                    this->live_die = get_live_die(chess_x, chess_y, player, chessboard);
                    for (auto item : this->live_die) {
                        total_point += this->value[item.first][item.second];
                    }
                    point_max = std::max(point_max, total_point);
                }
            }
        }
        return point_max;
    }

    for (int chess_y = 1 ; chess_y <= 15 ; chess_y ++) {
        for (int chess_x = 1 ; chess_x <= 15 ; chess_x ++) {

            if (check_round(chess_x, chess_y, this->round_size, chessboard)) {
                // check win 
                if (this->checkwin(chess_x, chess_y, player, chessboard)) {
                    if (depth == 1) {
                        this->choose_x = chess_x;
                        this->choose_y = chess_y;
                    }
                    if (player == 2)
                        return this->winpoint * 1.2;
                    else
                        return -1 * this->winpoint * 1.2;
                }

                if (player == 2) {
                    chessboard[chess_x][chess_y] = player;
                    int return_point = alpha_beta_pruning(now_eval, depth , maxdepth, 1, chessboard);
                    now_eval.alpha = std::max(now_eval.alpha, return_point);
                    chessboard[chess_x][chess_y] = 0;
                } else {
                    chessboard[chess_x][chess_y] = player;
                    int return_point = alpha_beta_pruning(now_eval, depth + 1, maxdepth, 2, chessboard);
                    now_eval.beta = std::min(now_eval.beta, return_point);
                    chessboard[chess_x][chess_y] = 0;
                }
                
                // Here is my last edit situation
                if (now_eval.alpha >= now_eval.beta) {
                    if (player == 2) {
                        return now_eval.alpha;
                    } else {
                        return now_eval.beta;
                    }
                }

                if (player == 2 && depth == 1) {
                    now_eval.alpha = (now_eval.alpha * this->weight[chess_x][chess_y] * (10 + rng() % 10)) / 10;
                    if (now_eval.alpha > this->best_value) {
                        this->best_value = now_eval.alpha;
                        this->choose_x = chess_x;
                        this->choose_y = chess_y;
                    }
                    this->eval_chessboard[chess_x][chess_y] = now_eval.alpha;
                    now_eval = std::make_pair(-1e8, 1e8);
                }
            }
        }
    }

    if (player == 2  && depth == 1) return best_value;
    
    if (player == 2) {
        return now_eval.alpha;
    } else {
        return now_eval.beta;
    }    
}

chess_coordinate game_algorithm::optimization_alpha_beta_pruning() {
    chess_coordinate test;
    return test;
}
