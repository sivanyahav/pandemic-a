#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

Player& GeneSplicer:: discover_cure(Color c) {
    if(!board.isResearchStation(city)){throw std::invalid_argument{"illegal action: city "+cityToString(city)+" has no research station!"};}
    if(cards.size()<5){throw std::invalid_argument{"illegal action: You do not have enough cards"};}
    
    ////////add actions//////////
    return *this;
}