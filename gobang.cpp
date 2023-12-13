#include gobang.h

void ChessMap::showboard() {
    for (int board_y = 0 ; board_y <= this->length ; board_y++) {
        for (int board_x = 0 ; board_x <= this->width ; board_x++) {
            std::cout << this->chessboard[board_x][board_y] << " ";
        }
        std::cout << std::endl;
    }
}

void ChessMap::checkwin(int pos_x, int pos_y) {
    
}

void point_chart::init() {
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
