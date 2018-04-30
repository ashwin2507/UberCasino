#include "deck.h"
#include <time.h>
#include <string>
using namespace DDS;
using namespace UberCasino;
using namespace std;

//Function to create a test deck.
void Deck::create_test_deck(){
	for(unsigned int i = 0, j = 0; i < 13 && j < 4; i++){
		card_t new_card;
		new_card.card=(card_kind)1;
		new_card.suite=(suite_t)1;
		deck.push_back(new_card);
		if(i == 12){
			j++;
			i = 0;
		}
	}
}
//Function to create the eight deck.
void Deck::create_eight_deck(){
	int count_deck=0;
	while(count_deck<8){
	for(unsigned int i = 0, j = 0; i < 13 && j < 4; i++){
		card_t new_card;
		new_card.card=(card_kind)i;
		new_card.suite=(suite_t)j;
		deck.push_back(new_card);
		if(i == 12){
			j++;
			i = 0;
		}
	}
	count_deck++;
	}
}

//Function to create infinite deck.
void Deck::create_infinite_deck(){
	int count_deck=0;
	while(count_deck<16){
	for(unsigned int i = 0, j = 0; i < 13 && j < 4; i++){
		card_t new_card;
		new_card.card=(card_kind)i;
		new_card.suite=(suite_t)j;
		deck.push_back(new_card);
		if(i == 12){
			j++;
			i = 0;
		}
	}
	count_deck++;
	}
}

// Function to Setup Deck Type
  void Deck::SetDeckType(int i){
	deck_type=(Type)(i-1);
    	if(deck_type==Type::test){
		Deck::create_test_deck();
	}else if(deck_type==Type::eight_deck){
		Deck::create_eight_deck();
	}else{
		Deck::create_infinite_deck();
	}
  }

  string Deck::get_deck_type(){
	return types[deck_type];
  }

//Function selects a random card from the deck and returns it to the caller
UberCasino::card_t Deck::deal_a_card(){
	card_t new_card;
	srand( time(NULL) );
	int r = rand() % (deck.size());
	new_card = deck.at(r);
	deck.erase(deck.begin() + r);

	return new_card;
}

//Getter retuns number of cards in the deck
int Deck::num_cards(){
	return deck.size();
}

//Destructor - destroys cards when deck is destroyed (Allegro Bitmap issue)
Deck::~Deck(){
	deck.clear();
}
