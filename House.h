#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "GenericPlayer.h"
using namespace std;

class House :
    public GenericPlayer
{
public:
    House(const string& name = "Dealer");
    virtual ~House();
    bool isHitting() override;
    void FlipFirstCard();
};

