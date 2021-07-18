#include "Card.h"
Card::Card(CardValue value, Suit suit, bool position)
	: c_cardValue(value), c_suit(suit), cardPosition(position){}

bool Card :: Flip()
{
	cardPosition = !cardPosition;
	return cardPosition;
}

int Card :: getValue()
{
	int value = 0;
	if (cardPosition)
	{
		value = c_cardValue;
		if (value > 10)
			value = 10;
	}
	return value;
}

ostream& operator<<(ostream& os, const Card& card)
{
	const string CardValue[] = { "0", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
  "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	const string Suits[] = { "Diamonds", "Hearts", "Clubs", "Spades" };
	if (card.cardPosition == true)
		cout << CardValue[card.c_cardValue] << " " << Suits[card.c_suit];
	else
		cout << "XX";
	return os;
}
