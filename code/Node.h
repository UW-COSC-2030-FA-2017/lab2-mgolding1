// Node.h

//  Miles Golding Sep 18 2017
// Declare the Node class.

// Node uses public access to simplify code in the
// container classes that use Nodes.  Client access is
// controlled by the container classes.

// The constructors and destructor are verbose to facilitate
// tracking of memory leaks.

// The default constructor and assignment operator are
// declared private so they cannot be called.

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>


class Node
{
public:
	double _entry;
	Node * _next;

public:
	// Constructors

	// post: this Node contains entry and a null pointer
	explicit Node(double entry);

	// post: this Node contains entry and next
	Node(double entry, Node * next);

	// Destructor

	~Node();

	// Inaccessible standard functions
	Node() = delete;
	Node(const Node &) = delete;
	Node(Node &&) = delete;
	const Node & operator=(const Node &) = delete;
	const Node & operator=(Node &&) = delete;
};

#endif
