#include "doctest.h"
#include <string>
#include <iostream>
#include <vector>


#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

const map<City, vector<City>> cities {
    { City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo } },
    { City::Atlanta, {City::Chicago, City::Miami, City::Washington } },
    { City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi } },
    { City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong } },
    { City::Beijing, {City::Shanghai, City::Seoul } },
    { City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires } },
    { City::BuenosAires, {City::Bogota, City::SaoPaulo } },
    { City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh } },
    { City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta } },
    { City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal } },
    { City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata } },
    { City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg } },
    { City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila } },
    { City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei } },
    { City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow } },
    { City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney } },
    { City::Johannesburg, {City::Kinshasa, City::Khartoum } },
    { City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi } },
    { City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg } },
    { City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg } },
    { City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong } },
    { City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa } },
    { City::Lima, {City::MexicoCity, City::Bogota, City::Santiago } },
    { City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris } },
    { City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney } },
    { City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers } },
    { City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney } },
    { City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota } },
    { City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota } },
    { City::Milan, {City::Essen, City::Paris, City::Istanbul } },
    { City::Montreal, {City::Chicago, City::Washington, City::NewYork } },
    { City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran } },
    { City::Mumbai, {City::Karachi, City::Delhi, City::Chennai } },
    { City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid } },
    { City::Osaka, {City::Taipei, City::Tokyo } },
    { City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London } },
    { City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi } },
    { City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila } },
    { City::Santiago, {City::Lima } },
    { City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid } },
    { City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo } },
    { City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo } },
    { City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow } },
    { City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles } },
    { City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila } },
    { City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi } },
    { City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco } },
    { City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami } }
};

void take5yellowCards(Player& p){
    p.take_card(City::BuenosAires)
    .take_card(City::Bogota)
    .take_card(City::Johannesburg)
    .take_card(City::Khartoum)
    .take_card(City::Lagos);
}


City getConnectedCity(City c){
    return cities.at(c).at(0);
}

City getRandomCity(){
    size_t randNum = (size_t)rand() % (size_t)cities.size();
    for(auto& city: cities){
        if(randNum==0){return city.first;}
        randNum--;
    }
    return Miami;
}


/*
  בדיקת פעולות על הלוח  
*/

TEST_CASE("drive"){
    Board b;

    //check drive to connected city
    for(int i=0; i<20; i++){
        City c = getRandomCity();
        Player p= {b, c};

        CHECK_NOTHROW(p.drive(getConnectedCity(c)));
        
    }
    
}
TEST_CASE("fly_direct"){
    Board b;

    for (int i = 0; i < 20; i++)
    {
        Player p= {b,getRandomCity()};
        take5yellowCards(p);
        //fly to yellow cities
        CHECK_NOTHROW(p.fly_direct(City::BuenosAires).fly_direct(City::Lagos));
        //fly to blue city, illegal action. 
        CHECK_THROWS(p.fly_direct(City::Essen));

    }

}
TEST_CASE("fly_charter"){
    Board b;
    Player p = {b, City::BuenosAires };
    take5yellowCards(p);
    CHECK_NOTHROW(p.fly_charter(City::Bogota).fly_charter(City::Johannesburg));
    CHECK_NOTHROW(p.fly_charter(City::Khartoum).fly_charter(City::Lagos));
    CHECK_NOTHROW(p.fly_charter(City::BuenosAires));

    //illegal action- the player has no card in hand
    CHECK_THROWS(p.fly_charter(City::Jakarta));
}


TEST_CASE("fly_shuttle"){
    Board b;
    for(int i=0; i<20; i++){
        City source = getRandomCity();
        City dest = getRandomCity();
        b.buildStation(source);
        b.buildStation(dest);
        
        Player p = {b, source};
        CHECK_NOTHROW(p.fly_shuttle(dest));
        City notBuild = getRandomCity();
        if(!b.isResearchStation(notBuild)){
            CHECK_THROWS(p.fly_shuttle(notBuild));
        }
    }

}
TEST_CASE("build"){
    Board b;
    for (int i = 0; i < 20; i++)
    {
        City c= getRandomCity();
        Player p1= {b, c};
        p1.take_card(c);
        CHECK_NOTHROW(p1.build());

        City noCard = getRandomCity();
        Player p2= {b, noCard};
        CHECK_THROWS(p2.build());
    }

}
// TEST_CASE("discover_cure"){
//     for (int i = 0; i < 20; i++)
//     {
//       City c = getRandomCity();
//     }
    
// }
// TEST_CASE("treat"){
   

// }

// /*
//   בדיקת שחקנים 
// */

// TEST_CASE("OperationsExpert"){

// }

// TEST_CASE("Dispatcher"){

// }
// TEST_CASE("Scientist"){

// }
// TEST_CASE("Researcher"){

// }
// TEST_CASE("Medic"){

// }
// TEST_CASE("Virologist"){

// }
// TEST_CASE("GeneSplicer"){

// }
// TEST_CASE("FieldDoctor"){

// }