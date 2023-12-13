#include <iostream>
#include "gobang.h"

void Chess::showboard() {
    for (int board_y = 0 ; board_y <= this->length ; board_y++) {
        for (int board_x = 0 ; board_x <= this->width ; board_x++) {
            if (board_x == 0) printf("%5d", board_y);
            else if (board_y == 0) printf("%5d", board_x);
            else printf("%5d", this->chessboard[board_x][board_y]); 
        }
        std::cout << std::endl;
    }
}

std::vector<std::pair<int,int>> Chess::get_live_die(int pos_x, int pos_y) {
    // left to right and up to doun
    int sum_leftright = 0, sum_leftright_live = 0, sum_updown = 0, sum_updown_live = 0;
    for (int shift = -1 ; shift >= -5 ; shift --) {
        if (this->chessboard[pos_x + shift][pos_y] == player) {
            sum_leftright += 1;
        } else if (this->chessboard[pos_x + shift][pos_y] == 0){
            sum_leftright_live += 1;
            break;
        } else {
            break;
        }

        if (this->chessboard[pos_x][pos_y + shift] == player) {
            sum_updown += 1;
        } else if (this->chessboard[pos_x][pos_y + shift] == 0){
            sum_updown_live += 1;
            break;
        } else {
            break;
        }
    }

    for (int shift = 1; shift <= 5 ; shift ++) {
        if (this->chessboard[pos_x + shift][pos_y] == player) {
            sum_leftright += 1;
        } else if (this->chessboard[pos_x + shift][pos_y] == 0){
            sum_leftright_live += 1;
            break;
        } else {
            break;
        }
        
        if (this->chessboard[pos_x][pos_y + shift] == player) {
            sum_updown += 1;
        } else if (this->chessboard[pos_x][pos_y + shift] == 0){
            sum_updown_live += 1;
            break;
        } else {
            break;
        }
    }

    // left up to left down and right down to right up 
    int sum_leftup = 0, sum_leftup_live = 0, sum_rightup = 0, sum_rightup_live = 0;
    for (int shift = -1 ; shift >= -5 ; shift --) {
        if (this->chessboard[pos_x + shift][pos_y + shift] == player) {
            sum_leftup += 1;
        } else if (this->chessboard[pos_x + shift][pos_y + shift] == 0){
            sum_leftup_live += 1;
            break;
        } else {
            break;
        }

        if (this->chessboard[pos_x + shift][pos_y - shift] == player) {
            sum_rightup += 1;
        } else if (this->chessboard[pos_x + shift][pos_y - shift] == 0){
            sum_rightup_live += 1;
            break;
        } else {
            break;
        }
    }

    for (int shift = 1; shift <= 5 ; shift ++) {
        if (this->chessboard[pos_x + shift][pos_y + shift] == player) {
            sum_leftup += 1;
        } else if (this->chessboard[pos_x + shift][pos_y + shift] == 0){
            sum_leftup_live += 1;
            break;
        } else {
            break;
        }

        if (this->chessboard[pos_x + shift][pos_y - shift] == player) {
            sum_rightup += 1;
        } else if (this->chessboard[pos_x + shift][pos_y - shift] == 0){
            sum_rightup_live += 1;
            break;
        } else {
            break;
        }
    }

    //return all situation
    std::vector<std::pair<int,int>> result(4);
    result[0] = std::make_pair(sum_leftright, sum_leftright_live);
    result[1] = std::make_pair(sum_updown, sum_updown_live);
    result[2] = std::make_pair(sum_leftup, sum_leftup_live);
    result[3] = std::make_pair(sum_rightup, sum_rightup_live);
    return result;
}

bool Chess::checkwin(int pos_x, int pos_y, int player) {
    this->live_die = this->get_live_die(pos_x, pos_y);
    for (int direct = 0 ; direct < 4 ; direct++) {
        if (this->live_die[direct].first >= 5) 
            return true;
    }
    return false;
}

void point_chart::_init_(){
    this->point[2][1] = 10;
    this->point[2][2] = 50;
    this->point[3][1] = 40;
    this->point[3][2] = 100;
    this->point[4][1] = 200;
    this->point[4][2] = 1000;
    this->point[5][0] = 10000;
    this->point[5][1] = 10000;
    this->point[5][2] = 10000;
}

void user::_init_(int player){
    this->player = player;
}