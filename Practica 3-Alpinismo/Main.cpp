#include "arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//importante: si quiero que se modifique un dato (como en el de tiempo aqui), sin &, si quiero que no se modique aunque haga las llamdas para atras pongo &
void tiempoAyudaAux(const Arbin<char>& falda, int tiempo, int &total){
	if (!falda.esVacio()){
		if (falda.raiz()=='X'){
			total=total+(tiempo*2);
		}
		if (!falda.hijoIz().esVacio()){
			
			tiempoAyudaAux(falda.hijoIz(),tiempo+1,total);
		}
		if (!falda.hijoDer().esVacio()){
			
			tiempoAyudaAux(falda.hijoDer(),tiempo+1,total);
		}
		
	}
}
int tiempoAyuda(const Arbin<char>& falda) {
	int tiempo=0,total=0;;
	tiempoAyudaAux(falda,tiempo,total);
	return total;
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}