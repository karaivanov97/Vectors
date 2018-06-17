#include "Vector.h"
#include<iostream>
#include <exception>
#include<cmath>
#include "VectorLenghtException.h"

Vector::Vector(double x, double y, double z): Point(x,y,z) {
}
Vector::Vector(Point  A, Point  B) : Point(B.get_x() - A.get_x(), B.get_y() - A.get_y(), B.get_z() - A.get_x())
{
}
Vector::Vector(const Vector & rhs) :Point (rhs){
}
Vector& Vector::operator=(const Vector & rhs) {
	if (this != &rhs) {
		Point::operator=(rhs);
		return*this;
	}
}
//Метод за изчисляване на дължина на вектор
double Vector::VectorLength()const
{
	return sqrt(pow(get_x(), 2) + pow(get_y(), 2) + pow(get_z(), 2));
}
//Метод за изчисляване на посока на вектор
Vector Vector::VectorDirection()const
{
		if (VectorLength() == 0) { throw VectorLenghtException(VectorLength()); }
	return Vector((get_x()) / VectorLength(), (get_y()) / VectorLength(), (get_z()) / VectorLength());
}
//Метод за проекция на вектор върху друг вектор
 Vector Vector::VectorProjection(const Vector& rhs) {
	 double vecmult = get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z();
	 double div = (vecmult / pow(rhs.VectorLength(), 2));
	 return Vector(div*rhs.get_x(), div*rhs.get_y(), div*rhs.get_z());
 }
 //Метод за проверка за нулев вектор

 bool Vector::ZeroVector()const {
	 return get_x() == 0 && get_y() == 0 && get_z() == 0;
 }
 //Метод за проверка за успоредност на два вектора
 bool Vector::VectorsParallel(const Vector & rhs)const {
	 if (VectorLength() == 0||rhs.VectorLength()==0) { throw VectorLenghtException(VectorLength()); }
	 return (get_x() / rhs.get_x()) == (get_y() / rhs.get_y()) == (get_z() / rhs.get_z());
 }
 //Метод за проверка за перпендикулярност на два вектора
 bool Vector::VectorsPerpendicular(const Vector & rhs)const {
	 if (VectorLength() == 0 || rhs.VectorLength() == 0) { throw VectorLenghtException(VectorLength()); }
	 return (get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z()) == 0;
 }
 //Метод за събиране на два вектора
 Vector Vector::operator +(const Vector& rhs) const {
	 return Vector(get_x() + rhs.get_x(), get_y() + rhs.get_y(), get_z() + rhs.get_z());
 }
 //Метод за изваждане на два вектора
 Vector Vector::operator -(const Vector& rhs)const {
	 return Vector(get_x() - rhs.get_x(), get_y() - rhs.get_y(), get_z() - rhs.get_z());
 }
 //Метод за умножение на вектор с реално число
 Vector Vector::operator *(double real) {
	 return Vector(get_x()*real, get_y()*real, get_z()*real);
 }
 // Метод за скаларно произведение на два вектора
 double Vector::operator *(const Vector& rhs) {
	 return get_x()*rhs.get_x() + get_y()*rhs.get_y() + get_z()*rhs.get_z();
 }
 //Метод за векторно произведение на два вектора
 Vector Vector::operator ^(const Vector& rhs) {
	 return Vector(get_y()*rhs.get_z() - get_z()*rhs.get_y(), get_z()*rhs.get_x() - get_x()*rhs.get_z(), get_x()*rhs.get_y() - get_y()*rhs.get_x());
 }
 //Метод за векторно произведение на три вектора
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
std::ostream& Vector::inserter(std::ostream& out) const {
	Point::inserter(out);
	return out;
 }
 std::istream& Vector::extractor(std::istream & in) {
	 Point::extractor(in);
	 return in;
 }
