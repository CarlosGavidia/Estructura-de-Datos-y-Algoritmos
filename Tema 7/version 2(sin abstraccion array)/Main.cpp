#include "Punto.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	Punto actual;
	Punto el_mas_lejano;
	el_mas_lejano[0] = 0;
	el_mas_lejano[1] = 0;
	float mayor_distancia = 0;
	while ((cin >> actual[0])) {
		cin >> actual[1];
		float distancia_al_origen = sqrt(actual[0]*actual[0] + actual[1]*actual[1]);
		if (distancia_al_origen > mayor_distancia) {
			el_mas_lejano[0] = actual[0];
			el_mas_lejano[1] = actual[1];
			mayor_distancia = distancia_al_origen;
		}
	}
	cout << "Punto mas lejano: " << el_mas_lejano[0] << "," << el_mas_lejano[1] << endl; 
	system("pause");
	return 0;
}