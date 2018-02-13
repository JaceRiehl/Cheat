//
// CPSC 3720
// Assignment 1
//
// Deck Class Implementation File
//
// \author David Adams
// \date Jan. 27, 2018
//
// This file contains the class function definitions for the Deck class.

#include "Deck.h"

// Constructor
//
// constructs the deck object
Deck::Deck()
{
	Rank tempRank;
	Suit tempSuit;

	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			switch (i)
			{
			case 1:
				tempRank = two;
				break;
			case 2:
				tempRank = three;
				break;
			case 3:
				tempRank = four;
				break;
			case 4:
				tempRank = five;
				break;
			case 5:
				tempRank = six;
				break;
			case 6:
				tempRank = seven;
				break;
			case 7:
				tempRank = eight;
				break;
			case 8:
				tempRank = nine;
				break;
			case 9:
				tempRank = ten;
				break;
			case 10:
				tempRank = jack;
				break;
			case 11:
				tempRank = queen;
				break;
			case 12:
				tempRank = king;
				break;
			case 0:
				tempRank = ace;
				break;
			default:
				break;
			}
			switch (j)
			{
			case 0:
				tempSuit = hearts;
				break;
			case 1:
				tempSuit = diamonds;
				break;
			case 2:
				tempSuit = clubs;
				break;
			case 3:
				tempSuit = spades;
				break;
			default:
				break;
			}
			_deckVector.push_back(Card(tempRank, tempSuit));
		}
	}

}

// Destructor
//
// destructs the deck object
Deck::~Deck()
{

}

// getDeck function
//
// \return vector<Card> of cards representing the deck
// returns the private vector member of the deck
std::vector<Card> Deck::getDeck()
{
	return _deckVector;
}

// getSize function
//
// \return int representing the size of the deck
// returns the size of the deck
int Deck::getSize() const
{
	return _deckVector.size();
}

// drawCard function
//
// \return Card being drawn
// returns the card being removed from the deck
Card Deck::drawCard()
{
	Card top = _deckVector.back();
	_deckVector.pop_back();
	return top;
}

// shuffle function
//
// void function to shuffle the cards in the deck
void Deck::shuffle()
{
	std::srand((unsigned int)time(0));
	std::random_shuffle(_deckVector.begin(), _deckVector.end());
}
