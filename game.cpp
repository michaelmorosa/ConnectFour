//
// Created by micha on 6/23/2021.
//
#include "board.h"
#include "game.h"
#include "player.h"
#include "move.h"
#include <iostream>

game::game(){
    turn = true;
}

void game::play() {
    //create board object
    board boardObject(6, 7);

    //create move object
    move moveObject;

    //initialize board state
    boardObject.initialize_board();

    //initialize player names and symbols
    player player1('1');
    player player2('2');

    while(true){
        player1.getPlayerSymbol();
        player2.getPlayerSymbol();
        playersSymbol1 = player1.retreiveSymbol();
        playersSymbol2 = player2.retreiveSymbol();
        if((playersSymbol1 == playersSymbol2) || (playersSymbol1 == '*') || (playersSymbol2 == '*')){
            printf("%s\n","Invalid symbol options. Please Choose Again.");
            continue;
        }
        break;
    }

    printf("\n");
    printf("When making a move, enter the column number you want to place your piece in");
    printf("\n");
    printf("Player 1 goes first");
    printf("\n");

    //begin game
    while(true){
        //check if the game is over
        //check for win or if it's a draw
        if(gameOver()){
            boardObject.print_board();
            declareWinner();
            break;
        }
        else if(tie()){
            boardObject.print_board();
            declareTie();
            break;
        }
        else{
            //print the state of the board
            boardObject.print_board();

            printf("\n");

            //determine who's turn it is
            if (turn){ //player 1's turn
                playersMove = moveObject.getMove('1');
                boardState = boardObject.getBoardState();
                if(!valid()){
                    continue;
                }
                turn = !turn;
                board_row = moveObject.makeMove(boardState);
                if(board_row == -1){
                    turn = !turn;
                    continue;
                }else{
                    boardObject.changeBoardState(board_row, playersMove, playersSymbol1);
                }
            }else{ //player 2's turn
                playersMove = moveObject.getMove('2');
                boardState = boardObject.getBoardState();
                if(!valid()){
                    continue;
                }
                turn = !turn;
                board_row = moveObject.makeMove(boardState);
                if(board_row == -1){
                    turn = !turn;
                    continue;
                }else{
                    boardObject.changeBoardState(board_row, playersMove, playersSymbol2);
                }
            }
        }
    }
}


bool game::valid(){
    for(int i = 0; i < 7; i++){
        if(((playersMove < 0) || (playersMove > 6)) || ((*(boardState + i) != '*') && (playersMove == i))){
            printf("%s\n", "Invalid Input. Try Again.");
            return(false);
        }
    }
    return(true);
}


bool game::gameOver() {
    if(verticalWin() || horizontalWin() || rightDiagonalWin() || leftDiagonalWin()){
        return (true);
    }
    else{
        return(false);
    }
}


void game::declareWinner() const {
    printf("\n");
    printf("%s", "The Game is Over.");
    printf("\n");
    if(turn){
        printf("%s", "Player 2 is the Winner.");
    }else{
        printf("%s", "Player 1 is the Winner.");
    }
}


bool game::tie(){
    if(((playersMove) == -2) || ((board_row) == -2)){
        return(false);
    }
    else{
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                if(*(boardState + i * 7 + j) == '*'){
                    return(false);
                }
            }
        }
        return(true);
    }
}


void game::declareTie() {
    printf("\n");
    printf("%s", "The Game is Over.");
    printf("\n");
    printf("%s", "The Game has Ended in a Tie.");
}


bool game::verticalWin() {
    if(((playersMove) == -2) || ((board_row) == -2)){
        return(false);
    }
    else if(turn){
        currentSymbol = playersSymbol2;
    }
    else{
        currentSymbol = playersSymbol1;
    }
    for (int i = 0; i < 3; i++) {
        int counter = 0;
        for (int j = i; j < (i + 5); j++) {
            if (counter == 4) {
                return (true);
            } else if (*(boardState + j * 7 + playersMove) == currentSymbol) {
                counter++;
            } else {
                break;
            }
        }
    }
    return(false);
}


bool game::horizontalWin() {
    if(((playersMove) == -2) || ((board_row) == -2)){
        return(false);
    }
    else if(turn){
        currentSymbol = playersSymbol2;
    }
    else{
        currentSymbol = playersSymbol1;
    }
    for (int i = 0; i < 4; i++) {
        int counter = 0;
        for (int j = i; j < (i + 5); j++) {
            if (counter == 4) {
                return (true);
            } else if (*(boardState + board_row * 7 + j) == currentSymbol) {
                counter++;
            } else {
                break;
            }
        }
    }
    return(false);
}


