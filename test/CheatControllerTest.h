#ifndef CHEATCONTROLLERTEST_H
#define CHEATCONTROLLERTEST_H
#include "CheatController.h"
#include "MockCard.cpp"
#include "MockDeck.cpp"
#include "Deck.h"
#include "MockCheatView.cpp"
#include "MockPlayer.cpp"
#include "Card.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;
using namespace ::testing;

class CheatControllerTest : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		deck = new MockDeck();
		view = new MockCheatView();
		p1Mock = new MockPlayer(1);
		p2Mock = new MockPlayer(2);
		//p3 = new MockPlayer(3);
		//p4 = new MockPlayer(4);
		//p5 = new MockPlayer(5);
		//p6 = new MockPlayer(6);
		//p7 = new MockPlayer(7);
		//p8 = new MockPlayer(8);
		//p9 = new MockPlayer(9);
		//p10 = new MockPlayer(10);
		players.push_back(p1Mock);
		players.push_back(p2Mock);
		controller = new CheatController(players,view,deck);
		viewMock = dynamic_cast<MockCheatView*>(view);
		//p1Mock = dynamic_cast<MockPlayer*>(p1);
		//p2Mock = dynamic_cast<MockPlayer*>(p2);
		// p3Mock = dynamic_cast<MockPlayer*>(p3);
		// p4Mock = dynamic_cast<MockPlayer*>(p4);
		// p5Mock = dynamic_cast<MockPlayer*>(p5);
		// p6Mock = dynamic_cast<MockPlayer*>(p6);
		// p7Mock = dynamic_cast<MockPlayer*>(p7);
		// p8Mock = dynamic_cast<MockPlayer*>(p8);
		// p9Mock = dynamic_cast<MockPlayer*>(p9);
		// p10Mock = dynamic_cast<MockPlayer*>(p10);
		deckMock = dynamic_cast<MockDeck*>(deck);
	}

	virtual void TearDown()
	{
		delete controller;
		delete p1Mock;
		delete p2Mock;
		//delete p1Mock,p2Mock,p3Mock,p4Mock,p5Mock,p6Mock,p7Mock,p8Mock,p9Mock,p10Mock;
		//delete view, viewMock;
		//delete deck,deckMock;

	}

protected:
    CheatController* controller;
    CheatView* view;
    MockCheatView* viewMock;
    Deck* deck;
    MockDeck* deckMock;
	Player* p1;
	Player* p2;


    MockPlayer* p1Mock;
    MockPlayer* p2Mock;


    vector<Player*> players;

};
#endif
