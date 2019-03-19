#include "Vector3.h"

using namespace std;

Vector3::Vector3(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

ostream & operator<< (ostream &leftOp, const Vector3 &rightOp)
{
	leftOp << "(" << rightOp.x << ", " << rightOp.y << ", " << rightOp.z << ")";

	return leftOp;
}

Vector3 Vector3::operator+ (const Vector3 &rightOp) const
{
	Vector3 result = *this;

	result.x += rightOp.x;
	result.y += rightOp.y;
	result.z += rightOp.z;

	return result;
}

Vector3 Vector3::operator- (const Vector3 &rightOp) const
{
	Vector3 result = *this;

	result.x -= rightOp.x;
	result.y -= rightOp.y;
	result.z -= rightOp.z;

	return result;
}

// scalar product
float Vector3::operator* (const Vector3 &rightOp) const
{
	Vector3 result = *this;

	result.x *= rightOp.x;
	result.y *= rightOp.y;
	result.z *= rightOp.z;

	return (float)(result.x + result.y + result.z);
}

// float first
Vector3 operator* (const float &leftOp, const Vector3 &rightOp)
{
	Vector3 result = rightOp;

	result.x *= leftOp;
	result.y *= leftOp;
	result.z *= leftOp;

	return result;
}

// vector first
Vector3 Vector3::operator* (const float &rightOp) const
{
	Vector3 result = *this;

	result.x *= rightOp;
	result.y *= rightOp;
	result.z *= rightOp;

	return result;
}


float Vector3::operator[] (int index) const	// For reading
{
	Vector3 result = *this;

	if (index == 0)
		return result.x;
	else if (index == 1)
		return result.y;
	else if (index == 2)
		return result.z;
	else
		return 0;
}

float & Vector3::operator[] (int index)		// For writing
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else if (index == 2)
		return z;
}

bool Vector3::operator== (const Vector3 & rightOp) const
{
	return (x == rightOp.x && y == rightOp.y && z == rightOp.z);
}

