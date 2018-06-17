#include "Point.h"
#include <iostream>

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {

}
Point::Point(const Point & rhs) : x(rhs.x),y(rhs.y),z(rhs.z) {

	}
Point& Point::operator=(const Point & rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
	}
//Метод за проверка дали две точки съвпадат
bool Point::operator==(const Point& rhs) {
	return (x == rhs.x&&y == rhs.y&&z == rhs.z);
	}
double Point::get_x() const {
	return x;
}
double Point::get_y() const {
	return y;
}
double Point::get_z() const {
	return z;
}
void Point::set_x(double x) {
	this->x = x;
}
void Point::set_y(double y) {
	this->y = y;
}
void Point::set_z(double z) {
	this->z = z;
}

 std::ostream& Point::inserter(std::ostream& out) const {
	 Element::inserter(out);
	 out << "x = " << x << "\n";
	 out << "y = " << y << "\n";
	 out << "z = " << z << "\n";
	 return out;
	}
 std::istream& Point::extractor(std::istream & in) {
	 std::cout << "Въведи x: ";
	 in >> x;
	 std::cout << "Въведи y: ";
	 in >> y;
	 std::cout << "Въведи z: ";
	 in >> z;
	 return in;
	}
std::istream& operator>>(std::istream& lhs, Point& rhs) {
	return rhs.extractor(lhs);
}