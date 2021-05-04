#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic{
    class Board{

        static std :: map<City, std::set<City>> connections;
        std :: map<City, int> diseasCubes; //Indicates the level of disease in each city
        std::set<City> research_stations; //Marks the cities that have research stations
        bool cured[4] = {0};

        public:
            Board(){}

            int& operator[] (City c);
            bool is_clean();
            void remove_cures(){};
            friend std::ostream& operator<<(std::ostream& os, const Board& b);

            //////////Help functions////////////////
            bool isConnected(City& c1, City&c2);
            void buildStation(City c);
            bool isResearchStation(City c);
            void mark(Color c);
            bool cureDiscoverd(City c);
            Color getColor(City c);

    };
}