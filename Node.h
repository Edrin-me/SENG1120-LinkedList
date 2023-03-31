// Node class implementation
// Eddie Young 30.03.23 c3431624


#ifndef EDDIENODE
#define EDDIENODE

#include "Card.h"

class Node { // By default, class attributes are public instead of private
public:
	typedef Card dataType;

	Node(); // Constructor definition
	~Node(); // Deconstructor definition


	// Getters and setters
	Node* getNext();
	Node* getPrev();

	void setNext(Node* newNext);
	void setPrev(Node* newPrev);

	dataType getData();
	void setData(dataType value);

private:
	// Private member variables
	Node* prev;
	Node* next;
	dataType data;
};

#endif