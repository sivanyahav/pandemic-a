#include "Player.hpp"

using namespace std;
using namespace pandemic;

Player& Player:: drive(City c){
    if(board.isConnected(city, c)){city=c;}
    else{throw std::invalid_argument{"Illegal action: "+ cityToString(city)+"is not connected to"+cityToString(c)};}
    return *this;
}

Player& Player:: fly_direct(City c){
    if(cards.count(c)){
        city=c;
        cards.erase(c);
    }
    else{throw std::invalid_argument{"illegal action: you do not have the card of "+cityToString(c)};}
    return *this;
}
Player& Player::fly_charter(City c){
    if(cards.count(city)){
        cards.erase(city);
        city=c;
    }
    else{throw std::invalid_argument{"illegal action: you do not have the card of "+cityToString(city)};}
    return *this;
}
Player& Player::fly_shuttle(City c){
    if(board.isResearchStation(city) && board.isResearchStation(c)){city=c;}
    else{throw std::invalid_argument{"Illegal action: " + cityToString(city) + " and " + cityToString(c) + " must both have research station."};}
    return *this;
}
Player& Player::build(){
    if(!cards.count(city)){throw std::invalid_argument{"Illegal action: you do not have the card of "+cityToString(city)};}
    if(!board.isResearchStation(city)){
        board.buildStation(city);
        cards.erase(city);
    }
    return *this;
}
Player& Player:: discover_cure(Color c){
    return *this;
}
Player& Player:: treat(City c){
    if(city != c){ throw std::invalid_argument{"illegal action: you are not in city " + cityToString(c)};}
    else if(board[c] == 0){  throw std::invalid_argument{"illegal action: no more cubes remain in city " + cityToString(c)};}
    else if(board.cureDiscoverd(c)){board[c]=0;}
    else{
        board[c]--;
    }
    return *this;
}

Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}