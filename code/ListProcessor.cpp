// ListProcessor.cpp

//  Miles Golding Sep 18 2017

// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"

#include <iostream>
using std::cout;
using std::endl;



int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cows.insertAsLast(8.01);
	cout << "cows list  :  " << cows << endl << endl;

	cows.removeFirst();
	cows.insertAsLast(8.02);
	cout << "cows list  :  " << cows << endl << endl;
	cows.size();
	cows.sum();

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;
	

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	horses.insertAsLast(8.05);
	cows.insertAsFirst(6.78);
	cows.insertAsLast(8.03);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;
	cows.size();
	horses.size();
	cows.sum();
	horses.sum();

	List pigs;
	pigs.insertAsLast(7192);
	pigs.insertAsLast(1427);
	pigs.size();
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;


	cout << "End of code" << endl;

	return 0;
}

