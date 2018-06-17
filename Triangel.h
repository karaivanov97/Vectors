#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "Line.h"
class Triangle : public Point
{
public:
	Triangle(Point, Point, Point);
	Triangle(const Triangle&);
	Triangle & operator=(const Triangle &);
	virtual ~Triangle() {}
	void TriangleType()const;
	double TrianglePerimeter()const;
	double AreaTriangle()const;
	Point centroid()const;
	//friend, ������ ������ �� ������ ��� ��������
	//	����� �� � �� �����
	//	�� � ����� �� �����
	//	� � ����� �� �����
	//			� �� ���� �� �� ����������� �������� ���� ���� ������� ��� ���� �������������
	friend bool operator<(const Point &, const Triangle &);
	friend bool operator >(const Point&, const Triangle &);
	virtual std::ostream & inserter(std::ostream&)const;
	bool operator ==(const Point &);

private:
	Point A;
	Point B;
	Point C;
};

#endif // TRIANGLE_H