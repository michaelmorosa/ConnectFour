//
// Created by micha on 6/23/2021.
//

#ifndef CONNECTFOUR_GAME_H
#define CONNECTFOUR_GAME_H

class game {
public:
    game();
    void play();
    bool gameOver();
    void declareWinner() const;
    bool verticalWin();
    bool horizontalWin();
    void rightDiagonalCoord();
    bool rightDiagonalWin();
    void leftDiagonalCoord();
    bool leftDiagonalWin();
    bool tie();
    void declareTie();
    bool valid();

private:
    char playersSymbol1;
    char playersSymbol2;
    bool turn;
    int playersMove = -2;
    char * boardState;
    int board_row = -2;
    char currentSymbol;
    int diagMaxX;
    int diagMaxY;
    int diagMinX;
    int diagMinY;
    int diagMaxX_dummy;
    int diagMaxY_dummy;
    int count;
};


#endif //CONNECTFOUR_GAME_H
