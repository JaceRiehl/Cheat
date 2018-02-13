//
// CPSC 3720
// Assignment 1
//
// Player Test File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the Test defintion for the Player class.

#include <gtest/gtest.h>
#include "Player.h"

class PlayerTest : public::testing::Test
{
protected:
	virtual void setUp()
	{

	}
	virtual void tearDown()
	{

	}
};

TEST(PlayerTest, defaultValues)
{
	Player player;
	EXPECT_EQ(1, player.getPlayerNum());
	EXPECT_EQ(0, player.getScore());
	EXPECT_EQ(0, player.getHand().size());
	EXPECT_EQ(0, player.getHandSize());
	EXPECT_EQ(0, player.countRank(two));
	EXPECT_EQ(0, player.countRank(ace));
	EXPECT_EQ(0, player.countRank(jack));
}

TEST(PlayerTest, definedValues)
{
	Player player(2, 20);
	EXPECT_EQ(2, player.getPlayerNum());
	EXPECT_EQ(20, player.getScore());
	EXPECT_EQ(0, player.getHand().size());
	EXPECT_EQ(0, player.getHandSize());
	EXPECT_EQ(0, player.countRank(two));
	EXPECT_EQ(0, player.countRank(ace));
	EXPECT_EQ(0, player.countRank(jack));
}

TEST(PlayerTest, scoreCheck)
{
	Player player(1, 1);
	EXPECT_EQ(1, player.getPlayerNum());
	EXPECT_EQ(1, player.getScore());
	
	player.receivePoint();
	EXPECT_EQ(2, player.getScore());
	for (int i = 1; i <= 10; ++i)
	{
		player.receivePoint();
		EXPECT_EQ(2+i, player.getScore());
	}
}

TEST(PlayerTest, handCheck)
{
	Player player1;
	Player player2(2, 0);
	EXPECT_EQ("", player1.getHandString());
	Card card(ace, spades);
	player1.receiveCard(card);
	EXPECT_EQ(1, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player1.getHandString());
}

TEST(PlayerTest, exchangeCheck)
{
	// re-establish that everything works from the start, for comparison
	Player player1;
	Player player2(2, 0);
	Card card(ace, spades);
	player1.receiveCard(card);
	EXPECT_EQ(1, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player1.getHandString());

	EXPECT_EQ(0, player2.getHandSize());
	EXPECT_EQ(0, player2.countRank(ace));
	EXPECT_EQ("", player2.getHandString());

	// first give a card he doesn't have
	player1.giveCards(king, player2);
	EXPECT_EQ(1, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player1.getHandString());

	EXPECT_EQ(0, player2.getHandSize());
	EXPECT_EQ(0, player2.countRank(ace));
	EXPECT_EQ("", player2.getHandString());

	// now give his only card
	player1.giveCards(ace, player2);
	EXPECT_EQ(1, player2.getHandSize());
	EXPECT_EQ(1, player2.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player2.getHandString());

	EXPECT_EQ(0, player1.getHandSize());
	EXPECT_EQ(0, player1.countRank(ace));
	EXPECT_EQ("", player1.getHandString());

	// now get more cards and exchange them
	Card card2(two, spades);
	Card card3(three, spades);
	Card card3A(three, hearts);
	Card card4(king, spades);
	player1.receiveCard(card2);
	player1.receiveCard(card3);
	player1.receiveCard(card3A);
	player2.receiveCard(card4);

	// make sure their hand sizes are correct
	EXPECT_EQ(2, player2.getHandSize());
	EXPECT_EQ(1, player2.countRank(ace));
	EXPECT_EQ(3, player1.getHandSize());
	EXPECT_EQ(1, player2.countRank(king));

	// now give their cards and check again
	player1.giveCards(three, player2);
	player2.giveCards(king, player1);
	EXPECT_EQ(3, player2.getHandSize());
	EXPECT_EQ(1, player2.countRank(ace));
	EXPECT_EQ(2, player2.countRank(three));
	EXPECT_EQ(2, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(king));

	// create a player who only has tens, and try giving them all away
	Player player3;
	Card card10A(ten, spades);
	Card card10B(ten, diamonds);
	Card card10C(ten, hearts);
	player3.receiveCard(card10A);
	player3.receiveCard(card10B);
	player3.receiveCard(card10C);
	EXPECT_EQ(3, player3.getHandSize());
	EXPECT_EQ(3, player3.countRank(ten));

	player3.giveCards(ten, player1);
	EXPECT_EQ(5, player1.getHandSize());
	EXPECT_EQ(3, player1.countRank(ten));
	EXPECT_EQ(0, player3.getHandSize());
	EXPECT_EQ(0, player3.countRank(ten));

}