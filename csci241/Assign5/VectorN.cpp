#include "VectorN.h"

using namespace std;

VectorN::VectorN()
{
	n = 0;
	ar = new float[n];
}

ostream & operator<< (ostream &leftOp, const VectorN &rightOp)
{
	leftOp << "(";
	int i = 0;
	while(i < rightOp.n)
	{
        	leftOp << rightOp.ar[i];

		if (rightOp.n > 1 && i < (rightOp.n - 1))
			leftOp << ", ";
		i++;
	}
	leftOp << ")";

        return leftOp;
}


VectorN::VectorN(double newArray[], unsigned int k)
{
	n = k;
	ar = new float[n];
	copy(newArray, newArray + n, ar);
}

unsigned int VectorN::size() const
{
	return n;
}

void VectorN::clear()
{
	n = 0;
}

double VectorN::operator[] (int index) const	// For reading
{
	VectorN result = *this;

	return result.ar[index];
}

float & VectorN::operator[] (int index)
{
	return ar[index];
}

VectorN::VectorN(const VectorN &obj)
{
	n = obj.n;
	ar = new float[n];
	copy(obj.ar, obj.ar + n, ar);
}

VectorN & VectorN::operator= (const VectorN & other)
{
	int M, N;

	if (*this == other);
	else
	{
		if (n != 0)
			delete [] ar;

		N =  other.n;
		ar = new float[N];

		for (M = 0; M < N; M++)
		{
			ar[M] = other.ar[M];
			n = other.n;
		}
	}

	return *this;
}

bool VectorN::operator== (const VectorN & rightOp) const
{
	if (n != rightOp.n)
		return false;

	for (int i = 0; i < n; i++)
	{
		if (ar[i] != rightOp.ar[i])
			return false;
	}

	return true;
}

VectorN VectorN::operator+ (const VectorN &rightOp) const
{
	VectorN result;

	if (this->n <= rightOp.n)
		result.n = this->n;
	else
		result.n = rightOp.n;

	int i = 0;

	while(i < result.n)
	{
		result.ar[i] = this->ar[i] + rightOp.ar[i];
		i++;
	}

	return result;
}

VectorN VectorN::operator- (const VectorN &rightOp) const
{
	VectorN result;

	if (this->n <= rightOp.n)
		result.n = this->n;
	else
		result.n = rightOp.n;

	int i = 0;

	while(i < result.n)
	{
		result.ar[i] = this->ar[i] - rightOp.ar[i];
		i++;
	}

	return result;
}

double VectorN::operator*(const VectorN &rightOp) const
{
	VectorN result;

	if (this->n <= rightOp.n)
		result.n = this->n;
	else
		result.n = rightOp.n;

	int 	i = 0;
	double	sum = 0;

	while (i < result.n)
	{
		sum += this->ar[i] * rightOp.ar[i];
		i++;
	}

	return sum;
}

VectorN VectorN::operator*(const float &rightOp) const
{
	VectorN result = *this;

	for (int i = 0; i < result.n; i++)
	{
		result.ar[i] *= rightOp;
	}

	return result;
}

VectorN operator*(const double &leftOp, const VectorN &rightOp)
{
	VectorN result = rightOp;

	for (int i = 0; i< result.n; i++)
	{
		result.ar[i] *= leftOp;
	}

	return result;
}

double VectorN::at(int sub) const throw(out_of_range) //Read
{
        VectorN result = *this;

	if (sub < 0 || sub >= result.n)
		throw out_of_range("subscript out of range");
	else
        	return result.ar[sub];
}

float & VectorN::at(int sub) throw(out_of_range)
{
	if (sub < 0 || sub >= n)
		throw out_of_range("subscript out of range");
	else
		return ar[sub];
}
