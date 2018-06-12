#include "Vector.h"
#include<iostream>
#include <exception>
#include<cmath>
#include "VectorLenghtException.h"
Vector::Vector(double x, double y, double z): Point(x,y,z) {
}

Vector::Vector(Point& A, Point& B) : Point(B.get_x()-A.get_x(),B.get_y()-A.get_y(),B.get_z()-A.get_z()) {
}
Vector::Vector(const Vector & rhs) :Point (rhs){
}
Vector& Vector::operator=(const Vector & rhs) {
	if (this != &rhs) {
		Point::operator=(rhs);
		return*this;
	}
}
double Vector::VectorLength()const
{
	return sqrt(pow(get_x(), 2) + pow(get_y(), 2) + pow(get_z(), 2));
}
Vector Vector::VectorDirection()const
{
		return Vector((get_x()) / VectorLength(), (get_y()) / VectorLength(), (get_z()) / VectorLength());
}
std::ostream& Vector::inserter(std::ostream& out) const {
	Point::inserter(out);
	return out;
 }
 std::istream& Vector::extractor(std::istream & in) {
	 Point::extractor(in);
	 return in;
 }
 Vector Vector::VectorProjection(const Vector& rhs) {
	 double vecmult = get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z();
	 double div = (vecmult / pow(rhs.VectorLength(), 2));
	 return Vector(div*rhs.get_x(), div*rhs.get_y(), div*rhs.get_z());
 }
 bool Vector::ZeroVector()const {
	 return get_x() == 0 && get_y() == 0 && get_z() == 0;
 }
 bool Vector::VectorsParallel(const Vector & rhs)const {
	 return (get_x() / rhs.get_x()) == (get_y() / rhs.get_y()) == (get_z() / rhs.get_z());
 }
 bool Vector::VectorsPerpendicular(const Vector & rhs)const {
	 return (get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z()) == 0;
 }

 Vector Vector::operator +(const Vector& rhs) const {
	 return Vector(get_x() + rhs.get_x(), get_y() + rhs.get_y(), get_z() + rhs.get_z());
 }
 Vector Vector::operator -(const Vector& rhs)const {
	 return Vector(get_x() - rhs.get_x(), get_y() - rhs.get_y(), get_z() - rhs.get_z());
 }
 Vector Vector::operator *(double a) {
	 return Vector(get_x()*a, get_y()*a, get_z()*a);
 }
 double Vector::operator *(const Vector& rhs) {
	 return get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z();
 }
 Vector Vector::operator ^(const Vector& rhs) {
	 return Vector(get_y()*rhs.get_z() - get_z()*rhs.get_y(), get_z()*rhs.get_x() - get_x()*rhs.get_z(), get_x()*rhs.get_y() - get_y()*rhs.get_x());
 }
 double Vector::operator ()(const Vector & lhs, const Vector & rhs) {
	 double a = get_x()*lhs.get_y()*rhs.get_z();
	 double b = get_y()*lhs.get_z()*rhs.get_x();
	 double c = get_z()*lhs.get_x()*rhs.get_y();
	 double first = a + b + c;

	 double d = get_z()*lhs.get_y()*rhs.get_x();
	 double e = get_x()*lhs.get_z()*rhs.get_y();
	 double f = get_y()*lhs.get_x()*rhs.get_z();
	 double second = d + e + f;

	 return fabs(first - second);

 }
