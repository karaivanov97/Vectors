#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Triangle.h"
#include <iostream>
#include <fstream>
#include <exception>
#include "VectorLenghtException.h"
#include "EqualPointException.h"
#include <locale>

using namespace std;

int main() {
	locale::global(locale("Bulgarian"));
	Point p1, p2, p3, p4;
	Vector v1, v2, v3,v4;
	Line l1(p1, p2);
	Line l2(p1, v1);
	Triangle t1(p1, p2, p3);
	unsigned int figure;
	double realnoChislo;
	size_t metod;
	char input = ' ';

Label2: cout << "���� �������� ��� ����������� �����: 1. �����, 2. ������, 3. �����, 4. ����������, 5. �������" << endl;
	cin >> figure;
	switch (figure) {
	case 1:
		cout << "���� �������� ������������ �� �����: " << endl;
		cin >> p1;
		Label1:		cout << "���� �������� �������� �� ������: " << endl <<
			"1. �������� ���� 2 ����� ��������" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cin >> p2;
			if (p1 == p2)
				cout << "��" << endl;
			else {
				cout << "��" << endl;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
				if (input=='y') {
				goto Label1;
			}
			else if (input=='n'){
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		}
		break;
	case 2:
		cout << "�������� ��������� �� �������: " << endl;
		cin >> v1;
		Label3: cout << "���� �������� �������� �� ������: " << endl <<
			"1. ����������� �� ������� �� ������" << endl <<
			"2. ����������� �� ������ �� ������ " << endl <<
			"3. �������� �� ������ ����� ���� ������" << endl <<
			"4. �������� �� ����� ������" << endl <<
			"5. �������� �� ����������� �� ��� �������" << endl <<
			"6. �������� �� ����������������� �� ��� �������" << endl <<
			"7. �������� �� ��� �������" << endl <<
			"8. ��������� �� ������ � ������ �����" << endl <<
			"9. �������� ������������ �� ��� ������� " << endl <<
			"10. �������� ������������ �� ��� �������" << endl <<
			"11. �������� ������������ �� ��� �������" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cout << "��������� �� ������� �:  " << v1.VectorLength() << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 2:try {
		
			cout << "�������� �� ������� �: " << v1.VectorDirection() << endl;
			
		}
			   catch (VectorLenghtException &ex){
				   ex.rep(cerr);
				   cerr << ex.what() << " by " << typeid(ex).name() << endl;
				   system("pause");
				   return 1;
			   }
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 3:
			cout << "���� �������� ������������ �� ����� ������: " << endl;
			cin >> v2;
			cout << "���������� �: " << v1.VectorProjection(v2) << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 4:
			if (v1.ZeroVector() == true) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 5:
			try {
				cout << "���� �������� ������������ �� ����� ������: " << endl;
				cin >> v2;
				if (v1.VectorsParallel(v2) == true) {
					cout << "��" << endl;
				}
				else {
					cout << "��" << endl;
				}
			}
			catch (VectorLenghtException &ex) {
				ex.rep(cerr);
				cerr << ex.what() << " by " << typeid(ex).name() << endl;
				system("pause");
				return 2;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 6:
			try {
				cout << "���� �������� ������������ �� ����� ������: " << endl;
				cin >> v2;
				if (v1.VectorsPerpendicular(v2) == true) {
						cout << "��" << endl;
					}
					else {
						cout << "��" << endl;
					}
			}
			catch (VectorLenghtException &ex) {
				ex.rep(cerr);
				cerr << ex.what() << " by " << typeid(ex).name() << endl;
				system("pause");
				return 3;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 7:
			cout << "���� �������� ������������ �� ����� ������: " << endl;
			cin >> v2;
			cout << v1 + v2 << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 8:
			cout << "���� �������� ������ �����: " << endl;
			cin >> realnoChislo;
			cout << endl;
			cout << v1*realnoChislo;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 9:
			cout << "���� �������� ������������ �� ����� ������: " << endl;
			cin >> v2;
			cout << v1*v2;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 10:
			cout << "���� �������� ������������ �� ����� ������: " << endl;
			cin >> v2;
			v3 = v1^v2;
			cout << v3;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		case 11:
			cout << "���� �������� ������������ �� ����� ������: " << endl;
			cin >> v2;
			cout << "���� �������� ������������ �� ����� ������: " << endl;
			cin >> v3;
			cout << v1(v2, v3);
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
			break;
		}
		break;
	case 3: {
		cout << "���� �������� ������������ �� �����: " << endl;
		cin >> p1;
		cout << "���� �������� ������������ �� �����: " << endl;
		cin >> p2;
		Line l1(p1, p2);
	Label4:	cout << "�������� �������� �� ������: " << endl <<
			"1. �������� �� ������ �� �������" << endl <<
			"2. �������� �� �������� ������" << endl <<
			"3. �������� �� ���� ����� ��� �����" << endl <<
			"4. �������� ���� ������ ����� ���� �� ������ �����" << endl <<
			"5. �������� ���� ������ ����� � ��������� �� ����� �����" << endl <<
			"6. �������� ���� ����� ������� � ����� �����" << endl <<
			"7. �������� ���� ����� ������� ����� �����" << endl <<
			"8. �������� ���� ����� � ���������� � ����� �����" << endl <<
			"9. �������� ���� ����� � ��������������� �� ����� �����" << endl;
		cin >> metod;
		switch (metod) {
		case 1: {
			cout << "������ �� �������: " << endl;
			cout << l1.LineDirection() << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
			break;
		case 2: {
			cout << "�������� ������: ";
			cout << l1.NormalVector() << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			} 
		}
			break;
		case 3: {
			cout << "���� �������� ������������ �� ��� ����� �� ����� �����: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			cout << l1.AngleBetweenLines(l2) << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
				break;
		case 4: {
			cout << "���� �������� ������������ �� �����: " << endl;
			cin >> p3;
			cout << endl;
			if (l1 + p1) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
			break;
		case 5: {
			cout << "���� �������� ������������ �� ��� ����� �� ����� �����: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 || l2) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}

			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
				break;
		case 6: {
			cout << "���� �������� ������������ �� ��� ����� �� ����� �����: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 == l2) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}

			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
				break;
		case 7: {
			cout << "���� �������� ������������ �� ��� ����� �� ����� �����: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 && l2) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
				break;
		case 8: {
			cout << "���� �������� ������������ �� ��� ����� �� ����� �����: " << endl;
			cin >> p3 >> p4;
			Line l2(p3, p4);
			if (l1 != l2) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
				break;
		case 9: {
			cout << "���� �������� ������������ �� ��� ����� �� ����� �����: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 | l2) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
		}
				break;
		}
	}
	
			break;



	case 4: {
		try {
		cout << "���� �������� ������������ ������� ����� �� �����������: " << endl;
		cin >> p1;
		cout << "���� �������� ������������ ������� ����� �� �����������: " << endl;
		cin >> p2;
		cout << "���� �������� ������������ ������� ����� �� �����������: " << endl;
		cin >> p3;
		if (p1 == p2) {
			throw EqualPointException(p1, p2);
		}
		if (p1 == p3) {
			throw EqualPointException(p1, p3);
		}
		if (p2 == p3) {
			throw EqualPointException(p2, p3);
		}

		}
		catch (EqualPointException &ex) {
			ex.rep(cerr);
			cerr << ex.what() << " by " << typeid(ex).name() << endl;
			system("pause");
			return 4;
		} 
		Triangle t1(p1, p2, p3);

		Label5:	cout << "���� �������� �������� �� ������: " << endl <<
				"1. ���������� ���� �� �����������" << endl <<
				"2. �������� �� ������ �� ����������� " << endl <<
				"3. �������� �� ���������� �� ����������� " << endl <<
				"4. �������� �� ����������� �� ����������� " << endl <<
				"5. �������� ���� ����� � �� ������������ �� ����������� " << endl <<
				"6. �������� ���� ����� � ����� ����������� " << endl <<
				"7. �������� ���� ����� ���� ����� ����� �� �������� �� ����������� " << endl;
			cin >> metod;
			switch (metod) {
			case 1:
			cout << "������������ �: ";
			t1.TriangleType();
			cout << endl;
			cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label5;
			}
			else if (input == 'n') {
				cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label2;
				}
				else if (input == 'n') {
					return 0;
				}
			}
				break;
			case 2:
				cout << "������ �� ����������� �: ";
				cout << t1.AreaTriangle();
				cout << endl;
				cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
					cin >> input;
					if (input == 'y') {
						goto Label2;
					}
					else if (input == 'n') {
						return 0;
					}
				}
				break;
			case 3:
				cout << "����������� �� ����������� �: ";
				cout << t1.TrianglePerimeter();
				cout << endl;
				cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
					cin >> input;
					if (input == 'y') {
						goto Label2;
					}
					else if (input == 'n') {
						return 0;
					}
				}
				break;
			case 4:
				cout << "������������ � � ����������: " << endl;
				cout << t1.centroid();
				cout << endl;
				cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
					cin >> input;
					if (input == 'y') {
						goto Label2;
					}
					else if (input == 'n') {
						return 0;
					}
				}
				break;
			case 5:
				cout << "���� �������� ������������ �� �����: " << endl;
				cin >> p1;
				cout << endl;
				if (p1 < t1) {
					cout << "��" << endl;
				}
				else {
					cout << "��" << endl;
				}
				cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
					cin >> input;
					if (input == 'y') {
						goto Label2;
					}
					else if (input == 'n') {
						return 0;
					}
				}
				break;
			case 6:
				cout << "���� �������� ������������ �� �����: " << endl;
				cin >> p1;
				cout << endl;
				if (p1 > t1) {
					cout << "��" << endl;
				}
				else {
					cout << "��" << endl;
				}
				cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
					cin >> input;
					if (input == 'y') {
						goto Label2;
					}
					else if (input == 'n') {
						return 0;
					}
				}
				break;
			case 7:
				cout << "���� �������� ������������ �� �����: " << endl;
				cin >> p1;
				cout << endl;
				if (p1 == t1) {
					cout << "��" << endl;
				}
				else {
					cout << "��" << endl;
				}
				cout << "������� �� �� �������� ���� ��������? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "������� �� �� �������� ��� ����������� �����? (y/n)" << endl;
					cin >> input;
					if (input == 'y') {
						goto Label2;
					}
					else if (input == 'n') {
						return 0;
					}
				}
				break;
			}
	}
		break;
	}
	system("pause");
return 0;
}