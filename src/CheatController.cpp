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
}

void CheatController::goFishDeal(int)
{

}

void CheatController::runGame()
{

}

int CheatController::turn(int)
{

}

int CheatController::mostMatches()
{

}