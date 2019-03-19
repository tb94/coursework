#ifndef QUEUE
#define QUEUE

#include <stdexcept>
#include <iostream>

using namespace std;

class Queue
{
	friend ostream & operator<< (ostream &, const Queue &);

	private:
		int *		qArray;
		unsigned int	qCap;
		int		qSize, qFront, qRear;

	public:
		Queue();
		~Queue();
		Queue(const Queue &);

		Queue &	operator=(const Queue &);
		bool operator!=(const Queue &) const;

		unsigned int 	size() const,
				capacity() const;
		bool		empty() const;
		int		front() const,
				back() const;
		void		clear(),
				push(int),
				pop(),
				reserve(unsigned int);

};

#endif
