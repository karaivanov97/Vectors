#ifndef _VectorLenghtException_H
#define _VectorLenghtException_H
#include <iostream>
#include <exception>
#include "Vector.h"
using namespace std;
class VectorLenghtException :public exception {
private: 
	Vector VectorLength;
public:
	VectorLenghtException() :exception("Index:") {}
	ostream& rep(ostream & os) {
		os << "Duljinata na vektora e nula " << endl;
		return os;
	}
};

#endif