#include "House.h"

House::House(const string& name) : GenericPlayer(name) {}
//House::House(const string& name) {}
House::~House() {}

bool House::isHitting()
{
    if (GetTotal() <= 16) return true;
    else return false;
}

void House::FlipFirstCard()
{
    if (m_Cards.empty() == false)
        m_Cards[0]->Flip();
    else
        cout << "All cards is flipped." << endl;
}
