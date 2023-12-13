#pragma once

class Chess:
{
public:
    // chessboard width and length
    int width = 15, length = 15;
    int chessboard[width+2][length+2] = {0};
    void showboard(void) {};
    void checkwin(int pos_x, int pos_y) {};
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
}

class minmax_algorithm : public Chess
{
public:
    
}