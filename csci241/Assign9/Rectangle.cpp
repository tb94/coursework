#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string nColor, int nHeight, int nWidth)
: Shape(nColor)
{
	height = nHeight;
	width = nWidth;
}

void Rectangle::print() const
{
	Shape::print();
	cout << " rectangle, height " << height << ", width " << width
		<< ", area " << get_area() << endl;
}

double Rectangle::get_area() const
{
	return width * height;
}
