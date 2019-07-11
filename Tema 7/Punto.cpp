#include "Punto.h"

Punto::Punto() {}

Punto::Punto(float x, float y) {
	_x = x;
	_y = y;
}


float Punto::coordenadaX() const {
	return _x;
}

float Punto::coordenadaY() const {
	return _y;
}

bool Punto::operator==(const Punto&p) const {
	return (_x == p._x)
		&&
		(_y == p._y);
}

