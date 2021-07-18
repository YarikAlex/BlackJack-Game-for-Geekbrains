#include "Game.h"
using namespace std;

Game:: Game(const vector<string>& names)
{
    vector<string>::const_iterator itNames;
    for (itNames = names.begin(); itNames != names.end(); ++itNames)
    {
        m_Players.push_back(Player(*itNames));
    }
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}
Game::~Game() {}
void Game:: Play()
{
    vector<Player>::iterator itPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (itPlayer = m_Players.begin(); itPlayer != m_Players.end(); ++itPlayer)
        {
            m_Deck.Deal(*itPlayer);
        }
        m_Deck.Deal(m_House);
    }
    m_House.FlipFirstCard();
    for (itPlayer = m_Players.begin(); itPlayer != m_Players.end(); ++itPlayer)
    {
        cout << *itPlayer << endl;
    }
    cout << m_House << endl;
    for (itPlayer = m_Players.begin(); itPlayer != m_Players.end(); ++itPlayer)
    {
        m_Deck.AdditionalCards(*itPlayer);
    }
    m_House.FlipFirstCard();
    cout << endl << m_House;
    m_Deck.AdditionalCards(m_House);
    if (m_House.isBoosted())
    {
        for (itPlayer = m_Players.begin(); itPlayer != m_Players.end(); ++itPlayer)
            if (!(itPlayer->isBoosted()))
            {
                itPlayer->Win();
            }
    }
    else
    {
        for (itPlayer = m_Players.begin(); itPlayer != m_Players.end(); ++itPlayer)
        {
            if (!(itPlayer->isBoosted()))
            {
                if (itPlayer->GetTotal() > m_House.GetTotal())
                {
                    itPlayer->Win();
                }
                else if (itPlayer->GetTotal() < m_House.GetTotal())
                {
                    itPlayer->Lose();
                }
                else
                {
                    itPlayer->Push();
                }
            }
        }
    }
    for (itPlayer = m_Players.begin(); itPlayer != m_Players.end(); ++itPlayer)
    {
        itPlayer->Clear();
    }
    m_House.Clear();
}


void playAgain(Game& newGame)
{
    char answer = 'y';
    while (answer != 'n' and answer != 'N')
    {
        newGame.Play();
        cout << "Do you want play again? (Y/N): ";
        cin >> answer;
        if (answer == 'n' or answer == 'N')
            cout << "Goodbye!!" << endl;
    }
}