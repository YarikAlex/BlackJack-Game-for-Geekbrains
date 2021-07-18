#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "Deck.h"
#include "Game.h"

int main()
{
    cout << "\t\t---Welcome to BlackJack!---" << endl << endl;
    int NumberOfPlayers = 0;
    while (NumberOfPlayers < 1 or NumberOfPlayers>7)
    {
        cout << "How many players? (1-7): ";
        cin >> NumberOfPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < NumberOfPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game newGame(names);

    playAgain(newGame);

	return 0;
}
