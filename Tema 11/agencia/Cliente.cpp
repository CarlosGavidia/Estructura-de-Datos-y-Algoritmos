#include "Cliente.h"

Cliente::Cliente(const string& nombre): _nombre(nombre) {}

const string& Cliente::nombre() const {
	return _nombre;
}

bool Cliente::operator< (const Cliente& c) const {
	return _nombre < c._nombre;
}

bool Cliente::operator> (const Cliente& c) const {
	return _nombre > c._nombre;
}

bool Cliente::operator== (const Cliente& c) const {
	return _nombre == c._nombre;
}

bool Cliente::operator!= (const Cliente& c) const {
	return _nombre != c._nombre;
}

	