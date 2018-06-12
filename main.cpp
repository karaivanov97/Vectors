#include "Element.h"
#include "Point.h"
#include "Vector.h"

#include <iostream>

using namespace std;

int main() {
	Vector v1(0, 0, 0);
	cout << v1;
	cout << v1.VectorLength() << endl;
	system("pause");
	return 0;
}