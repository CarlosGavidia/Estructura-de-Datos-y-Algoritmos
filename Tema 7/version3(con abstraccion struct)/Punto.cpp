#include "Punto.h"

void iniciaPunto(Punto& punto, float x, float y) {
	punto.x = x;
	punto.y = y;
}

void actualizaPunto(Punto& punto, const Punto& p) {
	punto = p;
}

float coordenadaX(const Punto& punto) {
	return punto.x;
}

float coordenadaY(const Punto& punto) {
	return punto.y;
}
