//
// Created by micha on 6/23/2021.
//

#ifndef CONNECTFOUR_BOARD_H
#define CONNECTFOUR_BOARD_H


class board {
public:
    board(int x, int y);
    void initialize_board();
    void print_board();
    char * getBoardState();
    void changeBoardState(int row, int column, char playersSymbol);

private:
    int width;
    int height;
    char board_state[6][7];
    char * board_param;
};


#endif //CONNECTFOUR_BOARD_H
