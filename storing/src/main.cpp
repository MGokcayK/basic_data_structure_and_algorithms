#include <iostream>
#include "store.h"
#include "tree.h"

// Custom structure 
struct cstr
{
	int v;
	char c;
};

// custom structure operator `<<` overloading
std::ostream& operator<<(std::ostream& os, const cstr& p)
{
	return os << p.v << " / " << p.c;
}

void stack_example()
{
	gstr::stack<int> s(5);

	s.push(5);
	s.push(2);
	s.push(3);
	s.push(23);


	std::cout << "\n STACK Example Items" << std::endl;
	for (int i = 0; i < s.count(); i++)
	{
		std::cout << s[i] << std::endl;
	}


	int g = s.pop();
	std::cout << " Popped Stack Item : " << g << std::endl;

	int h = s.pop();
	std::cout << " Popped Stack Item : " << h << std::endl;

	std::cout << " Remainin Items in Stack " << std::endl;
	for (int i = 0; i < s.count(); i++)
	{
		std::cout << s[i] << std::endl;
	}

	std::cout << " is empty : " << s.isEmpty() << std::endl;
}


void queue_example()
{
	gstr::queue<int> q(10);

	q.push(5);
	q.push(2);
	q.push(3);
	q.push(23);
	q.push(54);

	std::cout << "\n QUEUE Example Items" << std::endl;
	for (int i = 0; i < q.count(); i++)
	{
		std::cout << q[i] << std::endl;
	}


	int g = q.pop();
	std::cout << " Popped Queue Item : " << g << std::endl;

	int h = q.pop();
	std::cout << " Popped Queue Item : " << h << std::endl;

	std::cout << " Remainin Items in Queue " << std::endl;
	for (int i = 0; i < q.count(); i++)
	{
		std::cout << q[i] << std::endl;
	}

	std::cout << " is empty : " << q.isEmpty() << std::endl;
}


void customDtype_example()
{
	gstr::queue<cstr> c(5);
	cstr a1;
	a1.c = 'a';
	a1.v = 1;

	c.push(a1);

	cstr a2;
	a2.c = 'b';
	a2.v = 2;

	c.push(a2);

	cstr a3;
	a3.c = 'c';
	a3.v = 3;

	c.push(a3);

	std::cout << "\n QUEUE Custom Dtype Example Items" << std::endl;
	for (int i = 0; i < c.count(); i++)
	{
		std::cout << c[i] << std::endl;
	}


	cstr g = c.pop();
	std::cout << " Popped Queue Item : " << g << std::endl;

	std::cout << " Remainin Items in Queue " << std::endl;
	for (int i = 0; i < c.count(); i++)
	{
		std::cout << c[i] << std::endl;
	}

	std::cout << " is empty : " << c.isEmpty() << std::endl;

}

void binary_tree_example()
{
	int data[] = { 47,25,77,11,43,65,93,7,17,31,44,68 };
	
	gstr::binaryTree<int> tree;
	
	for (auto item : data)
	{
		tree.addNode(item, true);
	}

	// tree print orders

	//tree.inorder();
	//tree.preorder();
	tree.postorder();
}

int main()
{
	//stack_example();
	//queue_example();
	//customDtype_example();

	binary_tree_example();

	return 0;
}
