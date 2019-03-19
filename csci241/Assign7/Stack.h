/****************************************************************
	FILE:		Stack.h
	AUTHOR:		Tim Bretz
	LOGON ID:	Z1697841
	DUE DATE:	4/14/2015

	PURPOSE:	Declares and defines the Node structure
			and Stack class
****************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node
{
	T	value;			// data type
	Node<T>	*next;			// next node in the stack

	Node(const T &data)
	{
		value = data;
		next = NULL;
	}
};

/*	Forward Declarations	*/
template <class T>
class Stack;

template <class T>
ostream& operator<< (ostream &, const Stack<T> &);

template <class T>
class Stack
{
	friend ostream& operator<< <>(ostream &, const Stack<T> &);

	private:
		Node<T>	*stkTop;		// first node in the stack
		int	stkSize;		// number of nodes in the stack
		void	copyList(const Stack<T> &);

	public:
		Stack();
		~Stack();
		Stack(const Stack<T> &);

		Stack<T>&	operator=(const Stack<T> &);

		void	clear();
		int	size() const;
		bool	empty() const;
		T	top()	const;
		void	push(const T &),
			pop();
};

/*	method definitions for the stack class	*/

/******************************************************************
	FUNCTION:	Stack()
	ARGUMENTS:	none
	RETURNS:	nothing
	NOTES:		set stack size to 0 and set stkTop to null
******************************************************************/

template <class T>
Stack<T>::Stack()
{
	stkSize = 0;
	stkTop = NULL;
}

/******************************************************************
	FUNCTION:	~Stack()
	ARGUMENTS:	none
	RETURNS:	nothing
	NOTES:		destructor; calls the clear() method
******************************************************************/

template <class T>
Stack<T>::~Stack()
{
	clear();
}

/******************************************************************
	FUNCTION:	Stack(const Stack<T> &)
	ARGUMENTS:	reference to a constant stack
	RETURNS:	nothing
	NOTES:		copy constructor;
			calls copyList(const Stack<T> &) method
******************************************************************/

template <class T>
Stack<T>::Stack(const Stack<T> &obj)
{
	copyList(obj);
}

/******************************************************************
	FUNCTION:	copyList(const Stack<T> &)
	ARGUMENTS:	reference to a constant Stack
	RETURNS:	no return type
	NOTES:		copies stack into a temporary stack,
			then into a new stack to maintain order
******************************************************************/

template <class T>
void Stack<T>::copyList(const Stack<T> &copy)
{
	Stack temp;		// temporary stack
	Node<T>* ptr;		// pointer to a temporary node

	stkSize = 0;
	stkTop = NULL;

/*	place the old stack into a temporary stack	*/
	for (ptr = copy.stkTop; ptr != NULL; ptr = ptr -> next)
		temp.push(ptr -> value);

/*	place the temporary stack into the copy of the old stack */
	for (ptr = temp.stkTop; ptr != NULL; ptr = ptr -> next)
		push(ptr -> value);
}

/******************************************************************
	FUNCTION:	Stack<T>& operator=(const Stack<T> &)
	ARGUMENTS:	reference to a constant Stack
	RETURNS:	reference to a Stack
	NOTES:		overloaded assignment operator;
			calls the copyList(const Stack<T> &) method
******************************************************************/

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &rightOp)
{
	if (this != &rightOp)		// check for self assignment
	{
		clear();		// delete old memory
		copyList(rightOp);	// allocate new memory and copy the data
	}

	return *this;			// return *this
}

/******************************************************************
	FUNCTION:	ostream& operator<< (ostream &,
						const Stack<T> &)
	ARGUMENTS:	reference to an ostream operator,
			reference to a constant stack
	RETURNS:	reference to an ostream operator
        NOTES:		overloaded output operator;
			outputs the stack as a whole
******************************************************************/

template <class T>
ostream& operator<<(ostream& leftOp, const Stack<T>& rightOp)
{
	Node<T>* ptr = rightOp.stkTop;		// temporary pointer to a node
						// to hold the place of the top of the stack
/*	while the pointer is not null	*/
/*	output the value of the pointer	*/
/*	then move on to the next node	*/
	while (ptr)
	{
		leftOp << ptr -> value << ' ';
		ptr = ptr -> next;
	}

	return leftOp;
}

/******************************************************************
	FUNCTION:	int size()
        ARGUMENTS:	none
        RETURNS:	integer
        NOTES:		returns the size of the stack
******************************************************************/

template <class T>
int Stack<T>::size() const
{
	return stkSize;
}

/******************************************************************
	FUNCTION:	T top()
	ARGUMENTS:	none
	RETURNS:	the template parameter
	NOTES:		returns the value of the top of the stack
******************************************************************/

template <class T>
T Stack<T>::top() const
{
	return stkTop -> value;
}

/******************************************************************
	FUNCTION:	bool empty()
	ARGUMENTS:	none
	RETURNS:	boolean
	NOTES:		returns true if the stack is empty,
			false if its not
******************************************************************/

template <class T>
bool Stack<T>::empty() const
{
	if(stkTop == NULL)
		return true;

	else
		return false;
}

/******************************************************************
	FUNCTION:       void push(const T &)
	ARGUMENTS:      reference to a constant item
			of the template parameter type
	RETURNS:        nothing
	NOTES:          inserts the item at the top of the stack
			and increases the size of the stack
******************************************************************/

template <class T>
void Stack<T>::push(const T &newValue)
{
	Node<T> * newNode = new Node<T>(newValue);		// pointer to a new node

/*	set the new node to the top of the stack	*/
	newNode -> next = stkTop;
	stkTop = newNode;

/*	increment the size of the stack		*/
	stkSize++;
}

/******************************************************************
	FUNCTION:	void pop()
	ARGUMENTS:	nothing
	RETURNS:	nothing
	NOTES:		removes the node at the top of the stack
			and decreases the size of the stack
******************************************************************/

template <class T>
void Stack<T>::pop()
{
	Node<T>	*temp = stkTop;		// Temporary node to hold the place of the node on top of the stack

/*	set the top of the stack to the next node down	*/
	stkTop = stkTop -> next;

/*	delete the old top node	*/
	delete temp;

/*	decrement the size of the stack	*/
	stkSize--;
}

/******************************************************************
	FUNCTION:	void clear()
	ARGUMENTS:	nothing
	RETURNS:	nothing
	NOTES:		sets the stack back to the empty state
******************************************************************/

template <class T>
void Stack<T>::clear()
{
/*	while the stack has more than 0 items	*/
/*	delete all the nodes			*/

	while (stkSize > 0)
	{
		pop();
	};

	stkSize = 0;
	stkTop = NULL;
}

#endif
