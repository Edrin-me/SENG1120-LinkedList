// LinkedList class implementation
// Eddie Young 30.03.23 c3431624

#include <iostream>
#include "LinkedList.h"


// Constructor
LinkedList::LinkedList() : head(NULL) {}

// Deconstructor
LinkedList::~LinkedList(){
	Node* current = getHead();
	Node* next;

	// Start at the head, delete every item in list
	while (current != NULL){
		next = current->getNext();
		delete current;
		current = next;
	}
}

void LinkedList::order() const{
	// Going to attempt a bubble sort
	while (!order_sort()){continue;}

	cout << "Bubble sort complete." << endl;

}

bool LinkedList::order_sort() const{
	Node* current = getHead();
	Node* next;

	while (current != NULL){
		next = current->getNext();
		if (next != NULL && current->getData().getRank() < next->getData().getRank()){
			// SWAP THEIR DATA
			Node::dataType data1 = current->getData();
			Node::dataType data2 = next->getData();
			current->setData(data2);
			next->setData(data1);
			return false;
		}
		current = next;
	}
	return true;
}


// Return number of cards in a suit as int
int LinkedList::countSuit(string suit) const{
	Node* current = getHead();
	Node* next;
	int count = 0;
	while (current != NULL){
		next = current->getNext();
		if(current->getData().getSuit() == suit){
			count++;
		}
		current = next;
	}
	return count;

}

// return the highest rank of the given suit as int
int LinkedList::highestRank(string suit) const{
	Node* current = getHead();
	Node* next;
	int highest = -1;
	while (current != NULL){
		next = current->getNext();
		if(current->getData().getSuit() == suit && current->getData().getRank() > highest){
			highest = current->getData().getRank();
		}
		current = next;
	}
	return highest;
}


// return the average rank as a double
double LinkedList::averageRank() const{
	Node* current = getHead();
	Node* next;
	double average = 0;
	double count = 0;
	while (current != NULL){
		next = current->getNext();
		average += current->getData().getRank();
		count++;
		current = next;
	}
	return average/count;
}

// remove a card from the list
void LinkedList::remove(int rank, string suit){

	Node* current = getHead();
	Node* next;
	Node* prev;

	// Start at the head and look for cards that match

	while (current != NULL){
		next = current->getNext();
		prev = current->getPrev();
		if (current->getData().getSuit() == suit && current->getData().getRank() == rank){
			if (current->getNext() != NULL){next->setPrev(prev);}
			if (current->getPrev() != NULL){prev->setNext(next);}
			return;
		}
		current = next;

	}

}

Node* LinkedList::getHead() const { return head; }

void LinkedList::setHead(Node* newHead){head = newHead;}

void LinkedList::removeHead(){
	Node* current = getHead();
	Node* next = current->getNext();

	next->setPrev(NULL);

	delete head;
	setHead(next);
}


void LinkedList::addToHead(Node::dataType value){
	Node* new_node = new Node; // Make new node
	new_node->setData(value); // Assign its data to the provided value
	new_node->setPrev(NULL); // It's the new head, no previous ptr
	new_node->setNext(head); // Set the next node for the new node to what was the head

	if (head != NULL){
		head->setPrev(new_node); // Set old head prev node to new head node
	}

	setHead(new_node); // Set new node to head
}

void LinkedList::addToTail(Node::dataType value){
	Node* new_node = new Node; // Make the new node

	if (getHead() == NULL){
		addToHead(value);
		return;
	}

	new_node->setData(value); // Set the nodes data to the provided data
	new_node->setNext(NULL); // It is the tail, no next ptr

	// Start at head, go to tail and set current tails next to this node and this nodes previous to the old tail

	Node* current = head;
	Node* next_in_list;

	while (current != NULL){
		next_in_list = current->getNext();
		if (next_in_list == NULL){ // If this node is the tail
			current->setNext(new_node);
			new_node->setPrev(current);
			break;
		}
		current = next_in_list;
	}
}

void LinkedList::print() const {
    Node* current = head;

    while (current != NULL) { // Go through items, printing them
        std::cout << current->getData() << " ";
        current = current->getNext();
    }

    std::cout << std::endl;
}

LinkedList& LinkedList::operator+= (const LinkedList& other) {

	Node* other_current;

    if (other.getHead() == NULL) {
        return *this;
    }

    bool start_head = true;

    if (getHead() == NULL){
    	Node::dataType new_head = other.getHead()->getData();
    	addToHead(new_head);
    	start_head = false;
    }


    // Start at the head of the other list unless we already took its head
    if (start_head){
    	other_current = other.getHead();
	}
	else{
		other_current = other.getHead()->getNext();
	}

    while (other_current != NULL) {
        // Create a copy of the other_current's data
        Node::dataType new_data = other_current->getData();

        // Add the new_data to the tail of the current list
        addToTail(new_data);

        // Move to the next node in the other list
        other_current = other_current->getNext();
    }
    return *this;
}

std::ostream& operator <<(ostream& out, LinkedList& list)
{
	if (list.getHead() == NULL){
		out << "List is empty." << endl;
	}

	Node* current = list.getHead();
	while(current != NULL)
	{	
		out << current->getData();
		out << " ";
		current = current->getNext();
	}
    return out;
}