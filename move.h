//
// Created by micha on 6/24/2021.
//

#ifndef CONNECTFOUR_MOVE_H
#define CONNECTFOUR_MOVE_H
#include <string>

class move {
public:
    move();
    int getMove(char player_number);
    int makeMove(char * boardState);
    int validate_move(char * boardState);

private:
    char moveQuestion[50] = {'W','h','a','t',' ','i','s',' ', 'y','o','u','r',' ', 'm','o','v','e',',',' ','p','l','a','y','e','r',' ','\0'};
    int playersMove;
    int viable_row;
    std::string var;
};


#endif //CONNECTFOUR_MOVE_H
