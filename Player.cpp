#include "Player.h"
Player::Player(const string& name = "") : GenericPlayer(name)
{
    m_Name = name;
}
Player:: ~Player() { }

void Player::Win() const
{
    cout << m_Name << ", you win!" << endl;
}
void Player::Lose() const
{
    cout << m_Name << ", you lose!" << endl;
}
void Player::Push() const
{
    cout << m_Name << ", you drew!" << endl;
}

bool Player::isHitting()
{
    char answer;
    cout << m_Name << ", do you need another card? (Y or N): " << endl;
    cin >> answer;
    if (answer == 'Y' or answer == 'y') return true;
    else return false;
}
