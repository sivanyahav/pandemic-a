#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Scientist: public Player{
        int num;
        public:
        Scientist(Board& b, City c, int n): Player(b, c), num(n){this->player_role = "Scientist";};
        Player& discover_cure(Color c) override;
    };
} 