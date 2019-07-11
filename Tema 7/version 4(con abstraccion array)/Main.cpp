#include "Punto.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	Punto actual;
	Punto el_mas_lejano;
	iniciaPunto(el_mas_lejano, 0, 0);
	float mayor_distancia = 0;
	float x, y;
	while ((cin >> x)) {
		cin >> y;
		iniciaPunto(actual, x, y);
		float distancia_al_origen = sqrt(coordenadaX(actual)*coordenadaX(actual) + coordenadaY(actual)*coordenadaY(actual));
		if (distancia_al_origen > mayor_distancia) {
			actualizaPunto(el_mas_lejano, actual);
			mayor_distancia = distancia_al_origen;
		}
	}
	cout << "Punto mas lejano: " << coordenadaX(el_mas_lejano) << "," << coordenadaY(el_mas_lejano) << endl; 
	system("pause");
	return 0;
}