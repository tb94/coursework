#include <iostream>
#include "Triangle.h"

using namespace std;

Triangle::Triangle(std::string nColor, int nHeight, int nBase)
: Shape(nColor)
{
	height = nHeight;
	base = nBase;
}

void Triangle::print() const
{
	Shape::print();
	cout << " triangle, height " << height << ", base " << base
		<< ", area " << get_area() << endl;
}

double Triangle::get_area() const
{
	return .5 * (double)base * (double)height;
}
