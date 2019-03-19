#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
	private:
		int 	height,
			base;

	public:
		Triangle(std::string, int, int);
		virtual void print() const;
		virtual double get_area() const;
};

#endif
