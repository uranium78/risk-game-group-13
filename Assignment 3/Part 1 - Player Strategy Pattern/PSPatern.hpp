//
//  PSPatern.hpp
//  Risk-fresh-start
//
//  Created by Bruno Robert on 31/10/2017.
//  Copyright © 2017 Bruno Robert. All rights reserved.
//

#ifndef PSPatern_hpp
#define PSPatern_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

#include "Map.h"
using namespace std;
//this is to be the parent class of Human Agressive and Benevolent
class PlayerStrategyPattern {
public:
    PlayerStrategyPattern();
    virtual ~PlayerStrategyPattern();
    virtual void getFortifyValues(int * startingCountry, int * destinationCountry, int * numberOftroupsToMove, Map& m)= 0;
    virtual void getAttackValues()= 0;
    virtual void getReinforceValues()= 0;
};
//subclass of PlayerStrategyPattern
class Human : public PlayerStrategyPattern{
    int countryNameToID(string countryName);
public:
    
    Human();
    ~Human();
    //Takes human input to changes the values of the given variables pointed to pointers. Before returning the function verifies that the given values are valid.
    void getFortifyValues(int * startingCountry, int * destinationCountry, int * numberOftroupsToMove, Map& m);
    void getAttackValues();
    void getReinforceValues();
    
};
//subclass of PlayerStrategyPattern
class Agressive;
//subclass of PlayerStrategyPattern
class Benevolent;


#endif /* PSPatern_hpp */