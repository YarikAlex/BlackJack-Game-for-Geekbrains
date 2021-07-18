#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string& name) : m_Name(name) {};

GenericPlayer :: ~GenericPlayer() {}
bool GenericPlayer :: isBoosted()
{
    return (GetTotal() > 21);
}
void GenericPlayer :: Bust()
{
    cout << m_Name << " bust" << endl;
}

ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer)
{
    os << genericPlayer.m_Name << ":\t";
    vector<Card*>::const_iterator itCard;
    if (!genericPlayer.m_Cards.empty())
    {
        for (itCard = genericPlayer.m_Cards.begin();
            itCard != genericPlayer.m_Cards.end(); ++itCard)
        {
            os << *(*itCard) << "\t";
        }
        if (genericPlayer.GetTotal() != 0)
        {
            cout << "(" << genericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<Empty>";
    }
    return os;
}