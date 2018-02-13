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

#include "GoFishController.h"

int main()
{
   GoFishController g(new GoFishModel(), new GoFishView());
   g.play();

   return 0;
}
