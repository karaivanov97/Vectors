#include "Triangel.h"
#include<cmath>

Triangle::Triangle(Point A, Point B, Point C) :A(A), B(B), C(C)
{
}

Triangle::Triangle(const Triangle& rhs) : Point(rhs)
{
}

Triangle & Triangle:: operator=(const Triangle & rhs)
{
	if (this != &rhs)
	{
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
	}
	return *this;
}

void Triangle::TriangleType()const
{
	double AC = fabs(sqrt(pow(C.get_x() - A.get_x(), 2) + (pow(C.get_y() - A.get_y(), 2)) + (pow(C.get_z() - A.get_z(), 2))));
	double BC = fabs(sqrt(pow(B.get_x() - C.get_x(), 2) + (pow(B.get_y() - C.get_y(), 2)) + (pow(B.get_z() - C.get_z(), 2))));
	double AB = fabs(sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)) + (pow(A.get_z() - B.get_z(), 2))));
	if (AC == BC || AC == AB || AB == BC)std::cout << "The triangle is isosceles " << std::endl;
	if (AC == BC&&AC == AB&&AB == BC)std::cout << "The triangle is equilateral " << std::endl;
	if (pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(AB, 2) + pow(BC, 2) == pow(AC, 2) || pow(AC, 2) + pow(BC, 2) == pow(AB, 2))std::cout << "The triangle is right-angled" << std::endl;
	if (pow(AB, 2) + pow(AC, 2)>pow(BC, 2) && pow(AB, 2) + pow(BC, 2)>pow(AC, 2) && pow(AC, 2) + pow(BC, 2)>pow(AB, 2))std::cout << "The triangle is acute-angled" << std::endl;
	if (pow(AB, 2) + pow(AC, 2)<pow(BC, 2) || pow(AB, 2) + pow(BC, 2)<pow(AC, 2) || pow(AC, 2) + pow(BC, 2)<pow(AB, 2))std::cout << "The triangle is obtuse" << std::endl;

}

std::ostream & Triangle::inserter(std::ostream& out)const
{
	out << "First point:" << A << std::endl;
	out << "Second point:" << B << std::endl;
	out << "Third point:" << C << std::endl;
	out << "AC=" << fabs(sqrt(pow(C.get_x() - A.get_x(), 2) + (pow(C.get_y() - A.get_y(), 2)) + (pow(C.get_z() - A.get_z(), 2)))) << std::endl;
	out << "BC=" << fabs(sqrt(pow(B.get_x() - C.get_x(), 2) + (pow(B.get_y() - C.get_y(), 2)) + (pow(B.get_z() - C.get_z(), 2)))) << std::endl;
	out << "AB=" << fabs(sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)) + (pow(A.get_z() - B.get_z(), 2)))) << std::endl;
	return out;
}

double Triangle::TrianglePerimeter()const
{
	double AC = fabs(sqrt(pow(C.get_x() - A.get_x(), 2) + (pow(C.get_y() - A.get_y(), 2)) + (pow(C.get_z() - A.get_z(), 2))));
	double BC = fabs(sqrt(pow(B.get_x() - C.get_x(), 2) + (pow(B.get_y() - C.get_y(), 2)) + (pow(B.get_z() - C.get_z(), 2))));
	double AB = fabs(sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)) + (pow(A.get_z() - B.get_z(), 2))));
	return AC + BC + AB;
}

double Triangle::AreaTriangle()const
{
	double AC = fabs(sqrt(pow(C.get_x() - A.get_x(), 2) + (pow(C.get_y() - A.get_y(), 2)) + (pow(C.get_z() - A.get_z(), 2))));
	/*std::cout << "ac = " << AC << std::endl;*/
	double BC = fabs(sqrt(pow(B.get_x() - C.get_x(), 2) + (pow(B.get_y() - C.get_y(), 2)) + (pow(B.get_z() - C.get_z(), 2))));
	/*std::cout << "bc = " << BC << std::endl;*/
	double AB = fabs(sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)) + (pow(A.get_z() - B.get_z(), 2))));
	//std::cout << "ab = " << AB << std::endl;
	double p = (AC + BC + AB) / 2;

	double area = sqrt((p)*(p - AB)*(p - AC)*(p - BC));
	return area;
}

Point Triangle::centroid()const
{
	double a = (A.get_x() + A.get_y() + A.get_z()) / 3;
	double b = (B.get_x() + B.get_y() + B.get_z()) / 3;
	double c = (C.get_x() + C.get_y() + C.get_z()) / 3;
	return Point(a, b, c);
}
bool operator<(const Point & lhs, const Triangle & rhs)
{
	double OA = fabs(sqrt(pow(rhs.A.get_x() - lhs.get_x(), 2) + pow(rhs.A.get_y() - lhs.get_y(), 2) + pow(rhs.A.get_z() - lhs.get_z(), 2)));
	double OB = fabs(sqrt(pow(rhs.B.get_x() - lhs.get_x(), 2) + pow(rhs.B.get_y() - lhs.get_y(), 2) + pow(rhs.B.get_z() - lhs.get_z(), 2)));
	double OC = fabs(sqrt(pow(rhs.C.get_x() - lhs.get_x(), 2) + pow(rhs.C.get_y() - lhs.get_y(), 2) + pow(rhs.C.get_z() - lhs.get_z(), 2)));
	double sum = OA + OB + OC;
	return sum<rhs.TrianglePerimeter();
}
bool Triangle::operator ==(const Point & p)
{
	Line ab(A, B);
	Line ac(A, C);
	Line bc(B, C);
	return(ab + p || ac + p || bc + p);
}
bool operator >(const Point& lhs, const Triangle & rhs)
{
	double OA = fabs(sqrt(pow(rhs.A.get_x() - lhs.get_x(), 2) + pow(rhs.A.get_y() - lhs.get_y(), 2) + pow(rhs.A.get_z() - lhs.get_z(), 2)));
	double OB = fabs(sqrt(pow(rhs.B.get_x() - lhs.get_x(), 2) + pow(rhs.B.get_y() - lhs.get_y(), 2) + pow(rhs.B.get_z() - lhs.get_z(), 2)));
	double OC = fabs(sqrt(pow(rhs.C.get_x() - lhs.get_x(), 2) + pow(rhs.C.get_y() - lhs.get_y(), 2) + pow(rhs.C.get_z() - lhs.get_z(), 2)));
	double sum = OA + OB + OC;
	return sum>rhs.TrianglePerimeter();
}