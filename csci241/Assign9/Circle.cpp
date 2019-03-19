#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(string nColor, int r)
: Shape(nColor)
{
	radius = r;
}

void Circle::print() const
{
	Shape::print();
	cout << " circle, radius " << radius << ", area " << get_area() << endl;
}

double Circle::get_area() const
{
	return 3.14159 * (double)(radius * radius);
}
