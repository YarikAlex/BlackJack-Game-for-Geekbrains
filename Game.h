#pragma once
#include <iostream>
//#include <ctime>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
public:
    Game(const vector<string>& names);
    ~Game();
    void Play();
};

void playAgain(Game& newGame);

