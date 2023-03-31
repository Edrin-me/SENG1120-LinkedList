//Card - Class Defintion
//Author: Kyle Robert Harrison
//Course: SENG1120
//Created: 30/08/17

//Class Description:
//A simple data class to represent a playing card that consists of a rank (integer) and suit (string).

#ifndef SENG1120_CARD_H
#define SENG1120_CARD_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Card 
{
	public:
		
		// Constructors
		Card();
		Card(const int rank, const string suit);

		// Destructor
		~Card();

		// Setters
		void setRank(const int _rank);
		void setSuit(const string _suit);
		void setAll(const int _rank , const string _suit);

		// Getters
		int getRank() const;
		string getSuit() const;

	//Private member variables
	private:
		int rank;		// numeric rank of card, from 1-13
		string suit;	 // the card suit, which is one of "Club", "Spade", "Diamond", "Heart"
};

ostream& operator <<(ostream&, const Card&);
bool operator == (const Card& c1, const Card& c2);
bool operator > (const Card& c1, const Card& c2);

#endif