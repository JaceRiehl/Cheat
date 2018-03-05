#include "CheatController.h"

CheatController::~CheatController()
{
	if(_dealersDeck != nullptr)
	{
		delete _dealersDeck;
		_dealersDeck = nullptr; 
	}
	if(_view != nullptr)
	{
		delete _view;
		_view = nullptr;
	}

}
	
void CheatController::startGame()
{
	_dealersDeck->shuffle();
    _view->welcomeMessage();
    _numPlayers = _view->chooseNumPlayers(10);
}

void CheatController::initalDeal()
{
	int cardsPerPlayer = floor(_dealersDeck->getSize() / _numPlayers);
	for(int player=0; player<cardsPerPlayer; player++)
	{
		for(int cardsDealt=0; cardsDealt<cardsPerPlayer; cardsDealt++)
		{
			_players[player]->receiveCard(_dealersDeck->drawCard());
		}
	}
	if(_dealersDeck->getSize() != 0)
		_pile = _dealersDeck->getDeck(); 
}

void CheatController::runGame()
{
	//play a turn
	//ask if anyone wants to cheat 
	//check if anyone has any cards left 
	//loop 
	int index = -1;
	while(1)
	{
		++index;
        index = index % _numPlayers;
        _view->clearTerminal();
        int currentPlayer = turn(index);
        if(_players[index]->getHandSize() == 0)
        {
        	_view->endingMessage(++index);
            //see if bullshit was true 
            //if(it is true)
            //continue 
            //else if(its false)
            //player is winner 
        }

	}
}

int CheatController::turn(int playerIndex)
{
	//display turn 
	//display the card to be discarced
	//ask the player what card to play 
	int numCardsDiscarded = 1;
	_view->displayTurn(playerIndex + 1);
	_view->displayPlayersHand(_players[playerIndex]->getHand());
	_view->displayCard(_discard[_discardIndex]);
	
	int discard = _view->chooseCard(_players[playerIndex]->getHandSize());
	_players[playerIndex]->takeCard(discard);
	while(_view->continueDiscarding() && numCardsDiscarded < 3)
	{
		int discard = _view->chooseCard(_players[playerIndex]->getHandSize());
		_players[playerIndex]->takeCard(discard);
		++numCardsDiscarded;
	}
	int playerCalledCheatIndex = _view->callCheat(_numPlayers);
	if(playerCalledCheatIndex != -1)
	{
		int playerGettingCards = playerCalledCheatIndex;
		if(didCheat(numCardsDiscarded))
			playerGettingCards = playerIndex;
		if(!_pile.empty())
		{
			for(vector<Card>::iterator it = _pile.begin(); it != _pile.end(); ++it)
				{
					_players[playerGettingCards]->receiveCard(*it);
				}
			_pile.clear(); 
		}
	}
	++_discardIndex;
	_discardIndex = _discardIndex % _discard.size();
}

bool CheatController::didCheat(int numCardsDiscarded)
{
	for(int i = _pile.size() - numCardsDiscarded; i<_pile.size();++i)
	{
		if(_pile[i].getRankString() != _discard[_discardIndex])
		{
			return true; 
		}
	}
	return false;
}
