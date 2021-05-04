#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player& OperationsExpert:: build(){
    board.buildStation(city);
    return *this;
}