#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player& Medic::treat(City c) {
    if(city != c){ throw std::invalid_argument{"illegal action: you are not in city " + cityToString(c)};}
    else if(board[c] == 0){  throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    else if(board.cureDiscoverd(c)){board[c]=0;/***add actions**/}
    else{
        board[c]=0;
    }
    return *this;
}