void game::rightDiagonalCoord(){
    diagMaxX = playersMove;
    diagMaxY = board_row;
    while(true){
        if((diagMaxX == 6) || (diagMaxY == 0)){
            break;
        }else{
            diagMaxX = diagMaxX + 1;
            diagMaxY = diagMaxY - 1;
        }
    }
    diagMinX = playersMove;
    diagMinY = board_row;
    while(true){
        if((diagMinX == 0) || (diagMinY == 5)){
            break;
        }else{
            diagMinX = diagMinX - 1;
            diagMinY = diagMinY + 1;
        }
    }
}


bool game::rightDiagonalWin(){
    if(((playersMove) == -2) || ((board_row) == -2)){
        return(false);
    }
    else if(turn){
        currentSymbol = playersSymbol2;
    }
    else{
        currentSymbol = playersSymbol1;
    }
    rightDiagonalCoord();
    if((diagMinY - diagMaxY) < 3){
        return(false);
    }
    else{
        while(true){
            diagMaxX_dummy = diagMaxX;
            diagMaxY_dummy = diagMaxY;
            count = 0;
            if((diagMaxX < diagMinX) && (diagMaxY > diagMinY)){
                return(false);
            }
            else{
                while(true){
                    if(count == 4){
                        return(true);
                    }
                    else if((diagMaxX_dummy < diagMinX) && (diagMaxY_dummy > diagMinY)){
                        break;
                    }
                    else if(*(boardState + diagMaxY_dummy * 7 + diagMaxX_dummy) == currentSymbol){
                        diagMaxX_dummy = diagMaxX_dummy - 1;
                        diagMaxY_dummy = diagMaxY_dummy + 1;
                        count++;
                    }
                    else{
                        break;
                    }
                }
            }
            diagMaxX = diagMaxX - 1;
            diagMaxY = diagMaxY + 1;
        }
    }
}


void game::leftDiagonalCoord() {
    diagMaxX = playersMove;
    diagMaxY = board_row;
    while(true){
        if((diagMaxX == 0) || (diagMaxY == 0)){
            break;
        }else{
            diagMaxX = diagMaxX - 1;
            diagMaxY = diagMaxY - 1;
        }
    }
    diagMinX = playersMove;
    diagMinY = board_row;
    while(true){
        if((diagMinX == 6) || (diagMinY == 5)){
            break;
        }else{
            diagMinX = diagMinX + 1;
            diagMinY = diagMinY + 1;
        }
    }
}


bool game::leftDiagonalWin(){
    if(((playersMove) == -2) || ((board_row) == -2)){
        return(false);
    }
    else if(turn){
        currentSymbol = playersSymbol2;
    }
    else{
        currentSymbol = playersSymbol1;
    }
    leftDiagonalCoord();

    if((diagMinY - diagMaxY) < 3){
        return(false);
    }
    else{
        while(true){
            diagMaxX_dummy = diagMaxX;
            diagMaxY_dummy = diagMaxY;
            count = 0;
            if((diagMaxX > diagMinX) && (diagMaxY > diagMinY)){
                return(false);
            }
            else{
                while(true){
                    if(count == 4){
                        return(true);
                    }
                    else if((diagMaxX_dummy > diagMinX) && (diagMaxY_dummy > diagMinY)){
                        break;
                    }
                    else if(*(boardState + diagMaxY_dummy * 7 + diagMaxX_dummy) == currentSymbol){
                        diagMaxX_dummy = diagMaxX_dummy + 1;
                        diagMaxY_dummy = diagMaxY_dummy + 1;
                        count++;
                    }
                    else{
                        break;
                    }
                }
            }
            diagMaxX = diagMaxX + 1;
            diagMaxY = diagMaxY + 1;
        }
    }
}


//Process
//initialize game board state
//one player picks a symbol
//the other player picks a symbol

//player 1 makes the first move
//player can place symbol in any column, as long as it isn't full
//symbol replaces the bottommost unoccupied symbol
//players switch off after each other's turns until one person gets 4 in a row
//this can be 4 horizontally, vertically, or diagonally
//winner is declared