#include "CheatController.h"

CheatController::~CheatController()
{
	if(dealersDeck != nullptr)
	{
		delete dealersDeck;
		dealersDeck = nullptr; 
	}
	if(view != nullptr)
	{
		delete view;
		view = nullptr;
	}

}
	
void CheatController::startGame()
{
	dealersDeck->shuffle();
    view->welcomeMessage();
    numPlayers = view->chooseNumPlayers(10);
}

void CheatController::initalDeal()
{

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