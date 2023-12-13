#include "gobang.h"

struct point_desige{
    int value[7][5] = {0};
    void point_desige::_init_() {
        this->value[2][1] = 10;
        this->value[2][2] = 50;
        this->value[3][1] = 40;
        this->value[3][2] = 100;
        this->value[4][1] = 200;
        this->value[4][2] = 1000;
        this->value[5][0] = 10000;
        this->value[5][1] = 10000;
        this->value[5][2] = 10000;
    }
};

chess_coordinate minmax_algorithm();
chess_coordinate alpha_beta_pruning();
chess_coordinate optimization_alpha_beta_pruning();