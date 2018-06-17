#ifndef _EqualPointException_H
#define _EqualPointException_H
#include <iostream>
#include <exception>
#include "Triangle.h"
#include "Point.h"

using namespace std;

class EqualPointException :public exception {
public:
	EqualPointException(Point p1, Point p2) :exception("Index:"), p1(p1), p2(p2) {}
		ostream& rep(ostream & os) {
			os << "Съвпадащите точки са: " << endl << p1 << endl << p2 << endl;
		return os;
	}
private:
	Point p1;
	Point p2;
};

#endif