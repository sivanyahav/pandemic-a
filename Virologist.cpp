#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player& Virologist:: treat(City c) {
    if(!cards.count(c)){ throw std::invalid_argument{"illegal action: you do not have the card of " + cityToString(c)};}
    else if(board[c] == 0){  throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    else if(board.cureDiscoverd(c)){board[c]=0;}
    else{
        board[c]--;
    }
    return *this;
}