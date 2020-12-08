/*
*	@Author : Mehmet Gokcay Kabatas - github/MGokcayK
* 
*	Creating basic stack and queue structure.
* 
*	Date : 08/12/2020
*		Create structures.
*/
#pragma once 
#include <iostream>

namespace gstr
{
	/// <summary>
	/// Basic stack class. It is templated. 
	/// <para>
	/// It accept primitives such as  `int`, `float`, 
	/// `double`, 'char`,`string` etc. or custom 
	/// structures. 
	/// </para>
	/// <para>
	/// It has only `Capacity Contstructor` which assign its
	/// capacity.
	/// </para>
	/// </summary>
	/// <typeparam name="Dtype"></typeparam>
	template <class Dtype>
	class stack
	{
	private:
		Dtype* container;
		int loc = -1;
		int capacity = 0;
	
	public :

		/// <summary>
		/// `Capacity Constructor` which assign stack's capacity.
		/// </summary>
		/// <param name="capacity">: capacity of stack.</param>
		stack(int capacity)
		{
			this->container = new Dtype[capacity];
			this->capacity = capacity;
		}

		/// <summary>
		/// Push data to stack.
		/// </summary>
		/// <param name="data">: data of new item.</param>
		void push(Dtype data)
		{
			if (this->loc + 1 < this->capacity)
			{
				this->loc += 1;
				this->container[this->loc] = data;
			}
			else 
			{
				std::cout << "This stack is full! You can not add new item (" << data << ") to stack." << std::endl;
				return;
			}
		}

		/// <summary>
		/// Popping last added item.
		/// </summary>
		/// <returns>Last added item of stack.</returns>
		Dtype pop()
		{
			if (this->isEmpty())
			{
				return INT_MIN;
			}
			Dtype tmp = this->container[this->loc];
			this->container[this->loc] = NULL;
			this->loc -= 1;
			return tmp;
		}

		/// <summary>
		/// Show stack is empty or not.
		/// </summary>
		/// <returns>If stack is empty true, else false.</returns>
		bool isEmpty()
		{
			return this->loc > 0 ? false : true;
		}

		/// <summary>
		/// Count elements number of stack.
		/// </summary>
		/// <returns>Number of element in stack.</returns>
		int count()
		{
			return this->loc + 1;
		}

		/// <summary>
		/// Operator overloading of [] operator.
		/// </summary>
		/// <param name="index">: index of stack</param>
		/// <returns>Related item at index.</returns>
		Dtype operator[](const int index) 
		{
			return this->container[index];
		}		
	};


	/// <summary>
	/// Basic queue class. It is templated. 
	/// <para>
	/// It accept primitives such as  `int`, `float`, 
	/// `double`, 'char`,`string` etc. or custom 
	/// structures. 
	/// </para>
	/// <para>
	/// It has only `Capacity Contstructor` which assign its
	/// capacity.
	/// </para>
	/// </summary>
	/// <typeparam name="Dtype"></typeparam>
	template <class Dtype>
	class queue
	{
	private:
		Dtype* container;
		int loc = -1;
		int capacity = 0;

	public:

		/// <summary>
		/// `Capacity Constructor` which assign stack's capacity.
		/// </summary>
		/// <param name="capacity">: capacity of stack.</param>
		queue(int capacity)
		{
			this->container = new Dtype[capacity];
			this->capacity = capacity;
		}

		/// <summary>
		/// Push data to stack.
		/// </summary>
		/// <param name="data">: data of new item.</param>
		void push(Dtype data)
		{
			if (this->loc + 1 < this->capacity)
			{
				this->loc += 1;
				this->container[this->loc] = data;
			}
			else
			{
				std::cout << "This queue is full! You can not add new item (" << data << ") to stack." << std::endl;
				return;
			}
		}

		/// <summary>
		/// Popping first added item.
		/// </summary>
		/// <returns>First added item of queue.</returns>
		Dtype pop()
		{
			if (this->isEmpty())
			{
				return *this->container;
			}
			Dtype tmp = this->container[0];
			for (int i = 1; i < this->capacity; i++)
			{
				this->container[i-1] = this->container[i];
			}
			this->loc -= 1;
			return tmp;
		}

		/// <summary>
		/// Show queue is empty or not.
		/// </summary>
		/// <returns>If stack is empty true, else false.</returns>
		bool isEmpty()
		{
			return this->loc > 0 ? false : true;
		}

		/// <summary>
		/// Count elements number of stack.
		/// </summary>
		/// <returns>Number of element in stack.</returns>
		int count()
		{
			return this->loc + 1;
		}

		/// <summary>
		/// Operator overloading of [] operator.
		/// </summary>
		/// <param name="index">: index of queue</param>
		/// <returns>Related item at index.</returns>
		Dtype operator[](const int index)
		{
			return this->container[index];
		}
	};


}