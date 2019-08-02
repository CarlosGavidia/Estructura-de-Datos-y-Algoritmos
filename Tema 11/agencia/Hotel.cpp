#include "Hotel.h"

Hotel::Hotel(const string& nombre) : _nombre(nombre) {}

const string& Hotel::nombre() const {
	return _nombre;
}

bool Hotel::operator< (const Hotel& c) const {
	return _nombre < c._nombre;
}

bool Hotel::operator> (const Hotel& c) const {
	return _nombre > c._nombre;
}

bool Hotel::operator== (const Hotel& c) const {
	return _nombre == c._nombre;
}

bool Hotel::operator!= (const Hotel& c) const {
	return _nombre != c._nombre;
}
