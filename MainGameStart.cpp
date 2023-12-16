#include "gobang.h"
#include "game_algorithm.h"

Chess game;
//point_chart Score;
user player1;
//user player2;
computer Agent;

int main(void) {
    // init two player
    player1._init_(1);
    //player2._init_(2);
    Agent._init_(2, 3, 2);
    // Score._init_();

    bool running = true;
    while (running) {
        // player 1 first
        showmap(game.chessboard);
        do {
            std::cout << "please player 1 choose x and y : "; 
            std::cin >> player1.choose_x >> player1.choose_y;
            if (player1.choose_x < 0 || player1.choose_y < 0 || player1.choose_x > 15 || player1.choose_y > 15) continue; 
        } while (game.chessboard[player1.choose_x][player1.choose_y] != 0);
        game.chessboard[player1.choose_x][player1.choose_y] = player1.player;

        // copy game chessboard to player chess board
        memcpy(player1.chessboard, game.chessboard, sizeof(game.chessboard));
        
        // check player2 whether win
        if (player1.checkwin(player1.choose_x, player1.choose_y, player1.player, player1.chessboard)) {
            showmap(game.chessboard);
            std::cout << "player1 win";
            running = false;
            break;
        }

        memcpy(Agent.chessboard, game.chessboard, sizeof(game.chessboard));
        Agent.Computer_Choose();
        std::cout << "Computer choose " << Agent.choose_x << " " << Agent.choose_y << std::endl;
        
        game.chessboard[Agent.choose_x][Agent.choose_y] = Agent.player;

        /*
        // next for player 2
        game.showboard();
        do{
            std::cout << "please player 2 choose x and y : "; 
            std::cin >> player2.choose_x >> player2.choose_y;
            if (player2.choose_x < 0 || player2.choose_y < 0 || player2.choose_x > 15 || player2.choose_y > 15) continue; 
        } while (game.chessboard[player2.choose_x][player2.choose_y] != 0);
        game.chessboard[player2.choose_x][player2.choose_y] = player2.player;

        // copy game chessboard to player chess board
        memcpy(player2.chessboard, game.chessboard, sizeof(game.chessboard));

        // check whether player2 win
        if (player2.checkwin(player2.choose_x, player2.choose_y, player2.player)) {
            game.showboard();
            std::cout << "player2 win";
            running = false;
            break;
        }
        */


    }
}

