#include "Deck.h"


Deck::Deck()
{
    m_Cards.reserve(52);
    Populate();
}
Deck::~Deck() {}
void Deck::Populate()
{
    Clear();
    for (int suit = Card::Diamonds; suit <= Card::Spades; ++suit)
    {
        for (int cardValue = Card::Ace; cardValue <= Card::King; ++cardValue)
        {
            Add(new Card(static_cast<Card::CardValue>(cardValue),
                static_cast<Card::Suit>(suit)));
        }
    }
}
void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}
void Deck::Deal(Hand& dHand)
{
    if (!m_Cards.empty())
    {
        dHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "The deck is out of cards." << endl;
    }
}
void Deck::AdditionalCards(GenericPlayer& dGenericPlayer)
{
    cout << endl;
    while (!(dGenericPlayer.isBoosted()) and dGenericPlayer.isHitting())
    {
        Deal(dGenericPlayer);
        cout << dGenericPlayer << endl;
        if (dGenericPlayer.isBoosted())
        {
            dGenericPlayer.Bust();
        }
    }
}