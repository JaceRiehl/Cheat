//
// CPSC 3720
// Assignment 1
//
/// Deck Class Header File
//
/// \author David Adams
/// \date Jan. 24, 2018
//
/// This file contains the class definition for the Deck class.

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <ctime>
#include <algorithm>

using std::vector;
using std::srand;
using std::random_shuffle;

class Deck
{
/// Class Members
private:
	vector<Card> _deckVector;

/// Class Member Functions
public:
/// Constructor
//
/// constructs the deck object
	Deck();

/// Destructor
//
/// destructs the deck object
	~Deck() {};

/// getDeck function
//
/// \return vector<Card> of cards representing the deck
/// returns the private vector member of the deck
	vector<Card> getDeck();

/// getSize function
//
/// \return int representing the size of the deck
/// returns the size of the deck
	int getSize() const;

/// drawCard function
//
/// \return Card being drawn
/// returns the card being removed from the deck
	Card drawCard();

/// shuffle function
//
/// void function to shuffle the cards in the deck
	void shuffle();
};

#endif
