#ifndef _VectorLenghtException_H
#define _VectorLenghtException_H
#include <iostream>
#include <exception>
#include "Vector.h"
#include <exception>

using namespace std;

class VectorLenghtException :public exception {
public:
	VectorLenghtException( Vector reason ) :exception("Index:"), reason(reason) {}
	
	ostream& rep(ostream & os) {
		os << "Duljinata na vektora e nula " << endl;
		return os;
	}
private: 
	Vector reason;
};

#endif