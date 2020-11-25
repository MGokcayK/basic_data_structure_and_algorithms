#include <iostream>
#include "llist.h"

struct cstr
{
	int v;
	char c;
};

std::ostream& operator<<(std::ostream& os, const cstr& p)
{
	return os << p.v << " / " << p.c;
}

int main()
{
	
	LinkedList<int> ll; // create list which stores int item
	ll.push_back(3); // add `3` to end of list
	ll.push_back(5); // add `5` to end of list
	ll.push_back(78); // add `78` to end of list
	ll.push_back(95); // add `95` to end of list
	ll.push_front(10); // add `10` to front of list
	ll.push_after(6, 5); // add `6` to list after `5` 
	ll.deleteItem(78); // delete `78` from list
	ll.print(); // print all elements and their adresses

	// custom structure example

	// creating instance of custom structure and initilaize them
	cstr a1;
	a1.c = 'a';
	a1.v = 1;

	cstr a2;
	a2.c = 'b';
	a2.v = 2;

	LinkedList<cstr> LLCust; // create custom linkedlist 
	LLCust.push_back(a1); // add to back
	LLCust.push_front(a2); // add to front
	LLCust.print(); // print

	return 0;
}


