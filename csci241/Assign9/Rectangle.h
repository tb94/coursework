#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape
{
	private:
		int	height,
			width;

	public:
		Rectangle(string, int, int);
		virtual void print() const;
		virtual double get_area() const;
};

#endif
