#ifndef __LIBRO_H
#define __LIBRO_H
#include <string>
#include "hash.h"
using namespace std;
class Libro{
public:
	Libro(const string & nombre);
	const string &nombre()const;
	int hashcode() const;
	bool operator==(const Libro& l) const;
	bool operator!=(const Libro& l) const;
	bool operator>(const Libro& l) const;
	bool operator<(const Libro& l) const;

private:
	string _nombre;
};
#endif // __DICCIO_H
