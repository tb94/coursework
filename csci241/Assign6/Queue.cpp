#include "Queue.h"
#include <iostream>
#include <vector>
using namespace std;

Queue::Queue()
{
	qCap = 1;
	qSize = 0;
	qArray = new int[qCap];
	qFront = 0;
	qRear = qCap -1;
}

Queue::~Queue()
{
	delete [] qArray;
}

Queue::Queue(const Queue &obj)
{
	qCap = obj.qCap;
	qSize = obj.qSize;
	qArray = new int[qCap];
	qFront = obj.qFront;
	qRear = obj.qRear;
	copy(obj.qArray, obj.qArray + qCap, qArray);
}

Queue & Queue::operator= (const Queue &other)
{
	int M, N;

	if(this != &other)
	{
		if (qSize != 0)
			delete [] qArray;

		N = other.qCap;
		qArray = new int[N];

		for (M = 0; M < N; M++)
			qArray[M] = other.qArray[M];
		qSize = other.qSize;
		qCap = other.qCap;
		qFront = other.qFront;
		qRear = other.qRear;
	}

	return *this;
}

ostream & operator<< (ostream &leftOp, const Queue &rightOp)
{
	int current, i;
	for (current = rightOp.qFront, i = 0; i < (int) rightOp.qSize; ++i)
	{
		// Print queue element at subscript i
		leftOp << rightOp.qArray[current] << ' ';

		// Increment i, wrapping around to front of queue array if necessary
		current = (current + 1) % rightOp.qCap;
	}

	return leftOp;
}

void Queue::clear()
{
	qSize = 0;
	qFront = 0;
	qRear = qCap;
}

unsigned int Queue::size() const
{
	return qSize;
}

unsigned int Queue::capacity() const
{
	return qCap;
}

bool Queue::empty() const
{
	return (qSize == 0);
}

int Queue::front() const
{
	if (qSize == 0)
		throw underflow_error("queue underflow on front()");
	else
		return qArray[qFront];
}

int Queue::back() const
{
	if (qSize == 0)
		throw underflow_error("queue underflow on back()");
	else
		return qArray[qRear];
}


void Queue::push(int insert)
{
	if (qSize == qCap)
		reserve(qCap * 2);

	qRear = (qRear + 1) % qCap;
	qArray[qRear] = insert;
	qSize++;
}

void Queue::pop()
{
	if (qSize == 0)
		throw underflow_error("queue underflow on pop()");
	qFront = (qFront + 1) % qCap;
	qSize--;
}

void Queue::reserve(unsigned int newCap)
{
	int* copyArray = new int[newCap];

	int current = qFront;
	for(unsigned int i = 0; i < qSize; i++)
	{
		copyArray[i] = qArray[current];
		current = (current + 1) % qCap;
	}

	qCap = newCap;
	delete [] qArray;
	qArray = copyArray;
	qFront = 0;
	qRear = qSize - 1;
}

bool Queue::operator!= (const Queue &rightOp) const
{
	if	(qCap == rightOp.qCap &&
		qSize == rightOp.qSize &&
		qFront == rightOp.qFront &&
		qRear == rightOp.qRear)
		return false;

	for(int i = 0; i < qCap; i++)
	{
		if (qArray[i] == rightOp.qArray[i])
			return false;
	}

	return true;
}
