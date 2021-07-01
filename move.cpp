//
// Created by micha on 6/24/2021.
//

#include "move.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

move::move() {
}

int move::getMove(char player_number) {
    moveQuestion[26] = player_number;
    moveQuestion[27] = ':';
    moveQuestion[28] = ' ';
    moveQuestion[29] = '\0';
    int i = 0;
    while(true){
        if((moveQuestion[i] != '\0')){
            printf("%c", moveQuestion[i]);
            i = i + 1;
        }
        else{
            std::cin >> var;
            if (isdigit(var[0]) && (var.size() == 1)) {
                std::stringstream str(var);
                str >> playersMove;
                return (playersMove);
            }else {
                std::cin.clear();
                std::cin.ignore(1234, '\n');
                printf("%s\n","Invalid Move. Please Choose Again.");
                i = 0;
                continue;
               }
            }
        }
    }

int move::makeMove(char * boardState){
    viable_row = validate_move(boardState);
    if(viable_row != -1){
        return (viable_row);
    }
    else{
        return(-1);
    }

}


int move::validate_move(char * boardState) {
    for(int i = 5; i > -1; i--){
        if(*(boardState + i * 7 + playersMove) == '*'){
            return(i);
        }
    }
    return(-1);
}
