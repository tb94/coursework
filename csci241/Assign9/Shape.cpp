#include "Shape.h"
#include <string>
#include <iostream>

using namespace std;

Shape::Shape(const string &nColor)
{
	color = nColor;
}

Shape::~Shape()
{
}

void Shape::print() const
{
	cout << color;
}
