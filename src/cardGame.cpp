//
// CPSC 3720
// Assignment 1
//
// Card Game Main Program File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the main program, which initializes and runs a card game.

#include <stdio.h>
#include <ctype.h>
#include "GoFishController.h"
#include "CheatController.h"
#include <iostream> 

int main()
{
	char input;
	while(input != 'C' && input != 'G')
	{
		cout << "Do you want to play Cheat or GoFish? (c/g): ";
		cin >> input; 
		input = toupper(input);
	}
	if(input == 'C')
	{
		Player* p1 = new Player(1);
	    Player* p2 = new Player(2);
    	Player* p3 = new Player(3);
    	Player* p4 = new Player(4);
    	Player* p5 = new Player(5);
    	vector<Player*> players = {p1,p2,p3,p4,p5};
    	Deck* deck = new Deck();
    	CheatView* view = new CheatView();
		CheatController c(players,view,deck);
		c.startGame();
		c.initalDeal();
		c.runGame();
		delete p1,p2,p3,p4,p5;
	}
	else if(input == 'G')
	{
	GoFishController g(new GoFishModel(), new GoFishView());
	g.play();
	}	

	return 0;
}
