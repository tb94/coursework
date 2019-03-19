#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

using namespace std;

class Vector3
{
	friend ostream& operator<<(ostream &, const Vector3 &);
	friend Vector3 operator*(const float &, const Vector3 &); // Float first

	private:
		float	x, y, z;

	public:
		Vector3	(float newX = 0, float newY = 0, float newZ = 0);
		Vector3 operator+ (const Vector3 &) const;
		Vector3 operator- (const Vector3 &) const;
		float operator* (const Vector3 &) const;
		Vector3 operator* (const float &) const;// Vector first
		float 	operator[] (int index) const;	// For reading
		float & operator[] (int Index);		// For writing
		bool 	operator== (const Vector3 &) const;
};

#endif
