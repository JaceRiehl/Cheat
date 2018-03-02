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
}

int CheatController::turn(int)
{
	//display last card of vector
	//ask the player what card to play 

}
