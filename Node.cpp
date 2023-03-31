// Node class definition
// Eddie Young 30.03.23 c3431624


#include <iostream>
#include "Node.h"

Node::Node() : prev(NULL), next(NULL){}

Node::~Node() {
	next = NULL;
	prev = NULL;
}

Node* Node::getNext(){
	return next;
}

Node* Node::getPrev(){
	return prev;
}

void Node::setNext(Node* newNext){
	next = newNext;
}

void Node::setPrev(Node* newPrev){
	prev = newPrev;
}

Card Node::getData(){
	return data;
}

void Node::setData(Node::dataType value){
	data = value;
}