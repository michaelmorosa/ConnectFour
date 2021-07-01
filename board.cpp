//
// Created by micha on 6/23/2021.
//

#include "board.h"
#include <iostream>

board::board(int x, int y) {
    width = x;
    height = y;
}


void board::initialize_board(){
    //fill up 2-d array with content
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j ++){
            board_state[i][j] = '*';
        }
    }
}

void board::print_board() {
    //print content of board
    for(int i = 0; i  < 7; i++){
        printf(" %d",i);
    }
    for(int i = 0; i < width; i++){
        printf("\n");
        for(int j = 0; j < height; j ++){
            printf(" %c",board_state[i][j]);
        }
    }
}

char * board::getBoardState(){
    board_param = *board_state;
    return (board_param);
}

void board::changeBoardState(int row, int column, char playersSymbol) {
    board_state[row][column] = playersSymbol;
}
