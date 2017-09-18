// LinkedList.cpp

// Miles Golding Sep 18 2017
// Definition of methods for the List class.

#include "LinkedList.h"

#include <iostream>
#include <utility>

using std::ostream;
using std::cout;
using std::endl;


List::List()
	: _first(nullptr)
{
	cout << "List no parameter constructor" << endl;
}


List::List(const List & other)
	: _first(clone(other._first))
{
	cout << "List copy constructor" << endl;
}


List::List(List && other)
	: _first(other._first)
{
	cout << "List move constructor" << endl;
	other._first = nullptr;
}


List::~List()
{
	cout << "List destructor" << endl;
	while (!empty())
	{
		removeFirst();
	}
}


List & List::operator=(const List & other)
{
	cout << "List copy assignment" << endl;
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		_first = clone(other._first);
	}

	return *this;
}


List & List::operator=(List && other)
{
	cout << "List move assignment" << endl;
	if (&other != this)
	{
		// swap the accesss pointers of other and this List
		Node * save = _first;
		_first = other._first;
		other._first = save;
	}

	return *this;

}

int List::size()
{
	counter = 0;
	if (!empty())
	{
		Node * ptr;
		ptr = _first;
		while (ptr != nullptr)
		{
			ptr = ptr->_next;
			counter++;
		}
	}
	cout << "Size of list: " << counter << endl;  //print statement
	return counter;
}

double List::sum()
{
	total = 0;
	if (!empty())
	{
		Node * ptr;
		ptr = _first;
		while (ptr != nullptr)
		{		
			total += ptr->_entry;
			ptr = ptr->_next;
		}
		cout << "sum: " << total << endl;  //print statement
		return total;
		
	}
}



bool List::empty() const
{ 	
	return _first == nullptr;
}

void List::insertAsLast(double x)
{

	Node * ptr = _first;
	if ( _first != nullptr) //if there are existing nodes
	{
		while(ptr->_next != nullptr)//traverse each node until the last pointer is stored
		{
			ptr = ptr->_next;
		}
		
		ptr->_next = new Node(x,nullptr);
	}
	else // if no existing nodes
	{
		_first = new Node(x, nullptr);
	}
	return;
}

void List::insertAsFirst(double x)
{
	_first = new Node(x, _first);
}


double List::removeFirst()
{
	double item = _first->_entry;
	Node * tempPtr = _first;
	_first = _first->_next;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << _first->_entry;
		Node * ptr = _first->_next;
		while (ptr != nullptr)
		{
			outfile << ", " << ptr->_entry;
			ptr = ptr->_next;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == nullptr)
	{
		return nullptr;
	}
	Node * first = new Node(ptr->_entry);
	Node * last = first;
	ptr = ptr->_next;
	while (ptr != nullptr)
	{
		last->_next = new Node(ptr->_entry);
		last = last->_next;
		ptr = ptr->_next;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == nullptr )
//   {
//      return nullptr;
//   }
//   return new Node( ptr->_entry, clone( ptr->_next ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
