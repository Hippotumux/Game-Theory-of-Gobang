#include "gobang.h"
#include <iostream>
Chess game;
point_chart Score_chart;
user player1;
user player2;
int main(void) {
    player1._init_(1);
    player2._init_(2);
    while (true) {
        game.showboard();
        do{
            std::cout << "please player 1 choose x and y : "; 
            std::cin >> player1.choose_x >> player1.choose_y;
        }while(game.chessboard[player1.choose_x][player1.choose_y] != 0);

        game.chessboard[player1.choose_x][player1.choose_y] = player1.player;
        game.showboard();
        if (player1.checkwin(player1.choose_x, player1.choose_y, player1.player)) {
            std::cout << "player1 win";
            return 0;
        }
        do{
            std::cout << "please player 2 choose x and y : "; 
            std::cin >> player2.choose_x >> player2.choose_y;
        }while(game.chessboard[player2.choose_x][player2.choose_y] != 0);

        game.chessboard[player2.choose_x][player2.choose_y] = player2.player;
        if (player2.checkwin(player2.choose_x, player2.choose_y, player2.player)) {
            std::cout << "player2 win";
            return 0;
        }
    }
}

