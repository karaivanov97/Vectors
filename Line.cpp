#include "Line.h"
#include<cmath>

Line::Line(Point & a, Vector& v) :b(a)
{
	a.set_x(v.get_x());
	a.set_y(v.get_y());
	a.set_z(v.get_z());
}

Line::Line(Point & a, Point & b) :a(a), b(b)
{
}
Line::Line(const Line &rhs) : Vector(rhs)
{
}

Line & Line::operator=(const Line& rhs)
{
	if (this != &rhs)
	{
		a = rhs.a;
		b = rhs.b;
	}
	return *this;
}

std::ostream& Line::inserter(std::ostream& out) const
{
	std::cout << "Първата точка е: \n" << a;
	std::cout << "Втората точка е: \n" << b;
	return out;
}


void Line::set_a(Point& a)
{
	this->a = a;
}

void Line::set_b(Point& b)
{
	this->b = b;
}

Point Line::get_a()const
{
	return a;
}

Point Line::get_b()const
{
	return b;
}
//Метод за намиране на посока на правата
Vector Line::LineDirection()const
{
	return Vector(b.get_x() - a.get_x(), b.get_y() - a.get_y(), b.get_z() - a.get_z());
}
//Метод за намиране на нормален вектор
Vector Line::NormalVector()const
{
	Vector vector(a, b);
	return vector.VectorDirection();
}
//Метод за намиране на ъгъл между две прави

double Line::AngleBetweenLines(const Line& line2)const
{
	Vector vector1(a,b);
	Vector vector2(line2.a, line2.b);
	double vector1Length = vector1.VectorLength();
	double vector2Length = vector2.VectorLength();
	double angle = (vector1*vector2) / (vector1Length*vector2Length);
	angle = acos(angle);

	return angle;
}
//Метод за проверка дали дадена точка лежи на дадената права
bool Line::operator +(const Point& rhs)const
{
	double x = (rhs.get_x() - a.get_x()) / (b.get_x() - a.get_x());
	double y = (rhs.get_y() - a.get_y()) / (b.get_y() - a.get_y());
	double z = (rhs.get_z() - a.get_z()) / (b.get_z() - a.get_z());
	return x == y == z;
}
//Метод за проверка дали дадена права пресича друга права
bool Line::operator &&(const Line & rhs)const
{
	Vector v1(a, b);
	Vector v2(rhs.a, rhs.b);
	double x = v1.get_x() / v2.get_x();
	double y = v1.get_y() / v2.get_y();
	double z = v1.get_z() / v2.get_z();
	return x != y&&x != z&&y != z;
}
//Метод за проверка дали дадена права е кръстосана с друга права
bool Line::operator !=(const Line& rhs) const
{
	return !(rhs == *this) && !(rhs || *this);
}
//Метод за проверка дали дадена права е успоредна на друга права

bool Line::operator ||(const Line& rhs)const
{
	double x1 = rhs.a.get_x() - a.get_x();
	double x2 = rhs.b.get_x() - b.get_x();

	double y1 = rhs.a.get_y() - a.get_y();
	double y2 = rhs.b.get_y() - b.get_y();

	double z1 = rhs.a.get_z() - a.get_z();
	double z2 = rhs.b.get_z() - b.get_z();

	return (x1 == x2&&y1 == y2&&z1 == z2&&x1 == y1&&y1 == z1);
}
//Метод за проверка дали дадена права съвпада с друга права
bool Line::operator==(const Line& rhs) const
{
	return (((*this) + rhs.a) && ((*this) + rhs.b));
}
//Метод за проверка дали дадена права е перпендикулярна на друга права
bool Line::operator |(const Line& rhs)const
{
	Vector vector1(a, b);
	Vector vector2(rhs.a, rhs.b);
	return vector1.VectorsPerpendicular(vector2);
}

