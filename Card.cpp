//Course: SENG1120
//Coded by: Kyle Harrison

#include "Card.h"
#include <cstdlib>

// Constructors
Card::Card()
{
	rank = 0;
	suit = "";
}

Card::Card(const int _rank, const string _suit)
{
	rank = _rank;
	suit = _suit;
}

// empty destructor
Card::~Card(){}

// Mutator methods (setters)
void Card::setRank(const int _rank) {rank = _rank;}
void Card::setSuit(const string _suit){ suit = _suit;}
void Card::setAll(const int _rank, const string _suit)
{
	rank = _rank;
	suit = _suit;
}

// Accessor methods (getters)
int Card::getRank() const {return rank;}
string Card::getSuit() const {return suit;}

// overloaded stream insertion operator
ostream& operator <<(ostream& out, const Card& value)
{
	out << "(" << value.getRank() << ", " << value.getSuit() << ")";
    return out;
}

// overloaded == operator
bool operator == (const Card& c1, const Card& c2)
{
    return c1.getRank() == c2.getRank();
}

// overloaded > operator
bool operator > (const Card& c1, const Card& c2)
{
    return c1.getRank() > c2.getRank();
}
