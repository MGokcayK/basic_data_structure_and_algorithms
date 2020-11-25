/*
*	@Author : Mehmet Gokcay Kabatas - github:/MGokcayK
*
*	Main purpose of the project is basic linked list structure
* 
*	Data: 24/11/2020
*		One directional linked list created
*/

#pragma once
#include <iostream>
#include <string>


/// <summary>
/// Basic Linked List class. It is templated. 
/// <para>
/// It accept primitives such as  `int`, `float`, 
/// `double`, 'char`,`string` etc. or custom 
/// structures. For custom structures please 
/// overload the `&lt;&lt;` operator.
/// </para>
/// <para>
/// It has only `Default Contstructor`.
/// </para>
/// </summary>
/// <typeparam name="Dtype"></typeparam>
template <class Dtype>
class LinkedList 
{
private:
	// basic node struct
	struct Node
	{
		Dtype data;
		Node* next;
	};

	// head node for list.
	Node* head;

	// printing node `n`'s value and adress.
	void printNode(Node* n)
	{
		std::cout << "Value : " << n->data << " Address : " << &n->data << std::endl;
	}

public:
	/// <summary>
	/// Default Constructor.
	/// </summary>
	LinkedList()
	{
		this->head = nullptr;
	};

	/// <summary>
	/// Add value to end of list.
	/// </summary>
	/// <param name="value">: value of new item.</param>
	void push_back(Dtype value)
	{
		Node* tempNode = new Node;
		tempNode->data = value;
		tempNode->next = nullptr;

		if (this->head == nullptr)
		{
			this->head = tempNode;
		}
		else
		{
			Node* last = this->head;
			while (last->next != nullptr)
			{
				last = last->next;
			}
			last->next = tempNode;
		}
	};

	/// <summary>
	/// Add value as first element of list.
	/// </summary>
	/// <param name="value">: value of new item.</param>
	void push_front(Dtype value)
	{
		Node* tempNode = new Node;
		tempNode->data = value;
		tempNode->next = nullptr;

		if (this->head == nullptr)
		{
			this->head = tempNode;
		}
		else
		{
			Node* tempHead = this->head;
			this->head = tempNode;
			this->head->next = tempHead;
		}
	};

	/// <summary>
	/// Add value to after `after` value.
	/// </summary>
	/// <param name="value">: value of new item.</param>
	/// <param name="after">: value that new item add next to it.</param>
	void push_after(Dtype value, Dtype after)
	{
		Node* tempNode = new Node;
		tempNode->data = value;
		tempNode->next = nullptr;

		if (this->head == nullptr)
		{
			this->head = tempNode;
		}
		else
		{
			Node* last = this->head;
			while (last->next != nullptr)
			{
				last = last->next;
				if (last->data == after)
				{
					break;
				}
			}
			tempNode->next = last->next;
			last->next = tempNode;
		}
	};

	/// <summary>
	/// Delete item which equal to `value`.
	/// </summary>
	/// <param name="value">: Delete item value.</param>
	void deleteItem(Dtype value)
	{
		Node* tempNode;
		Node* last = this->head;

		// make sure that if list has one element delete it.
		if (last->next == nullptr)
		{
			if (last->data == value)
			{
				this->head->data = NULL;
				return;
			}
		}

		// list has more than one item
		while (last->next != nullptr)
		{
			if (last->next->data == value)
			{
				tempNode = last->next->next;
				break;
			}
			last = last->next;
		}
		last->next = tempNode;		
	};

	/// <summary>
	/// Printing all item in the list.
	/// </summary>
	void print()
	{
		std::cout << " Printing.. " << std::endl;
		Node* last = this->head;
		printNode(last);
		while (last->next != nullptr)
		{
			last = last->next;
			printNode(last);
		}
	};


};