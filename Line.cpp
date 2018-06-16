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

std::ostream& Line::inserter(std::ostream &out) const
{
	std::cout << "First point: \n" << a;
	std::cout << "Second point: \n" << b;
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

Vector Line::LineDirection()const
{
	return Vector(b.get_x() - a.get_x(), b.get_y() - a.get_y(), b.get_z() - a.get_z());
}

Vector Line::NormalVector()const
{
	Vector v(a, b);
	return v.VectorDirection();
}

double Line::AngleBetweenLines(const Line& line2)const
{
	Vector v1(a,b);
	Vector v2(line2.a, line2.b);
	double v1Length = v1.VectorLength();
	double v2Length = v2.VectorLength();
	double angle = (v1*v2) / (v1Length*v2Length);
	angle = acos(angle);

	return angle;
}

bool Line::operator +(const Point& rhs)const
{
	double x = (rhs.get_x() - a.get_x()) / (b.get_x() - a.get_x());
	double y = (rhs.get_y() - a.get_y()) / (b.get_y() - a.get_y());
	double z = (rhs.get_z() - a.get_z()) / (b.get_z() - a.get_z());
	return x == y == z;
}

bool Line::operator &&(const Line & rhs)const
{
	Vector v1(a, b);
	Vector v2(rhs.a, rhs.b);
	double x = v1.get_x() / v2.get_x();
	double y = v1.get_y() / v2.get_y();
	double z = v1.get_z() / v2.get_z();
	return x != y&&x != z&&y != z;
}

bool Line::operator !=(const Line& rhs) const
{
	return !(rhs == *this) && !(rhs || *this);
}
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

bool Line::operator==(const Line& rhs) const
{
	return (((*this) + rhs.a) && ((*this) + rhs.b));
}
bool Line::operator |(const Line& rhs)const
{
	Vector v1(a, b);
	Vector v2(rhs.a, rhs.b);
	return v1.VectorsPerpendicular(v2);
}

