#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Card
{
public:
	enum Suit { Diamonds, Hearts, Clubs, Spades };
	enum CardValue {
		Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack,
		Queen, King
	};
	Card(CardValue value, Suit suit, bool position = true);
	bool Flip();
	int getValue();
	friend ostream& operator<<(ostream& os, const Card& card);
private:
	Suit c_suit;
	CardValue c_cardValue;
	bool cardPosition; //если карта рубашкой вверх - false, рубашкой вниз - true
};

