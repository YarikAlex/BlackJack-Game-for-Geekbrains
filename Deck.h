#pragma once
#include "Hand.h"
#include "GenericPlayer.h"
#include <algorithm>
class Deck :
    public Hand
{
public:
    Deck();
    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& dHand);
    void AdditionalCards(GenericPlayer& dGenericPlayer);
};

