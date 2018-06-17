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

Label2: cout << "Моля изберете вид геометричен обект: 1. Точка, 2. Вектор, 3. Линия, 4. Триъгълник, 5. Отсечка" << endl;
	cin >> figure;
	switch (figure) {
	case 1:
		cout << "Моля въведете координатите на точка: " << endl;
		cin >> p1;
		Label1:		cout << "Моля изберете операция за обекта: " << endl <<
			"1. Проверка дали 2 точки съвпадат" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cin >> p2;
			if (p1 == p2)
				cout << "Да" << endl;
			else {
				cout << "Не" << endl;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
				if (input=='y') {
				goto Label1;
			}
			else if (input=='n'){
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
		cout << "Въведете стойности на вектора: " << endl;
		cin >> v1;
		Label3: cout << "Моля изберете операция за обекта: " << endl <<
			"1. Изчисляване на дължина на вектор" << endl <<
			"2. Изчисляване на посока на вектор " << endl <<
			"3. Проекция на вектор върху друг вектор" << endl <<
			"4. Проверка за нулев вектор" << endl <<
			"5. Проверка за успоредност на два вектора" << endl <<
			"6. Проверка за перпендикулярност на два вектора" << endl <<
			"7. Събиране на два вектора" << endl <<
			"8. Умножение на дектор с реално число" << endl <<
			"9. Скаларно произведение на два вектора " << endl <<
			"10. Векторно произведение на два вектора" << endl <<
			"11. Векторно произведение на три вектора" << endl;
		cin >> metod;
		switch (metod) {
		case 1:
			cout << "Дължината на вектора е:  " << v1.VectorLength() << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
		
			cout << "Посоката на вектора е: " << v1.VectorDirection() << endl;
			
		}
			   catch (VectorLenghtException &ex){
				   ex.rep(cerr);
				   cerr << ex.what() << " by " << typeid(ex).name() << endl;
				   system("pause");
				   return 1;
			   }
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на втори вектор: " << endl;
			cin >> v2;
			cout << "Проекцията е: " << v1.VectorProjection(v2) << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Моля въведете координатите на втори вектор: " << endl;
				cin >> v2;
				if (v1.VectorsParallel(v2) == true) {
					cout << "Да" << endl;
				}
				else {
					cout << "Не" << endl;
				}
			}
			catch (VectorLenghtException &ex) {
				ex.rep(cerr);
				cerr << ex.what() << " by " << typeid(ex).name() << endl;
				system("pause");
				return 2;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Моля въведете координатите на втори вектор: " << endl;
				cin >> v2;
				if (v1.VectorsPerpendicular(v2) == true) {
						cout << "Да" << endl;
					}
					else {
						cout << "Не" << endl;
					}
			}
			catch (VectorLenghtException &ex) {
				ex.rep(cerr);
				cerr << ex.what() << " by " << typeid(ex).name() << endl;
				system("pause");
				return 3;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на втори вектор: " << endl;
			cin >> v2;
			cout << v1 + v2 << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете реално число: " << endl;
			cin >> realnoChislo;
			cout << endl;
			cout << v1*realnoChislo;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на втори вектор: " << endl;
			cin >> v2;
			cout << v1*v2;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на втори вектор: " << endl;
			cin >> v2;
			v3 = v1^v2;
			cout << v3;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на втори вектор: " << endl;
			cin >> v2;
			cout << "Моля въведете координатите на трети вектор: " << endl;
			cin >> v3;
			cout << v1(v2, v3);
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label3;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
		cout << "Моля въведете координатите на точка: " << endl;
		cin >> p1;
		cout << "Моля въведете координатите на точка: " << endl;
		cin >> p2;
		Line l1(p1, p2);
	Label4:	cout << "Изберете операция за обекта: " << endl <<
			"1. Намиране на посока на линията" << endl <<
			"2. Намиране на нормален вектор" << endl <<
			"3. Намиране на ъгъл между две прави" << endl <<
			"4. Проверка дали дадена точка лежи на дадена права" << endl <<
			"5. Проверка дали дадена права е успоредна на друга права" << endl <<
			"6. Проверка дали права съвпада с друга права" << endl <<
			"7. Проверка дали права пресича друга права" << endl <<
			"8. Проверка дали права е кръстосана с друга права" << endl <<
			"9. Проверка дали права е перпендикулярна на друга права" << endl;
		cin >> metod;
		switch (metod) {
		case 1: {
			cout << "Посока на линията: " << endl;
			cout << l1.LineDirection() << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Нормален вектор: ";
			cout << l1.NormalVector() << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на две точки за втора линия: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			cout << l1.AngleBetweenLines(l2) << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на точка: " << endl;
			cin >> p3;
			cout << endl;
			if (l1 + p1) {
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на две точки за втора линия: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 || l2) {
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}

			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на две точки за втора линия: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 == l2) {
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}

			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на две точки за втора линия: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 && l2) {
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на две точки за втора линия: " << endl;
			cin >> p3 >> p4;
			Line l2(p3, p4);
			if (l1 != l2) {
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
			cout << "Моля въведете координатите на две точки за втора линия: " << endl;
			cin >> p3 >> p4;
			cout << endl;
			Line l2(p3, p4);
			if (l1 | l2) {
				cout << "Да" << endl;
			}
			else {
				cout << "Не" << endl;
			}
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label4;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
		cout << "Моля въведете координатите първата точка от триъгълника: " << endl;
		cin >> p1;
		cout << "Моля въведете координатите втората точка от триъгълника: " << endl;
		cin >> p2;
		cout << "Моля въведете координатите третата точка от триъгълника: " << endl;
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

		Label5:	cout << "Моля изберете операция за обекта: " << endl <<
				"1. Определяне вида на триъгълника" << endl <<
				"2. Намиране на лицето на триъгълника " << endl <<
				"3. Намиране на периметъра на триъгълника " << endl <<
				"4. Намиране на медицентъра на триъгълника " << endl <<
				"5. Проверка дали точка е от вътрешността на триъгълника " << endl <<
				"6. Проверка дали точка е извър триъгълника " << endl <<
				"7. Проверка дали точка лежи върху някоя от страните на триъгълника " << endl;
			cin >> metod;
			switch (metod) {
			case 1:
			cout << "Триъгълникът е: ";
			t1.TriangleType();
			cout << endl;
			cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
			cin >> input;
			if (input == 'y') {
				goto Label5;
			}
			else if (input == 'n') {
				cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Лицето на триъгълника е: ";
				cout << t1.AreaTriangle();
				cout << endl;
				cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Периметърът на триъгълника е: ";
				cout << t1.TrianglePerimeter();
				cout << endl;
				cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Медицентърът е с координати: " << endl;
				cout << t1.centroid();
				cout << endl;
				cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Моля въведете координатите на точка: " << endl;
				cin >> p1;
				cout << endl;
				if (p1 < t1) {
					cout << "Да" << endl;
				}
				else {
					cout << "Не" << endl;
				}
				cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Моля въведете координатите на точка: " << endl;
				cin >> p1;
				cout << endl;
				if (p1 > t1) {
					cout << "Да" << endl;
				}
				else {
					cout << "Не" << endl;
				}
				cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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
				cout << "Моля въведете координатите на точка: " << endl;
				cin >> p1;
				cout << endl;
				if (p1 == t1) {
					cout << "Да" << endl;
				}
				else {
					cout << "Не" << endl;
				}
				cout << "Желаете ли да изберете нова операция? (y/n)" << endl;
				cin >> input;
				if (input == 'y') {
					goto Label5;
				}
				else if (input == 'n') {
					cout << "Желаете ли да изберете нов геометричен обект? (y/n)" << endl;
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