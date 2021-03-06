//============================================================================
// Name        : FortificationPhase.hpp
// Team        : Group 13
// Team members: Bruno Robert 40003443, Chao Yue 27282516, Jeffrey Maher 40018878, Sabrina Rieck 40032864, Simon Roy 40030996
// Version     : 1.0
// Copyright   : GNU Public license 3
// Description : Moves troups from one country to another during the fortification phase of a player's turn
//============================================================================

#ifndef FortificationPhase_hpp
#define FortificationPhase_hpp

#include <stdio.h>
#include "Player.h"
#include "Subject.h"
using namespace std;

class FortificationPhase : public Subject {
    vector <Player *> playerList;
public:
    FortificationPhase();
    ~FortificationPhase();
    void fortify(int player, Map& m );
	void setStartingCountry(CountryNode* startingCountryData);
	CountryNode* getStartingCountry();
	void setDestinationCountry(CountryNode* destinationCountryData);
	CountryNode* getDestinationCountry();
	void setAmountTroopsMoved(int amountTroopsMovedData);
	int getAmountTroopsMoved();
	void setFortifyingPlayer(Player* player);
	Player* getFortifyingPlayer();

private:
	CountryNode* startingCountry;
	CountryNode* destinationCountry;
	int amountTroopsMoved;
	Player* fortifyingPlayer;
};



#endif /* FortificationPhase_hpp */
