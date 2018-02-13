//
// CPSC 3720
// Assignment 1
//
// Deck Class Test File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the Test definition for the Deck class.

#include <limits.h>
#include <gtest/gtest.h>
#include "Deck.h"

class DeckTest : public::testing::Test
{
protected:
	virtual void setUp()
	{

	}
	virtual void tearDown()
	{

	}
};

TEST(DeckTest, sizeCheck)
{
	Deck deck1;
	EXPECT_EQ(52, deck1.getDeck().size());
	Deck deck2;
	EXPECT_EQ(52, deck2.getSize());
	EXPECT_EQ(true, deck1.getSize() == deck2.getSize());
}

TEST(DeckTest, drawCheck)
{
	Deck deck1;
	EXPECT_EQ(king, deck1.drawCard().getRank());
	EXPECT_EQ(clubs, deck1.drawCard().getSuit());
	EXPECT_EQ(diamonds, deck1.drawCard().getSuit());
	EXPECT_EQ(hearts, deck1.drawCard().getSuit());
	EXPECT_EQ(spades, deck1.drawCard().getSuit());
	EXPECT_EQ(queen, deck1.drawCard().getRank());
	EXPECT_EQ(diamonds, deck1.drawCard().getSuit());
	Deck deck2;
	EXPECT_EQ(king, deck2.drawCard().getRank());
	EXPECT_EQ(clubs, deck2.drawCard().getSuit());
	EXPECT_EQ(diamonds, deck2.drawCard().getSuit());
	EXPECT_EQ(hearts, deck2.drawCard().getSuit());
	EXPECT_EQ(spades, deck2.drawCard().getSuit());
	EXPECT_EQ(queen, deck2.drawCard().getRank());
	EXPECT_EQ(diamonds, deck2.drawCard().getSuit());
}

TEST(DeckTest, shuffleCheck)
{
	bool different = false;
	for (int i = 0; i < 1000000 && different == false; ++i)
	{
		Deck deck1;
		Deck deck2;
		deck1.shuffle();
		deck2.shuffle();
		if ((deck1.drawCard().getRank() != deck2.drawCard().getRank()) || (deck1.drawCard().getSuit() != deck2.drawCard().getSuit()))
		{
			different = true;
			break;
		}
	}
	EXPECT_TRUE(different);

}