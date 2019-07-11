#include "Punto.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	Punto actual;
	Punto el_mas_lejano;
	el_mas_lejano.x = 0;
	el_mas_lejano.y = 0;
	float mayor_distancia = 0;
	while ((cin >> actual.x)) {
		cin >> actual.y;
		float distancia_al_origen = sqrt(actual.x*actual.x + actual.y*actual.y);
		if (distancia_al_origen > mayor_distancia) {
			mayor_distancia = distancia_al_origen;
			el_mas_lejano = actual;
		}
	}
	cout << "Punto mas lejano: " << el_mas_lejano.x << "," << el_mas_lejano.y << endl; 
	system("pause");
	return 0;
}