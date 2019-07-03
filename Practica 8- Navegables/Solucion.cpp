#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int numeroTramosNavegablesAux(const Arbin<int>& cuenca, int &sumaNavegables) {
	int sumaCaudal=0;

	if (cuenca.esVacio()){// es vacio
		sumaCaudal = 0;
	}
	else if (cuenca.hijoIz().esVacio() && cuenca.hijoDer().esVacio()){//si es hoja
		sumaCaudal = 1;
	}
	
	else {// si es embalse
		
		int caudalIz = numeroTramosNavegablesAux(cuenca.hijoIz(), sumaNavegables);
		int caudalDr = numeroTramosNavegablesAux(cuenca.hijoDer(), sumaNavegables);
		sumaCaudal = caudalIz + caudalDr;
		if (cuenca.raiz() < 0){
			sumaCaudal += cuenca.raiz();
			if (sumaCaudal < 0) sumaCaudal = 0;
		}
		if (sumaCaudal >= 3)
			sumaNavegables++;
		
	}
	return sumaCaudal;
}
int numeroTramosNavegables(const Arbin<int>& cuenca) {
	int suma=0,caudal;
	if (numeroTramosNavegablesAux(cuenca, suma)>=3){
		suma--;
	}

	return suma;
}

Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF)  {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}