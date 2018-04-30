#ifndef DECK_H
#define DECK_H

#include "UberCasino.h"
#include <vector>
#include <string>

using namespace std;
//This is the class for the deck of cards. It a vector of cards

enum Type{test,eight_deck,infinite};
class Deck
{
	public:
		//Constructor and destructor
		Deck(){

                }
		~Deck();
		//Set test deck
		void create_test_deck();
		//Set eight deck
		void create_eight_deck();
		//Set infinite deck		
		void create_infinite_deck();
		//Getter returns the deck type
		string get_deck_type();
		//Funtion to set and create the deck(shoe) type 
		void SetDeckType(int i);
		//Function to deal a card returns a card from deck
		UberCasino::card_t deal_a_card();
		//Getter retuns number of cards in the deck
		int num_cards();
		const char *types[3]={"test","eight_deck","infinite"};

	private:
		std::vector<UberCasino::card_t> deck;
		Type deck_type;
		
};

#endif
