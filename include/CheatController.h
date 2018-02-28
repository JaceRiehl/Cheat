#include "GoFishView.h"
#include <algorithm>
#include <limits>
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <array>
#include <vector>
#include <cassert>
/**
*Implements the game Cheat.
*/ 
class CheatController 
{
public: 
	/**
	*Controller that sets up dependecy injection 
	*@param vector<Player*> play The players that will be used in the game
	*@param CheatView* v  The view object 
	*@param Deck* d the deck object that will be used 
	*/
	CheatController(vector<Player*> play, CheatView* v, Deck* d): view(v), players(play), dealersDeck(deck) {}
	/**
	*Class Destructor
	*/ 
	virtual ~CheatController();
	
	/**
	*Starts the game, creates players, and sets up the game.
	*/
	virtual void startGame();
	/**
	*Deals Cards to all Players. It deals 5 cards per player if there are 4-5 players and 7 if there are 2-3 players. 
	*/
	virtual void initalDeal();
	/**
	*Deals a card to the player if they get a 'GoFish' (the player they fished didn't have the card).
	@param int that is the index of the player in the players vector
	*/
	virtual void goFishDeal(int);
	/**
	*runGame does the loop that calls the appropriate functions to run the game until the game is won.
	*/
	virtual void runGame();
	/**
	*Calls a turn
	*@param int that is the players number.
	*@return The index of the Player in the players vector taking a turn.
	*/
	virtual int turn(int);
	/**
	*Checks who has the most matches of the players in the Player vector.
	*@return The index of the player who has the most matches.
	*/
	virtual int mostMatches();



private: 
	CheatView* view;
	vector<Player*> players;
	Deck* dealersDeck;
	vector<Card> pile; 
};