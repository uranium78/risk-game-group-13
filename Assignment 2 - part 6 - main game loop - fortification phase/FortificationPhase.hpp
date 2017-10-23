//
//  FortificationPhase.hpp
//  Assignment 2 - part 6 - main game loop: fortification phase
//
//  Created by Bruno Robert on 12/10/2017.
//  Copyright © 2017 Bruno Robert. All rights reserved.
//

#ifndef FortificationPhase_hpp
#define FortificationPhase_hpp

#include <stdio.h>
#include "Player.h"
using namespace std;

class FortificationPhase {
    vector <Player *> playerList;
public:
    FortificationPhase();
    ~FortificationPhase();
    void fortify(int player, Map& m );
};



#endif /* FortificationPhase_hpp */