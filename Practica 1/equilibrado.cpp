#include <iostream>
#include <string>
#include "pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
	bool equilibrado = true;
	Pila<char>p;
	int i = 0;
	while (i < cadena.length() && equilibrado){
		char c = cadena[i];
		if (c == '(' || c == '[' || c == '{'){
			p.apila(c);
		}
		else if (c==')'){
			if (!p.esVacia() && p.cima() == '('){
				p.desapila();
			}
			else{
				equilibrado = false;
			}
		}
		else if (c == '}'){
			if (!p.esVacia() && p.cima() == '{'){
				p.desapila();
			}
			else{
				equilibrado = false;
			}
		}
		else if (c == ']'){
			if (!p.esVacia() && p.cima() == '['){
				p.desapila();
			}
			else{
				equilibrado = false;
			}
		}
		i++;
	}



	return equilibrado && p.esVacia();
}


/*int main() {
	string cadena;
	while (getline(cin, cadena)) {
		if (esEquilibrada(cadena))
			cout << "EQUILIBRADA" << endl;
		else
			cout << "NO_EQUILIBRADA" << endl;
	}
	return 0;
}*/