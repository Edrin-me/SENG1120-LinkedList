// LinkedList class definition
// Eddie Young 30.03.23 c3431624

#ifndef EDDIELL
#define EDDIELL
//^^ macroguard ^^


#include "Node.h"

class LinkedList {
public:

	// Constructor and deconstructor
	LinkedList();
	~LinkedList();


	// Add node functions
	void addToHead(Node::dataType);
	void addToTail(Node::dataType);


	// Remove node
	void remove(int, string);

	// Game functions
	int countSuit(string) const;
	int highestRank(string) const;
	double averageRank() const;
	bool order_sort() const;
	void order() const;

	// Head functions
	void removeHead();
	Node* getHead() const;
	void setHead(Node*);
	
	// Debugging, prints the list to console
	void print() const;

	// += operator overload
	LinkedList& operator+= (const LinkedList&);


private: // Cannot be seen outside member scope
	Node* head;
};


// console out operator overload
ostream& operator <<(ostream& out, LinkedList&);

#endif