#include "CheatControllerTest.h"

TEST_F(CheatControllerTest,testStartGame)
{
	ASSERT_TRUE(true);
	EXPECT_CALL(*deckMock,shuffle())
	.Times(1)
	.WillOnce(Return());

	EXPECT_CALL(*viewMock,welcomeMessage())
	.Times(1)
	.WillOnce(Return());

	EXPECT_CALL(*viewMock,chooseNumPlayers(_))
	.Times(1)
	.WillOnce(Return(2));

	controller->startGame();

}

TEST_F(CheatControllerTest,testInitalDeal)
{
	EXPECT_CALL(*deckMock,shuffle())
	.Times(1)
	.WillOnce(Return());

	EXPECT_CALL(*viewMock,welcomeMessage())
	.Times(1)
	.WillOnce(Return());

	EXPECT_CALL(*viewMock,chooseNumPlayers(_))
	.Times(1)
	.WillOnce(Return(2));


    EXPECT_CALL(*deckMock,getSize())
    .Times(2)
	.WillRepeatedly(Return(5));

	Card c1(ace);

	EXPECT_CALL(*deckMock,drawCard())
	.Times(4)
	.WillRepeatedly(Return(c1));

	 EXPECT_CALL(*p1Mock,receiveCard(_))
	 .Times(2)
	 .WillRepeatedly(Return());

	EXPECT_CALL(*p2Mock,receiveCard(_))
	.Times(2)
	.WillRepeatedly(Return());

	vector<Card> cTemp = {Card(two)};
	EXPECT_CALL(*deckMock,getDeck())
	.Times(1)
	.WillOnce(Return(cTemp));

	controller->startGame();
	controller->initalDeal();

}

 TEST_F(CheatControllerTest,testEverythingElse)
 {
 	EXPECT_CALL(*deckMock,shuffle())
	.Times(1)
	.WillOnce(Return());

	EXPECT_CALL(*viewMock,welcomeMessage())
	.Times(1)
	.WillOnce(Return());

	EXPECT_CALL(*viewMock,chooseNumPlayers(_))
	.Times(1)
	.WillOnce(Return(2));


    EXPECT_CALL(*deckMock,getSize())
    .Times(2)
	.WillRepeatedly(Return(7));

	Card c1(ace);

	EXPECT_CALL(*deckMock,drawCard())
	.Times(6)
	.WillRepeatedly(Return(c1));

	 EXPECT_CALL(*p1Mock,receiveCard(_))
	 .Times(3)
	 .WillRepeatedly(Return());

	EXPECT_CALL(*p2Mock,receiveCard(_))
	.Times(8)
	.WillRepeatedly(Return());

	vector<Card> cTemp = {Card(two)};
	EXPECT_CALL(*deckMock,getDeck())
	.Times(1)
	.WillOnce(Return(cTemp));

 	EXPECT_CALL(*viewMock,clearTerminal())
 	.Times(1)
 	.WillOnce(Return());

 	EXPECT_CALL(*viewMock,displayTurn(_))
 	.Times(1)
 	.WillOnce(Return());

 	EXPECT_CALL(*p1Mock,sortHand())
 	.Times(1)
 	.WillOnce(Return());



//   EXPECT_CALL(*p1Mock,getHandSize())
// 	.Times(1)
// 	.WillOnce(Return(5));

// 	EXPECT_CALL(*viewMock,chooseCard(_))
// 	.Times(1)
// 	.WillOnce(Return(1));

    EXPECT_CALL(*p1Mock,takeCard(_))
 	.Times(4)
 	.WillRepeatedly(Return(c1));


 	EXPECT_CALL(*viewMock,displayPlayersHand(_))
 	.Times(4)
 	.WillRepeatedly(Return());

 	EXPECT_CALL(*viewMock,displayCard(_))
 	.Times(1)
 	.WillRepeatedly(Return());

 	EXPECT_CALL(*p1Mock,getHand())
 	.Times(4)
 	.WillRepeatedly(Return(cTemp));

 	EXPECT_CALL(*viewMock,continueDiscarding())
 	.Times(3)
 	.WillRepeatedly(Return(true));


 	EXPECT_CALL(*viewMock,chooseCard(_))
 	.Times(4)
 	.WillRepeatedly(Return(1));

// 	EXPECT_CALL(*p1Mock,getHandSize())
// 	.Times(3)
// 	.WillRepeatedly(Return(5));



//
// 	EXPECT_CALL(*p1Mock,takeCard(_))
// 	.Times(3)
// 	.WillRepeatedly(Return(c1));
//
 	EXPECT_CALL(*viewMock,callCheat(_,_))
 	.Times(1)
 	.WillOnce(Return(1));

 	EXPECT_CALL(*viewMock,endTurn())
 	.Times(1)
 	.WillOnce(Return());

 	EXPECT_CALL(*viewMock,endingMessage(_))
 	.Times(1)
 	.WillOnce(Return());


    controller->startGame();
 	controller->initalDeal();
 	controller->runGame();

 }
