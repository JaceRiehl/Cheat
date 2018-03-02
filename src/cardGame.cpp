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
	while(input != 'C' || input != 'G')
	{
		cout << "Do you want to play Cheat or GoFish? (c/g): ";
		cin >> input; 
		toupper(input);
	}
	if(input == 'C')
	{
		//CheatController g()
	}
	else if(input == 'G')
	{
	GoFishController g(new GoFishModel(), new GoFishView());
	g.play();
	}	

	return 0;
}
