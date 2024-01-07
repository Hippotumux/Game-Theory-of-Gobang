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
    int width = 15, length = 15;
    int player;
    int chessboard[17][17] = {0};
};


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

