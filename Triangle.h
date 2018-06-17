#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include "Line.h"
class Triangle : public Point
{
public:
	Triangle(Point, Point, Point);
	Triangle(const Triangle&);
	Triangle & operator=(const Triangle &);
	virtual ~Triangle() {}
	//Метод за определяне на вида на триъгълника
	void TriangleType()const;
	//Метод за изчисляване на периметъра на триъгълника
	double TrianglePerimeter()const;
	//Метод за изчисляване на лицето на триъгълника
	double AreaTriangle()const;
	//Метод за намиране на медицентъра на триъгълника
	Point centroid()const;
	//Метод за проверка дали точка е вътрешността на триъгълника
	//friend, защото трябва да приема ляв аргумент, който не е обект от класа, а е обект от пойнт, и не може да се предефинира оператор като член функция при тези обстоятелства
	friend bool operator<(const Point &, const Triangle &);
	//Метод за проверка дали точка е извън триъгълника
	friend bool operator >(const Point&, const Triangle &);
	//Метод за проверка дали точка лежи върху някоя от страните на триъгълника
	bool operator ==(const Point &);
	virtual std::ostream & inserter(std::ostream&)const;

private:
	Point A;
	Point B;
	Point C;
};

#endif 