#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Triangel.h"

#include <iostream>

using namespace std;

int main() {
	Point p1, p2, p3, p4;
	Vector v1, v2, v3,v4;
	Line l1(p1, p2);
	Line l2(p1, v1);
	Triangle t1(p1, p2, p3);
	unsigned int figure;
	double realnoChislo;
	size_t metod;
	cout << "Choose a figure: 1. Point 2. Vector 3. Line 4. Triangle";
	cin >> figure;
	switch (figure) {
	case 1:
		cout << "Vuvedi tochka: ";
		cin >> p1;
		cout << "Izberete operaciq za obekta: " << endl <<
			"1. Proverka dali 2 tochki suvpadat" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cin >> p2;
		if(	p1 == p2)
			cout << "yes";
		else {
			cout << "no";
		}
			break;
		}
		break;
	case 2:
		cout << "Vuvedi vektor: ";
		cin >> v1;
		cout << "Izberete operaciq za obekta: " << endl <<
			"1. Izchislqvane na duljina na vektor" << endl <<
			"2. Izchislqvane na posoka na vektor" << endl <<
			"3. Proekciq na vektor vurhu drug vektor" << endl <<
			"4. Proverka za nulev vektor" << endl <<
			"5. Proverka za usporednost na 2 vektora" << endl <<
			"6. Proverka za perpendikulqrnost na 2 vektora" << endl <<
			"7. Subirane na 2 vektora" << endl <<
			"8. Umnojenie na vektor s realno chislo" << endl <<
			"9. Skalarno proizvedenie na 2 vektora " << endl <<
			"10. Vektorno proizvedenie na 2 vektora" << endl <<
			"11. Vektorno proizvedenie na 3 vektora" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cout << "duljinata na vektora e: " << v1.VectorLength();
			break;
		case 2:
			cout << "posokata na vektora e:" << v1.VectorDirection();
			break;
		case 3:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
			cout << "Proekcita e: " << v1.VectorProjection(v2);
			break;
		case 4:
			if (v1.ZeroVector() == true) {
				cout << "yes";
			}
			else {
				cout << "no";
			}
			break;
		case 5:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
			if (v1.VectorsParallel(v2) == true) {
				cout << "yes";
			}
			else {
				cout << "no";
			}
			break;
		case 6:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
			if (v1.VectorsPerpendicular(v2) == true) {
				cout << "yes";
			}
			else {
				cout << "no";
			}
			break;
		case 7:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
			cout << v1 + v2;
			break;
		case 8:
			cout << "Vuvedete realno chilso: " << endl;
			cin >> realnoChislo;
			cout << v1*realnoChislo;
			break;
		case 9:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
			cout << v1*v2;
			break;
		case 10:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
	           v3= v1^v2;
			   cout << v3;
			break;
		case 11:
			cout << "Vuvedete vtori vektor: " << endl;
			cin >> v2;
			cout << "Vuvedete treti vektor: " << endl;
			cin >> v3;
		cout << 	v1(v2, v3);
			break;
		}
		break;
	case 3:
		cout << "Vuvedi tochka: ";
		cin >> p1;
		cout << "Vuvedi tochka: ";
		cin >> p2;
		Line l1(p1, p2); 
		cout << "Izberete operaciq za obekta: " << endl <<
			"1. Namirane posoka na liniqta" << endl <<
			"2. Namirane na normalen vektor" << endl <<
			"3. Namirane na ugul mejdu 2 pravi" << endl <<
			"4. Proverka dali dadena tochka leji na dadenata prava" << endl <<
			"5. Proverka dali dadena prava e usporedna na druga prava" << endl <<
			"6. Proverka dali prava suvpada s druga prava" << endl <<
			"7. Proverka dali prava presicha druga prava" << endl <<
			"8. Proverka dali prava e krustosana s druga prava" << endl <<
			"9. Proverka dali prava e perpendikulqrna na druga prava" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cout << l1;
			cout << "Posoka na liniqta: ";
			cout << l1.LineDirection();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
		break;
	case 4:
		break;
	}

	system("pause");
	return 0;
}