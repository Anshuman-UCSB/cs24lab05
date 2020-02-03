// intlist.cpp
// Implements class IntList
// Anshuman Dash 2/3/2020

#include "intlist.h"

#include <iostream>
using std::cout;

// return sum of values in list
int IntList::sum() const {
	int total = 0;
	for(Node* p = first; p; p=p->next){
		total+= p->info;
	}
	return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    	for(Node* p = first; p; p = p->next){
		if(p->info == value){
			return true;
		}
	}
	return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
   	if(first == 0)
		return 0;
	int ret = first->info;
	for(Node* p = first; p; p= p->next){
		if(p->info>ret){
			ret = p->info;
		}
	}
	return ret;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
   	if(first == 0){
		return 0;
	}
	int count = 0;
	int sum = 0;
	for(Node* p = first;p;p=p->next){
		count++;
		sum+=p->info;
	}
	return((sum+0.0)/count);
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = first;
    first = n;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        Node *garbage = n;
        n = n->next;
        delete garbage;
    }
}

// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
