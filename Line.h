#ifndef LINE_H
#define LINE_H
#include "Vector.h"

class Line : public Vector
{
public:
	Line(Point &, Vector&);
	Line(Point &, Point &);
	Line(const Line&);
	Line & operator=(const Line&);
	Vector LineDirection()const;
	Vector NormalVector()const;
	double AngleBetweenLines(const Line&)const;
	bool operator +(const Point&)const;
	bool operator ||(const Line&)const;    
	bool operator ==(const Line& rhs)const;
	bool operator |(const Line&)const;
	bool operator &&(const Line &)const;
	bool operator !=(const Line&) const;

	void set_a(Point&);
	void set_b(Point&);
	Point get_a()const;
	Point get_b()const;

	virtual std::ostream & inserter(std::ostream&)const;

private:
	Point a;
	Point b;
};

#endif // LINE_H