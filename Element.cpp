#include "Element.h"
#include <iostream>

std::ostream& Element::inserter(std::ostream& out)const {
	out << "An element is created. \n";
	return out;
 }

std::ostream& operator <<(std::ostream& lhs, const Element& rhs){
	return rhs.inserter(lhs);
}