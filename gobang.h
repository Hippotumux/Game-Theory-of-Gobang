#pragma once
#include <pair>
#include <vector>

class Chess:
{
public:
    // chessboard width and length
    int width = 15, length = 15;
    
    // player1 user, player2 computer 
    int player;

    // 0 : empty, 1 : player1, 2 : player2
    int chessboard[width+2][length+2] = {0};

    // 4 direction live and die;
    std::vector<std::pair<int,int>> live_die;
    std::vector<std::pair<int,int>> get_live_die() {};

    void showboard(void) {};
    bool checkwin(int pos_x, int pos_y, int player) {};
} 

class point_chart
{
public:
    // point[x][y] : x is the chess live, y is the chess die
    int point[7][5] = {0};
    void init() {};
}

class user: public Chess
{
public:
    int choose_x, int choose_y;
    player = 1;
}

class minmax_algorithm : public Chess
{
public:
    
}