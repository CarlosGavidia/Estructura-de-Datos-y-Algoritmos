#include "Punto.h"

#include <iostream>
using namespace std;

// Main para probar el TAD Punto

int main() {
	Punto p1;
	p1 = Punto(5, 5);
	Punto p2(5, 5);
	cout << boolalpha;
	cout << (p1 == p2) << endl;
	system("pause");
}