#ifndef  VECTOR_H
#define VECTOR_H

#include "Point.h"
#include <iostream>

class Vector : public Point {
public:
	Vector(double = 0., double = 0., double = 0.);
	Vector(Point, Point);
	Vector(const Vector &);
	Vector& operator =(const Vector &);
	virtual ~Vector() {}
	//Метод за изчисляване на дължина на вектор
	double VectorLength()const;
	//Метод за изчисляване на посока на вектор
	Vector VectorDirection()const;
	//Метод за проекция на вектор върху друг вектор
	Vector VectorProjection(const Vector&);
	//Метод за проверка за нулев вектор
	bool ZeroVector()const;
	//Метод за проверка за успоредност на два вектора
	bool VectorsParallel(const Vector &)const;
	//Метод за проверка за перпендикулярност на два вектора
	bool VectorsPerpendicular(const Vector &)const;
	//Метод за събиране на два вектора
	Vector operator +(const Vector&)const;
	//Метод за изваждане на два вектора
	Vector operator -(const Vector&)const;
	//Метод за умножение на вектор с реално число
	Vector operator *(double);
	// Метод за скаларно произведение на два вектора
	double operator *(const Vector&);
	//Метод за векторно произведение на два вектора
	Vector operator ^(const Vector&);
	//Метод за векторно произведение на три вектора
	double operator ()(const Vector &, const Vector &);

	virtual std::ostream& inserter(std::ostream&) const;
	virtual std::istream& extractor(std::istream &);
private:

};
#endif