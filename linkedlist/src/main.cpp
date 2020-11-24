#include <iostream>
#include "llist.h"

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

	return 0;
}