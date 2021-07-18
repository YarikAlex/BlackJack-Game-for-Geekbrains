#pragma once
#include <iostream>
#include <cstring>
#include "GenericPlayer.h"
using namespace std;

class Player :
    public GenericPlayer
{
public:
    Player(const string& name);
    virtual ~Player();
    void Win() const;
    void Lose() const;
    void Push() const;
    bool isHitting() override;
};

