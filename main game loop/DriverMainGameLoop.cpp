//
//  DriverMainGameLoop.cpp
//  main game loop
//
//  Created by Bruno Robert on 12/10/2017.
//  Copyright © 2017 Bruno Robert. All rights reserved.
//

#include "DriverMainGameLoop.hpp"
int main() {
    cout << "hello" << endl;
    Map map;
    
    ContinentNode europe("Europe", 5);
    ContinentNode northAmerica("North America", 5);
    ContinentNode southAmerica("south America", 5);
    ContinentNode asia("Asia", 9);
    asia.addAdjCont(&europe);
    europe.addAdjCont(&asia);
    europe.addAdjCont(&northAmerica);
    northAmerica.addAdjCont(&europe);
    northAmerica.addAdjCont(&southAmerica);
    southAmerica.addAdjCont(&northAmerica);
    
    //creating countries
    
    CountryNode mongolia("Mongolia", &europe);
    CountryNode france("France", &europe);
    CountryNode uk("U.K.", &europe);
    CountryNode spain("Spain", &europe);
    CountryNode china ("China", &asia);
    
    china.addAdjCount(&mongolia);
    mongolia.addAdjCount(&china);
    mongolia.addAdjCount(&france);
    france.addAdjCount(&mongolia);
    france.addAdjCount(&uk);
    france.addAdjCount(&spain);
    uk.addAdjCount(&france);
    spain.addAdjCount(&france);
    
    //adding nodes to map
    map.addContinent(&europe);
    map.addContinent(&northAmerica);
    map.addContinent(&southAmerica);
    map.addContinent(&asia);
    map.addCountry(&mongolia);
    map.addCountry(&france);
    map.addCountry(&uk);
    map.addCountry(&spain);
    map.addCountry(&china);
    
    MainGameLoop mgl;
    mgl.startGame(&map, 2, 1, true);
    return 0;
}