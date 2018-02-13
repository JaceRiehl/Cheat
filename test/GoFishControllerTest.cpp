//
// CPSC 3720
// Assignment 1
//
// GoFishController Test File
//
// \author David Adams
// \date Feb. 6, 2018
//
// This file contains the Test defintion for the GoFishController class.

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <MockGoFishModel.cpp>
#include <MockGoFishView.cpp>
#include "GoFishController.h"

using namespace ::testing;

class GoFishControllerTest : public::testing::Test
{
protected:
	virtual void setUp()
	{
	}
	virtual void tearDown()
	{
	}
};

TEST(GoFishControllerTest, defaultValues)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);
	EXPECT_EQ(mm, gc.getModel());
	EXPECT_EQ(mv, gc.getView());

	std::vector<Player> p;
	EXPECT_CALL(*mv, printWelcome(_)).WillRepeatedly(Return());
	EXPECT_CALL(*mm, getStatus())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(done));
	EXPECT_CALL(*mv, printGameOver());
	EXPECT_CALL(*mm, getPlayers())
		.WillRepeatedly(Return(p));
	
	gc.update();
	delete mm;
	delete mv;

}

TEST(GoFishControllerTest, initPlayersQuit)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	ON_CALL(*mm, getStatus()).WillByDefault(Return(done));
	char playerNum = '0';
	EXPECT_CALL(*mv, printWelcome(_))
		.Times(AtLeast(1))
		.WillRepeatedly(DoAll(SetArgReferee<0>(playerNum), Return()));
	EXPECT_CALL(*mm, setStatus(_))
		.Times(AtLeast(1));
	EXPECT_CALL(*mm, getStatus())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(done));


	std::vector<Player> p;
	EXPECT_CALL(*mv, printGameOver());
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(p));

	gc.initPlayers();
	

	delete mm;
	delete mv;
}

TEST(GoFishControllerTest, initPlayersTwoOrThree)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	ON_CALL(*mm, getStatus()).WillByDefault(Return(playing));
	char playerNum = '2';
	EXPECT_CALL(*mv, printWelcome(_))
	.Times(AtLeast(1))
	.WillRepeatedly(DoAll(SetArgReferee<0>(playerNum), Return()));
	EXPECT_CALL(*mm, addPlayers(_));
	EXPECT_CALL(*mm, setDealLimit(_));
	EXPECT_CALL(*mm, dealCards());
	EXPECT_CALL(*mm, setStatus(_));

	gc.initPlayers();

	delete mm;
	delete mv;
}

TEST(GoFishControllerTest, initPlayersFourOrFive)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	ON_CALL(*mm, getStatus()).WillByDefault(Return(playing));
	char playerNum = '4';
	EXPECT_CALL(*mv, printWelcome(_))
		.Times(AtLeast(1))
		.WillRepeatedly(DoAll(SetArgReferee<0>(playerNum), Return()));
	EXPECT_CALL(*mm, addPlayers(_));
	EXPECT_CALL(*mm, setDealLimit(_));
	EXPECT_CALL(*mm, dealCards());
	EXPECT_CALL(*mm, setStatus(_));

	gc.initPlayers();

	delete mm;
	delete mv;
}

TEST(GoFishControllerTest, takeTurnHasCard)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	Deck deck;
	Card card(ace, spades);
	Player p1(1, 0);
	Player p2(2, 0);
	p2.receiveCard(card);
	std::vector<Player> playerList;
	playerList.push_back(p1);
	playerList.push_back(p2);
	ON_CALL(*mm, getPlayers())
		.WillByDefault(Return(playerList));
	EXPECT_CALL(*mv, printPlayerRequest(_, _, _, _))
		.WillOnce(DoAll(SetArgReferee<2>(1), SetArgReferee<3>(12), Return()));
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(playerList));
	EXPECT_CALL(*mv, printHasCards(_));
	gc.takeTurn(p1);
	delete mm;
	delete mv;
}

