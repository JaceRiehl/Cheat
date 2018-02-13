//
// CPSC 3720
// Assignment 1
//
// GoFish View Header File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the class definition of the GoFish View class.

#include "GoFishView.h"

// Default Constructor
//
// constructs the GoFishView object
GoFishView::GoFishView()
{
}

// Destructor
//
// destructs the GoFishView object
GoFishView::~GoFishView()
{
}

// printWelcome Function
//
// prints a welcome message and prompts the user for the number of players
void GoFishView::printWelcome(char& playerNum)
{
	bool entered = false;

	while (entered == false)
	{
		try
		{
			std::cout << "Go Fish Game" << std::endl;
			std::cout << "How many (2-5) will be playing? (0 to quit)" << std::endl;
			std::cin >> playerNum;
			if (playerNum == '0' || playerNum == '2' || playerNum == '3' || playerNum == '4' || playerNum == '5')
			{
				entered = true;
				break;
			}
			else
			{
				throw std::invalid_argument("ERROR: Invalid number. Please try again.");
			}
		}
		catch (const std::invalid_argument& e)
		{
			clear(e);
		}
	}
}

// printStatus
//
// \param [out] currentPlayer the current player
// \param [out] score the score of the current player
// \param [out] playerHand the hand of the current player
// prints the current player's status
void GoFishView::printStatus(const int& currentPlayer, const int& score, const std::string& playerHand)
{
	std::cout << "Player " << currentPlayer << "'s score: " << score << std::endl;
	std::cout << "Player " << currentPlayer << "'s hand: " << std::endl;
	std::cout << playerHand;
}

// printPlayerRequest
//
// \param [out] playerLimit the maximum possible player number to request
// \param [in] playerNum the number of the player making the request
// \param [in] playerChoice the selection integer for the player being chosen
// \param [out] rankIndex the number of the rank for the controller to choose from the Rank enumeration
// prompts the user to request a player to ask for cards
void GoFishView::printPlayerRequest(const int& playerLimit, const int& playerNum, int& playerChoice, int& rankIndex)
{

	bool doneTurn = false;
	std::array<std::string, 13> rankArray = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };
	char playerTarget;
	std::string cardChoice;

	while (doneTurn == false)
	{
		// player check here
		try
		{
			std::cout << "Which player would you like to ask? (between 1 and " << playerLimit << ")" << std::endl;
			std::cin >> playerTarget;

			playerChoice = ((playerTarget - '0' - 1));
			if ((playerChoice < 0) || (playerChoice >= playerLimit) || playerNum == (playerChoice + 1))
			{
				throw std::invalid_argument("ERROR: Invalid player selection.");
			}

			// way to check and handle card requests here
			while (doneTurn == false)
			{
				printCardRequest(cardChoice);
				std::transform(cardChoice.begin(), cardChoice.end(), cardChoice.begin(), static_cast<int(*)(int)>(std::tolower));
				for (int i = 0; i < 13; ++i)
				{
					if (cardChoice == rankArray[i])
					{
						rankIndex = i;
						doneTurn = true;
						break;
					}
				}
			}
		}
		catch (const std::invalid_argument& e)
		{
			clear(e);
		}
	}
}

// printCardRequest
//
// \param [in] cardChoice the string of the card being chosen
// prompts the user to request a card from their chosen player
void GoFishView::printCardRequest(std::string& cardChoice)
{
	std::cout << "Which card would you like to request? (two, three, jack, king, ace, etc.)" << std::endl;
	std::cin >> cardChoice;
}

// printHasCards
//
// \param [out] cardAmount int representing the number of cards being transferred
// prints a message stating that the request was a success, and the given number of cards was transferred.
void GoFishView::printHasCards(const int& cardAmount)
{
	std::cout << "Success! " << cardAmount << " card(s) transferred to your hand." << std::endl;
}

// printGoFish
//
// prints the "Go Fish" message
void GoFishView::printGoFish()
{
	std::cout << "Go fish!" << std::endl;
}

// printFinalScore
//
// \param [out] currentPlayer the current player
// \param [out] score the score of the current player
// prints the player's final score
void GoFishView::printFinalScore(const int& currentPlayer, const int& score)
{
	std::cout << "Player " << currentPlayer << "'s final score: " << score << std::endl;
}

// printGameOver
//
// prints the game over message
void GoFishView::printGameOver()
{
	std::cout << "Game Over" << std::endl;
}

// clear function
//
// \param [out] e the exception to be printed
// prints the passed exception and clears the cin stream
void GoFishView::clear(const std::invalid_argument& e)
{
	std::cerr << e.what() << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
