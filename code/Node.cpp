// Node.cpp
//  Miles Golding Sep 18 2017
// Definitions of the Node class methods


#include "Node.h"

#include <iostream>
using std::cout;
using std::endl;


Node::Node(double entry)
	: _entry(entry), _next(nullptr)
{
	cout << "Node( " << _entry << ", " << _next <<
		" ) created at " << this << endl;
}

Node::Node(double entry, Node * next)
	: _entry(entry), _next(next)
{
	cout << "Node( " << _entry << ", " << _next <<
		" ) created at " << this << endl;
}

Node::~Node()
{
	cout << "Node( " << _entry << ", " << _next <<
		" ) at " << this << " destroyed" << endl;
}
