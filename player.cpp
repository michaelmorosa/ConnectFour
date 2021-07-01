//
// Created by micha on 6/23/2021.
//
#include <iostream>
#include "player.h"

player::player(char x){
    player_number = x;
};

void player::getPlayerSymbol() {
    symbolQuestion[28] = player_number;
    symbolQuestion[29] = ':';
    symbolQuestion[30] = ' ';
    symbolQuestion[31] = '\0';
    int i = 0;
    while(true){
        if(symbolQuestion[i] != '\0'){
            printf("%c", symbolQuestion[i]);
            i = i + 1;
        }
        else{
            std::cin >> symbol;
            if((symbol.size() > 1) || (symbol.empty())){
                std::cin.clear();
                std::cin.ignore(1234, '\n');
                i = 0;
                printf("%s\n","Invalid Symbol. Please Choose Again.");
                continue;
            }
            player_symbol = symbol[0];
            break;
        }
    }
}


char player::retreiveSymbol() {
    return(player_symbol);
}