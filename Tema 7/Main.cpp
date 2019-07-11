#include "Punto.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	Punto el_mas_lejano(0,0);
	float mayor_distancia = 0;
	float x, y;
	while ((cin >> x)) {
		cin >> y;
		Punto actual = Punto(x, y);
		float distancia_al_origen = sqrt(actual.coordenadaX()*actual.coordenadaX() + actual.coordenadaY()*actual.coordenadaY());
		if (distancia_al_origen > mayor_distancia) {
			el_mas_lejano = actual;
			mayor_distancia = distancia_al_origen;
		}
	}
	cout << "Punto mas lejano: " << el_mas_lejano.coordenadaX() << "," << el_mas_lejano.coordenadaY() << endl; 
	system("pause");
	return 0;
}