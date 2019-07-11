#include "Punto.h"

void iniciaPunto(Punto& punto, float x, float y) {
	punto[0] = x;
	punto[1] = y;
}

void actualizaPunto(Punto& punto, const Punto& p) {
	punto[0] = p[0];
	punto[1] = p[1];
}

float coordenadaX(const Punto& punto) {
	return punto[0];
}

float coordenadaY(const Punto& punto) {
	return punto[1];
}
