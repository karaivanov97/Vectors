#ifndef  VECTOR_H
#define VECTOR_H

#include "Point.h"
#include <iostream>

class Vector : public Point {
public:
	Vector(double = 0., double = 0., double = 0.);
	Vector(Point&, Point&);
	Vector(const Vector &);
	Vector & operator =(const Vector &);
	double VectorLength()const;
	Vector VectorDirection()const;

	virtual std::ostream& inserter(std::ostream&) const;
	virtual std::istream& extractor(std::istream &);
	Vector VectorProjection(const Vector&);
	bool ZeroVector()const;
	bool VectorsParallel(const Vector &)const;
	bool VectorsPerpendicular(const Vector &)const;

	Vector operator +(const Vector&)const;
	Vector operator -(const Vector&)const;
	Vector operator *(double);
	double operator *(const Vector&);
	Vector operator ^(const Vector&);
	double operator ()(const Vector &, const Vector &);

private:

};
#endif