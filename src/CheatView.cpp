#include "CheatView.h"

void CheatView::welcomeMessage()
{
	cout << "Welcome to Cheat!" << endl;
    cout << "For rules and regulations see: https://www.theguardian.com/lifeandstyle/2008/nov/22/rules-card-games-cheat" << endl;

}

int CheatView::chooseCard(int)
{

}
int CheatView::chooseNumPlayers(int maxPlayers)
{
    int players;
    char numPlayers = 0;
    int test = 0;
    cout << "How many players do you want to add (2-" << maxPlayers << ")? ";
    while(cin >> numPlayers)
    {
        players = numPlayers - '0';
        if(players >= 2 && players <= maxPlayers)
            break;
        cin.ignore(10000, '\n');
        cout << "Enter a valid input (2-" << maxPlayers << "): ";
    }

    return players;

}

void CheatView::displayPlayersHand(vector<Card> playersHand)
{
	cout << "Your hand is: " << endl;
    for(unsigned int hand=0; hand<playersHand.size();hand++)
    {
        if(hand == playersHand.size()-1)
            cout << playersHand[hand].getRankString() << " " << playersHand[hand].getSuitString() << endl;
        else
            cout << playersHand[hand].getRankString() << " " << playersHand[hand].getSuitString() << ", ";
    }

}

void CheatView::displayTurn(Player p1)
{
	cout << "Player " << p1.getPlayerNum() << "'s turn:" << endl;
}

void CheatView::endTurn()
{
	cout << "Your turn is ending." << endl;
}

void CheatView::endingMessage(int winner)
{
	cout << "The winner is: Player " << winner << "! "<< endl;
    cout << "Thanks for playing Cheat" << endl;
}

void CheatView::clearTerminal()
{
	for(int i=0;i<100;i++)
        cout << '\n';
}

bool CheatView::callCheat(int numPlayers)
{
	for(int i=0; i<numPlayers;i++)
	{
		char input = 'n';
		do
		{
		cout << "Do you want to call cheat, Player " << i+1 <<"? (y/n): ";
		}
		while(input != 'n' || input != 'y'); 
	}
}
