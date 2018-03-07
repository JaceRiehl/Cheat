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

	

	// EXPECT_CALL(*deckMock,getSize())
	// .Times(1)
	// .WillOnce(Return(52));

	Card c1(ace);

	// ON_CALL(*deckMock,getSize()).WillByDefault(Return(c1));

	EXPECT_CALL(*deckMock,drawCard())
	.Times(52)
	.WillRepeatedly(Return(c1));

	// EXPECT_CALL(*p1Mock,receiveCard(_))
	// .Times(26)
	// .WillRepeatedly(Return());

	// EXPECT_CALL(*p2Mock,receiveCard(_))
	// .Times(26)
	// .WillRepeatedly(Return());

	// EXPECT_CALL(*deckMock,drawCard())
	// .Times(2)
	// .WillRepeatedly(Return(c1));


	// EXPECT_CALL(*deckMock,getSize())
	// .Times(1)
	// .WillOnce(Return(1));

	vector<Card> cTemp = {Card(two)};
	EXPECT_CALL(*deckMock,getDeck())
	.Times(1)
	.WillOnce(Return(cTemp));

	controller->startGame();
	controller->initalDeal();	
	
}
