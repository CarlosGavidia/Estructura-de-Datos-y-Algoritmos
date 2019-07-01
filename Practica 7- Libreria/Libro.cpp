#include "Libro.h"

Libro::Libro(const string & nombre): _nombre(nombre){}
const string& Libro::nombre()const{ 
	return _nombre;
}
	int Libro::hashcode() const{
		return ::h(_nombre);
	}
	bool Libro::operator==(const Libro& l) const{
		return _nombre==l._nombre;
	}
	bool Libro::operator!=(const Libro& l) const{
		return _nombre!=l._nombre;
	}
	bool Libro::operator>(const Libro& l) const{
		return _nombre>l._nombre;
	}
	bool Libro::operator<(const Libro& l) const{
		return _nombre<l._nombre;
	}