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
	virtual ~Line() {}
	//Метод за намиране на посока на правата
	Vector LineDirection()const;
	//Метод за намиране на нормален вектор
	Vector NormalVector()const;
	//Метод за намиране на ъгъл между две прави
	double AngleBetweenLines(const Line&)const;
	//Метод за проверка дали дадена точка лежи на дадената права
	bool operator +(const Point&)const;
	//Метод за проверка дали дадена права е успоредна на друга права
	bool operator ||(const Line&)const;    
	//Метод за проверка дали дадена права съвпада с друга права
	bool operator ==(const Line& rhs)const;
	//Метод за проверка дали дадена права е перпендикулярна на друга права
	bool operator |(const Line&)const;
	//Метод за проверка дали дадена права пресича друга права
	bool operator &&(const Line &)const;
	//Метод за проверка дали дадена права е кръстосана с друга права
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

#endif 