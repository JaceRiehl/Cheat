//
// CPSC 3720
// Assignment 1
//
// Player Implementation File
//
// \author David Adams
// \date Jan. 27, 2018
//
// This file contains the class function defintions for the Player class.

#include "Player.h"

// Constructor
//
// \param [in] score an integer representing the score of the player
// constructs a player object from the given parameters
Player::Player(int playerNum, int score)
    : _playerNum(playerNum), _score(score)
{
}

// Destructor
//
// destructs the player object
Player::~Player()
{
}

// getHand Function
//
// \return vector<Card> representing the player's hand
// returns the player's hand
std::vector<Card> Player::getHand()
{
    return _hand;
}

// getHandString Function
//
// \return std::string representing the player's hand
// returns the player's hand in string form
std::string Player::getHandString()
{
	std::string s = "";
	for (int i = 0; i < _hand.size(); ++i)
	{
		s = (s + std::to_string((i + 1)) + ") " + _hand[i].getCardString() + "\n");
	}
	return s;
}

// getPlayerNum Function
//
// \return int representing the player's number
// returns an integer representing the player's number
int Player::getPlayerNum() const
{
	return _playerNum;
}

// getScore Function
//
// \return int representing the player's score
// returns an integer representing the player's score
int Player::getScore() const
{
    return _score;
}

// getHandSize Function
//
// \return int representing the player's hand size
// returns an integer representing the player's hand size
int Player::getHandSize() const
{
    return _hand.size();
}

// receiveCard Function
//
// \param[in] newCard the Card to be received by the player
// adds a card to the player's hand
void Player::receiveCard(const Card& newCard)
{
    _hand.push_back(newCard);
}

// countRank Function
//
// \param[in] value the Rank to be counted in player's hand
// \return int the number of cards with the given rank in the player's hand
// returns an integer representing how many cards of the given rank the player has
int Player::countRank(const Rank& value)
{
    int n = 0;
    for (int i = 0; i < getHandSize(); ++i)
    {
        if (getHand()[i].getRank() == value)
        {
            ++n;
        }
    }
    return n;
}

// giveCards Function
//
// \param[in] value the Rank of the card to be given
// \param[in] otherPlayer the Player to whom the cards will be given
// \return int representing how many cards of the given rank have been given
// finds cards in the hand of the given rank and gives them to the requesting player, also counting every card that is given
int Player::giveCards(const Rank& value, Player& otherPlayer)
{
    int n = 0;
    for (auto it = this->_hand.begin(); it != this->_hand.end(); )
        {
            if (value == it->getRank())
            {
                Card temp = *it;
				it = this->_hand.erase(it);
				otherPlayer.receiveCard(temp);
                ++n;
            }
			else
			{
				++it;
			}
        }
        return n;
}

// receivePoint Function
//
// function to increase the player's score by one
void Player::receivePoint()
{
    ++_score;
}


