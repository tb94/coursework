#include <vector>
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	vector <Shape *> v(6);

	v[0] = new Circle("green", 10);
	v[1] = new Rectangle("red", 8, 6);
	v[2] = new Triangle("yellow", 8, 4);
	v[3] = new Triangle("black", 4, 10);
	v[4] = new Circle("orange", 5);
	v[5] = new Rectangle("blue", 3, 7);

	cout << "\nPrinting all shapes:\n" << endl;

	for(int i = 0; i <= 5; i++)
		v[i] -> print();

	cout << "\nPrinting all triangles:\n" << endl;

	for(int i = 0; i <= 5; i++)
	{
		Triangle *tPtr;

		tPtr = dynamic_cast<Triangle *>(v[i]);

		if(tPtr != 0)
			v[i] -> print();
	}

	return 0;
}
