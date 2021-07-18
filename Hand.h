#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "Card.h"
using namespace std;

class Hand
{
protected:
    vector<Card*> m_Cards;
public:
    Hand();
    void Add(Card* newcard);
    void Clear();
    int GetTotal()const;
};

