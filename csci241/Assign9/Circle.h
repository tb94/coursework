#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
	private:
		int radius;

	public:
		Circle(string nColor, int r);
		virtual void print() const;
		virtual double get_area() const;
};

#endif
