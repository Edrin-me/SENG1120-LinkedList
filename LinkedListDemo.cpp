//LinkedListDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120

//Modified: 08/03/2023 Kyle Robert Harrison

//Program Description: This program demonstrates the basic functionality of a linked list that stores playing cards. 
//It will demo the functions of a basic linked list.
//The program adds content to a linked list, removes individual nodes, among other functionalities.

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Card.h"
using namespace std;

void initialize(LinkedList &l1, LinkedList &l2)
{
	//add a few cards to each players hand
	Card c(2, "Clubs");
    l1.addToTail(c);
	c.setAll(3, "Spades");
	l1.addToHead(c);
	c.setAll(12, "Hearts");
	l1.addToHead(c);
	c.setAll(11, "Diamonds");
	l1.addToHead(c);
	c.setAll(6, "Spades");
	l1.addToHead(c);
	
	
	c.setRank(5);
	c.setSuit("Diamonds");
	l2.addToHead(c);
	c.setAll(3, "Hearts");
	l2.addToHead(c);
	c.setAll(4, "Diamonds");
	l2.addToHead(c);
	c.setAll(11, "Hearts");
	l2.addToHead(c);
	c.setAll(8, "Spades");
	l2.addToHead(c);

}

void playRound(LinkedList &l1, LinkedList &l2)
{
	//play a single round of the game
	
	//each player saves and removes their first card
	Card player1Card = l1.getHead()->getData();
	Card player2Card = l2.getHead()->getData();
	l1.removeHead();
	l2.removeHead();
	
	//display the cards
	cout << "Player 1's card: " << player1Card << endl;
	cout << "Player 2's card: " << player2Card << endl;
	
	//create a new heap-allocated LinkedList to store the list of cards to win
	LinkedList* winningPot = new LinkedList();
	winningPot->addToTail(player1Card);
	winningPot->addToTail(player2Card);
	
	//while cards are the same (i.e., a tie) continue drawing
	while(player1Card == player2Card)
	{
		cout << "It's a tie! Drawing next card for each player."<< endl;
		
		//each player saves and removes their first card
		player1Card = l1.getHead()->getData();
		player2Card = l2.getHead()->getData();
		l1.removeHead();
		l2.removeHead();
		
		//display the cards
		cout << "Player 1's card: " << player1Card << endl;
		cout << "Player 2's card: " << player2Card << endl;
		
		//add these additional cards to the winning pot
		winningPot->addToTail(player1Card);
		winningPot->addToTail(player2Card);
	}
	
	//player 1 wins, winningPot is added to their list of cards
	if(player1Card > player2Card)
	{
		cout << "Player 1 wins!" << endl;
		l1 += *winningPot;
	}
	else //player 2 wins, winningPot is added to their list of cards
	{
		cout << "Player 2 wins!" << endl;
		l2 += *winningPot;
	}
	
	delete winningPot; //free the memory associated with winningPot
	
	//display the hands after the round
	//uncomment the following 3 lines if you wish to see the hands after each round. This may be useful during testing!
	//cout << endl;
	//cout << "Player 1: " << l1 << endl;
	//cout << "Player 2: " << l2 << endl;
	
	cout << endl;
}

int main()
{
	//number of rounds to be played in this demo
	int rounds = 3; 
	
	//a list for each of the players hands, with a combined list for testing purposes
    LinkedList player1Cards;
	LinkedList player2Cards;
	LinkedList combinedCardList;
	
	//initialize each hand with some cards
	initialize(player1Cards, player2Cards);

	//display the initial contents of the lists
	cout << "Starting Lists:" << endl;
	cout << "Player 1: " << player1Cards << endl;
	cout << "Player 2: " << player2Cards << endl;
	cout << "Combined Card List: " << combinedCardList << endl;
	
	cout << "=====================================================" << endl;
	
	//test the remove from each list
	cout << "Removing card '(2, Clubs)' from player 1." << endl;
	player1Cards.remove(2, "Clubs");
	cout << "Removing card '(3, Hearts)' from player 2." << endl;
	player2Cards.remove(3, "Hearts");
	
	//test concatenation (i.e., the += operator)
	cout << "Concatenating the two lists into 'Combined Card List'." << endl << endl;
	combinedCardList += player1Cards;
	combinedCardList += player2Cards;

	//display the lists after concatenation
	cout << "Player 1: " << player1Cards << endl;
	cout << "Player 2: " << player2Cards << endl;
	cout << "Combined Card List: " << combinedCardList << endl << endl;

	cout << "=====================================================" << endl;
	
	//display some stats about the cards, testing various LL methods on the combined list
	cout << "Combined List Details: " << endl;
	cout << "Number of cards of suit 'Hearts': ";
	cout << combinedCardList.countSuit("Hearts") << endl;
	cout << "Number of cards of suit 'Clubs': ";
	cout << combinedCardList.countSuit("Clubs") << endl;
	cout << "Highest rank of suit 'Hearts': ";
	cout << combinedCardList.highestRank("Hearts") << endl;
	//this should return -1 if there is no cards of that rank
	cout << "Highest rank of suit 'Clubs': ";
	cout << combinedCardList.highestRank("Clubs") << endl;
	cout << "Average card rank: ";
	cout << combinedCardList.averageRank() << endl << endl;
	
	cout << "=====================================================" << endl;
	
	//play a fixed number of rounds of the Game of War
	cout << "Playing " << rounds << " rounds of war" << endl << endl;
	for(int i = 0; i < rounds; i++)
	{
		cout << "Round " << i+1 << endl;
		playRound(player1Cards, player2Cards);
	}
	
	cout << "Hands after playing" << endl;
	cout << "Player 1: " << player1Cards << endl;
	cout << "Player 2: " << player2Cards << endl;
	cout << endl;
	
	// For the bonus question, uncomment this section and implement order in LinkedList
	cout << "=====BONUS QUESTION======" << endl;
	cout << "Ordering the two hands by rank." << endl;
	
	player1Cards.order();
	player2Cards.order();
	cout << "Player 1: " << player1Cards << endl;
	cout << "Player 2: " << player2Cards << endl << endl;
		
	cout << "The program has finished." << endl;
	return 0;
}
