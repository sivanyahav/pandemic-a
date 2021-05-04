#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher:: fly_direct(City c){
    if(board.isResearchStation(city)){
        city=c;
        return *this;
    }
    else{
        return Player:: fly_direct(c);
    }
}
