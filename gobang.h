#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include "game_algorithm.h"

typedef std::pair<int,int> chess_coordinate;
void showmap (int chessboard[17][17], int choose_x, int choose_y);

class Chess
{
public:
    // chessboard width and length
    int width = 15, length = 15;
    
    // player1 user, player2 computer 
    int player;

    // 0 : empty, 1 : player1, 2 : player2
    int chessboard[17][17] = {0};

    // 4 direction live and die;
    // std::vector<chess_coordinate> live_die;
    // void showboard();
};

// class point_chart
// {
// public:
//     // point[x][y] : x is the chess live, y is the chess die
//     int point[7][5] = {0};
//     void _init_();
// };

class user: public Chess, public game_algorithm
{
public:
    int choose_x, choose_y, player;
    void _init_(int player);
};

class computer: public Chess, public game_algorithm
{
public:
    void _init_(int player, int round_size, int max_depth);
    void Computer_Choose();
};

/*
class minmax_algorithm : public Chess
{
public:
    
}
*/