TEST(GoFishControllerTest, takeTurnGoFish)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	Deck deck;
	Card card(ace, spades);
	Player p1(1, 0);
	Player p2(2, 0);
	p2.receiveCard(card);
	std::vector<Player> playerList;
	playerList.push_back(p1);
	playerList.push_back(p2);
	EXPECT_CALL(*mv, printPlayerRequest(_, _, _, _))
		.WillOnce(DoAll(SetArgReferee<2>(1), SetArgReferee<3>(11), Return()));
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(playerList));
	EXPECT_CALL(*mm, getDeck())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(deck));

	EXPECT_CALL(*mv, printGoFish());
	gc.takeTurn(p1);
	delete mm;
	delete mv;
}

TEST(GoFishControllerTest, updateStart)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	EXPECT_CALL(*mm, getStatus())
		.Times(AtLeast(1))
		.WillOnce(Return(start))
		.WillRepeatedly(Return(playing));
	EXPECT_CALL(*mv, printWelcome(_)).WillRepeatedly(Return());

	gc.update();

	delete mm;
	delete mv;
}

/*
TEST(GoFishControllerTest, updatePlaying)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	Deck deck;
	Card card(ace, spades);
	Player p1(1, 0);
	Player p2(2, 0);
	p2.receiveCard(card);
	std::vector<Player> playerList;
	playerList.push_back(p1);
	playerList.push_back(p2);
	EXPECT_CALL(*mv, printPlayerRequest(_, _, _, _))
		.WillOnce(DoAll(SetArgReferee<2>(1), SetArgReferee<3>(11), Return()));
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(playerList));
	EXPECT_CALL(*mv, printGoFish());

	EXPECT_CALL(*mm, getStatus())
		.Times(AtLeast(1))
		.WillOnce(Return(playing))
		.WillOnce(Return(playing))
		.WillRepeatedly(Return(done));

	EXPECT_CALL(*mm, setStatus(_))
		.Times(AtLeast(1));

	EXPECT_CALL(*mv, printStatus(_, _, _))
		.Times(AtLeast(1));

	EXPECT_CALL(*mv, printGameOver());
	EXPECT_CALL(*mv, printFinalScore(_, _))
		.Times(AtLeast(1));

	gc.update();

	delete mm;
	delete mv;
}
*/

TEST(GoFishControllerTest, updateDone)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	EXPECT_CALL(*mm, getStatus())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(done));

	Player p1(1, 0);
	Player p2(2, 0);
	std::vector<Player> p;
	p.push_back(p1);
	p.push_back(p2);

	EXPECT_CALL(*mv, printGameOver());
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(p));

	EXPECT_CALL(*mv, printFinalScore(_, _))
		.Times(AtLeast(1));
	
	gc.update();

	delete mm;
	delete mv;
}

TEST(GoFishControllerTest, detectWin)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);

	Card c1(two, spades);
	Card c2(two, diamonds);
	Card c3(two, hearts);
	Card c4(two, clubs);

	Player p1(1, 0);
	Player p2(2, 0);
	Player p3(3, 0);
	Player p1A(1, 0);
	std::vector<Player> pl1 = { p1, p2, p3 };
	std::vector<Player> pl2 = { p1A, p2, p3 };
	pl1[0].receiveCard(c1);
	pl1[0].receiveCard(c2);
	pl1[0].receiveCard(c3);
	pl1[0].receiveCard(c4);
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillOnce(Return(pl1))
		.WillRepeatedly(Return(pl2));
	EXPECT_CALL(*mm, setStatus(_));
	gc.checkForWin();


	delete mm;
	delete mv;
}


TEST(GoFishControllerTest, playKill)
{
	MockGoFishModel* mm = new MockGoFishModel();
	MockGoFishView* mv = new MockGoFishView();
	GoFishController gc(mm, mv);
	
	EXPECT_CALL(*mm, getStatus())
		.WillOnce(Return(start))
		.WillRepeatedly(Return(done));

	std::vector<Player> p;
	EXPECT_CALL(*mv, printGameOver());
	EXPECT_CALL(*mm, getPlayers())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(p));

	gc.play();
	
	delete mm;
	delete mv;
}
