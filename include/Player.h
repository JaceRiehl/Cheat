//
// CPSC 3720
// Assignment 1
//
/// Player Header File
//
/// \author David Adams
/// \date Jan. 24, 2018
//
/// This file contains the class defintion for the Player class.

#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Card.h"

class Player
{
/// Class Members
private:
	std::vector<Card> _hand;
	int _playerNum;
	int _score;

/// Class Member Functions
public:

/// Constructor
//
/// \param [in] playerNum the number of the player
/// \param [in] score an integer representing the score of the player
/// constructs a player object from the given parameters
	Player(int playerNum = 1, int score = 0);

/// Destructor
//
/// destructs the player object
	~Player();

/// getHand Function
//
/// \return vector<Card> representing the player's hand
/// returns the player's hand
    std::vector<Card> getHand();

/// getHandString Function
//
/// \return std::string representing the player's hand
/// returns the player's hand in string form
	std::string getHandString();


/// getPlayerNum Function
//
/// \return int representing the player's number
/// returns an integer representing the player's number
	int getPlayerNum() const;

/// getScore Function
//
/// \return int representing the player's score
/// returns an integer representing the player's score
    int getScore() const;

/// getHandSize Function
//
/// \return int representing the player's hand size
/// returns an integer representing the player's hand size
    int getHandSize() const;

/// receiveCard Function
//
/// \param[in] newCard the Card to be received by the player
/// adds a card to the player's hand
    void receiveCard(const Card& newCard);

/// countRank Function
//
/// \param[in] value the Rank to be counted in player's hand
/// \return int the number of cards with the given rank in the player's hand
/// returns an integer representing how many cards of the given rank the player has
    int countRank(const Rank& value);

/// giveCards Function
//
/// \param[in] value the Rank of the card to be given
/// \param[in] otherPlayer the Player to whom the cards will be given
/// \return int representing how many cards of the given rank have been given
/// finds cards in the hand of the given rank and gives them to the requesting player, also counting every card that is given
    int giveCards(const Rank& value, Player& otherPlayer);

/// receivePoint Function
//
/// function to increase the player's score by one
    void receivePoint();
};

#endif
