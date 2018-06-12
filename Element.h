#ifndef  ELEMENT_H
#define ELEMENT_H
#include <iostream>
class Element {

public:

	virtual std::ostream& inserter(std::ostream&)const;
};
std::ostream& operator <<(std::ostream&, const Element&);

#endif