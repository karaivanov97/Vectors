#ifndef _VectorLenghtException_H
#define _VectorLenghtException_H
#include <iostream>
#include <exception>
#include "Vector.h"
#include <exception>

using namespace std;

class VectorLenghtException :public exception {
public:
	VectorLenghtException( double reason ) :exception("Index:"), reason(reason) {}
	
	ostream& rep(ostream & os) {
		os << "The length of the vector is 0. " << endl;
		return os;
	}
private: 
	double reason;
};

#endif