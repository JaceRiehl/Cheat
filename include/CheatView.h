#ifndef CHEATVIEW_H
#define CHEATVIEW_H
#include <iostream> 
#include "Deck.h"
#include "Player.h"
#include "Card.h"
using namespace std; 

class CheatView
{
public:
	CheatView();
	virtual ~CheatView();
	virtual void welcomeMessage();
	/**
	*Choose the Card number that will be checked against a player.
	*@return The players choice of Card.
	*@param The size of the hand.
	*/
	virtual int chooseCard(int);
	/**
	*Chooses the number of players that will play the game.
	*@param The maximum number of players
	*@return The number of players that will play.
	*/
	virtual int chooseNumPlayers(int);
	/**
	*Display the hand inputted.
	*@param Vector of Card to be displayed
	*/
	virtual void displayPlayersHand(vector<Card>);
	/**
	*Displays which Players' turn it is.
	*@param The Player who's turn it is.
	*/
	virtual void displayTurn(Player);
	/**
	*The display message for the end of a turn.
	*/
	virtual void endTurn();
	/**
	*Displays the ending message to the game. To be displayed when the game has ended.
	*@param The player number of the winner.
	*/
	virtual void endingMessage(int);
	/**
	*Clears the terminal so that the player can't see the other players hand.
	*/
	virtual void clearTerminal();
	/**
	*
	*/
	virtual int callCheat(int numPlayers);
	/**
	*
	*/
	virtual void displayCard(string c);
	/**
	*
	*/
	virtual bool continueDiscarding();

};

#endif