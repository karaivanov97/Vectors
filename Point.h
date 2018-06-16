#ifndef  POINT_H
#define POINT_H
#include "Element.h"
#include <iostream>

class Point : public Element {
public:
	Point(double = 0., double = 0., double = 0.);
	Point(const Point &);
	Point & operator=(const Point &);
	bool operator==(const Point &);
	 double get_x() const;
	 double get_y() const;
	 double get_z() const;
	 void set_x(double);
	 void set_y(double);
	 void set_z(double);
	virtual std::ostream& inserter(std::ostream&) const;
	virtual std::istream& extractor(std::istream &);

private:
	double x;
	double y;
	double z;
};

std::istream& operator>>(std::istream&, Point&);
#endif
