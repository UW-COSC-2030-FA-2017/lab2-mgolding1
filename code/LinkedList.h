// LinkedList.h

//  Miles Golding Sep 18 2017
// Declaration of the List class.

// A List stores and manages a sequence of doubles.

// This version uses a pointer to the first Node of a 
//   singly linked list of Nodes.



#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Node.h"

#include <iostream>

#define ulong unsigned long


class List
{
public:
	//*** Standard functions ***

	// Default constructor
	// post: this List is empty.
	List();

	// Copy constructor
	// post: this List now stores a copy of the sequence stored
	//         in other
	List(const List & other);

	// Move constructor
	// post: this List now stores the sequence that was stored
	//         in other; other is empty
	List(List && other);	

	

	// Destructor
	// post: all the Nodes of this List have been destroyed.
	~List();

	// Copy assignment operator
	// post: this List now stores a copy of the sequence stored
	//         in other, this List has been returned
	List & operator=(const List & other);

	// Move assignment operator
	// post: this List now stores sequence that was stored
	//         in other, this List has been returned; other is empty
	List & operator=(List && other);

	int List::size();

	double List::sum();

	void insertAsLast(double x);

	//*** Accessors ***

	// post: true has been returned just if this List is
	//         empty.
	bool empty() const;

	// post: the doubles in this List have been written to
	//         outfile.
	void print(std::ostream & outfile) const;


	//*** Mutators ***

	// post: x has been added as the first double in this
	//         List.
	void insertAsFirst(double x);

	// pre:  this List is not empty.
	// post: the first double in this List has been removed 
	//         from this List and has been returned.
	double removeFirst();

private:
	//*** Helper functions ***
	// process part of the linked structure

	// post: a pointer to a copy of the linked structure
	//         targeted by ptr has been returned.
	static Node * clone(Node * ptr);


private:
	Node * _first;
	int counter;
	double total;

};


//*** Auxiliary functions ***

// post: the doubles in list have been written to outfile
std::ostream & operator<<(std::ostream & outfile, const List & list);

#endif
