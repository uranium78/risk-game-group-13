//============================================================================
// Name        : ReinforcePhase.h
// Team        : Group 13
// Team members: Bruno Robert 40003443, Chao Yue 27282516, Jeffrey Maher 40018878, Sabrina Rieck 40032864, Simon Roy 40030996
// Version     : 0.1
// Copyright   : GNU Public license 3
// Description : Declaration of the Reinforce class and all its methods
//============================================================================


#pragma once
#include "Subject.h"
#include "Player.h"

class Reinforce : public Subject {

public:
	void reinforceDistributions(Player& player);	// This is the only method that needs to be called
	int totalUnits(Player& player);
	void reinforceNotifyDistribution(CountryNode* country, int units);
	void reinforceNotifyStart(Player& user);
	void setExchangeType(string typeOfExchange);
	string getExchangeType();
	void setReinforcedCountryData(CountryNode* country);
	CountryNode* getReinforcedCountryData();
	void setTroopsMoved(int moved);
	int getTroopsMoved();
	void setReinforcingPlayer(Player* player);
	Player* getReinforcingPlayer();

//Helper methods
private:			
	int  unitsForCountries(Player& player);
	int  unitsForContinents(Player& player);
	int  unitsForCards(Player& player);
	string exchangeType;
	CountryNode* reinforcedCountryData;
	int troopsMoved;
	Player* reinforcingPlayer;
};