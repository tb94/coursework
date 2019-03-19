#ifndef VECTORN
#define VECTORN

#include <iostream>
#include <stdexcept>
#include <stddef.h>

using namespace std;

class VectorN
{
        friend ostream & operator<< (ostream &leftOp, const VectorN &rightOp);
	friend VectorN operator*(const double &, const VectorN &);

	private:
		unsigned int n;
		float* ar;

	public:
		VectorN ();
		VectorN (double newArray[], unsigned int);
		VectorN (const VectorN &obj);
//		~VectorN();

		double 		operator*(const VectorN &) const;
		VectorN 	operator*(const float &) const;

		VectorN &	operator=(const VectorN & other);
		void 		clear();
		unsigned int 	size() const;
		VectorN 	operator+(const VectorN &) const;
		VectorN		operator-(const VectorN &) const;
		double 		operator[](int index) const;		//Read
		float & 	operator[](int index);			//Write
		double 		at(int sub) const throw(out_of_range);	//Read
		float & 	at(int sub) throw(out_of_range);	//Write
		bool	 	operator==(const VectorN &) const;
};

#endif
