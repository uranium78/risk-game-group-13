//============================================================================
// Name        : ReinforcePhase.cpp
// Team        : Group 13
// Team members: Bruno Robert 40003443, Chao Yue 27282516, Jeffrey Maher 40018878, Sabrina Rieck 40032864, Simon Roy 40030996
// Version     : 0.1
// Copyright   : GNU Public license 3
// Description : implementing all the methods for the reinforce phase 
//============================================================================

#include "Player.h"
#include "ReinforcePhase.h"
#include <algorithm>
#include "Subject.h"
#include <string>

int Reinforce::unitsForCountries(Player& player) {
	int units = (int)player.getCountry().size() / 3;
	if (units < 3) {
		units = 3;
	}
	cout << "\nThe country bonus is of " << units << " units." << endl;
	return units;
}

int Reinforce::unitsForContinents(Player& player) {
	int units = 0;
	vector<int> pastIndex;
	for (int i = 0; i < player.getCountry().size();i++) {
		if (std::find(pastIndex.begin(), pastIndex.end(), i) != pastIndex.end()) {
			continue;
		}
		ContinentNode* currentContinent = player.getCountry().at(i)->getContinent();
		bool isEqual = true;
		for (int j = 0; j < currentContinent->getCountryList().size() && isEqual; j++) {
			isEqual = false;
			int k = 0;
			while (!isEqual && k < player.getCountry().size()) {
				if (std::find(pastIndex.begin(), pastIndex.end(), i) != pastIndex.end()) {
					k++;
					continue;
				}
				if (currentContinent->getCountryList().at(j) == player.getCountry().at(k)) {
					isEqual = true;
					pastIndex.push_back(k);
				}
				k++;
			}
			if (isEqual && j == currentContinent->getCountryList().size() - 1)
				units += currentContinent->getContScore();
		}
	}
	cout << "The continent bonus is of " << units << " units." << endl;

	return units;
}

int Reinforce::unitsForCards(Player& player) {
	int units = player.getHandByRef().exchange();
	setExchangeType(player.getHandByRef().getExchangeString());
	notify("Card Exchange");
	cout << "size of the hand: " << player.getHand().getSize() << endl;
	cout << "The card bonus is of " << units << " units." << endl;
	return units;
}

int Reinforce::totalUnits(Player& player) {
	int units = 0;
	units += unitsForCountries(player);
	units += unitsForContinents(player);
	units += unitsForCards(player);

	cout << "\ntotal number of units: " << units << endl;
	return units;
}

void Reinforce::reinforceDistributions(Player& player) {

	setReinforcingPlayer(&player);
	notify("Reinforcing Started");

	int units = totalUnits(player);
	cout << "\nThe player possesses " << units << " to reinforce this turn." << endl;
	while (units != 0) {
		cout << "With now " << units << " units remaining, which country would you like to reinforce?" << endl;

		for (int i = 0; i < player.getCountry().size();i++)
			cout << player.getCountryByRef().at(i)->getCountName() << " which has " << player.getCountryByRef().at(i)->getNumberOfTroops() << " units." << endl;

		bool valid = false;
		string entry;
		CountryNode* reinforcedCountry = NULL;

		while (valid == false) {

			cin >> entry;
			replace(entry.begin(), entry.end(), '_', ' ');

			for (int i = 0; i < player.getCountry().size() && valid == false;i++) {
				if (entry == player.getCountryByRef().at(i)->getCountName()) {
					valid = true;
					reinforcedCountry = player.getCountryByRef().at(i);
					setReinforcedCountryData(reinforcedCountry);
				}
			}
			if (valid == false)
				cout << "\nThe country you entered is not valid. Please try again...\nNote: Spaces should be an underscore." << endl;
		}

		cout << "How many units you would like to move? ";
		int moving;
		cin >> moving;

		while (moving > units || moving < 1 || cin.fail()) {
			cout << "\nYour input was invalid: you must move at least 1 unit and no more than your remaining number of units."
				"You currently have " << units << " units remaining..." << endl;
			cout << "How many units you would like to move? ";
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
			cin >> moving;

		}
		setTroopsMoved(moving);
		reinforcedCountry->setNumberOfTroops(reinforcedCountry->getNumberOfTroops() + moving);
		units -= moving;
		
	}
	cout << "\nYou have dispensed all of your reinforcement units." << endl;
	notify("Troops Moved");
}

void Reinforce::reinforceNotifyDistribution(CountryNode* country, int units) {
	string  message = "PHASE_OBSERVER|" + country->getCountName() + " has received " + to_string(units) + " units.";
	Subject::notify(message);
}

void Reinforce::reinforceNotifyStart(Player& user) {
	string starting = "PHASE_OBSERVER| Beginning the reinforcement phase for player " + to_string(user.getPlayerID()) + "...";
	notify(starting);
}

void Reinforce::setExchangeType(string typeOfExchange){
	exchangeType = typeOfExchange;
}
string Reinforce::getExchangeType(){
	return exchangeType;
}
void Reinforce::setReinforcedCountryData(CountryNode* country){
	this->reinforcedCountryData = country;
}
CountryNode* Reinforce::getReinforcedCountryData(){
	return reinforcedCountryData;
}
void Reinforce::setTroopsMoved(int moved){
	troopsMoved = moved;
}
int Reinforce::getTroopsMoved(){
	return troopsMoved;
}
void Reinforce::setReinforcingPlayer(Player* player){
	this->reinforcingPlayer = player;
}
Player* Reinforce::getReinforcingPlayer(){
	return reinforcingPlayer;

}
