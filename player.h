//
// Created by micha on 6/23/2021.
//

#ifndef CONNECTFOUR_PLAYER_H
#define CONNECTFOUR_PLAYER_H
#include <string>

class player {
public:
    player(char x);
    void getPlayerSymbol();
    char retreiveSymbol();

private:
    char nameQuestion[50] = {'W','h','a','t',' ','i','s',' ', 'y','o','u','r',' ', 'n','a','m','e',',',' ','p','l','a','y','e','r',' ','\0'};
    char symbolQuestion[50] = {'W','h','a','t',' ','i','s',' ', 'y','o','u','r',' ', 's','y','m','b','o','l',',',' ','p','l','a','y','e','r',' ','\0'};
    std::string symbol;
    char player_symbol;
    char player_number;

};


#endif //CONNECTFOUR_PLAYER_H
