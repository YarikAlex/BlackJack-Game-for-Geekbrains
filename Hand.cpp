#include "Hand.h"
Hand :: Hand() {}
void Hand :: Add(Card* newcard)
{
    m_Cards.push_back(newcard);
}
void Hand::Clear()
{
    for (auto card : m_Cards)
    {
        delete card;
    }
    m_Cards.clear();
}
int Hand::GetTotal() const
{
    if (m_Cards.empty())
    {
        return 0;
    }
    else
    {
        int total = 0;
        const int MaxPointers = 11;
        const int NewAceValue = 11;
        for (unsigned int i = 0; i < unsigned(m_Cards.size()); ++i)
        {
            total += m_Cards[i]->getValue();
        }
        if (total <= MaxPointers and total>21)
        {
            for (unsigned int i = 0; i < unsigned(m_Cards.size()); ++i)
            {
                if (m_Cards[i]->getValue() == Card::Ace)
                {
                    total -= m_Cards[i]->getValue();
                    total += NewAceValue;
                }
            }
        }
        return total;
    }
}