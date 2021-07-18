#pragma once
#include "Hand.h"

class GenericPlayer :
    public Hand
{
protected:
    string m_Name;
public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();
    virtual bool isHitting() = 0;
    bool isBoosted();
    void Bust();
    friend ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);
};

ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);

