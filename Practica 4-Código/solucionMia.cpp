#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "dcola.h"
#include "pila.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS
bool esVocal(char letra){
	return letra == 'a' || letra == 'e' || letra  == 'o' || letra == 'u' || letra == 'i'
		|| letra == 'A' || letra == 'E' || letra == 'O' || letra == 'U' || letra == 'I';
}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	
	DCola<char> dcola;
	Pila<char> pila;
	Lista<char>::ConstIterator i = mensaje.cbegin();
	Lista<char>::ConstIterator f = mensaje.cend();
	while (i != f){
		char letra = i.elem();
		i.next();
		//vemos si el siguinete elemento es voacl o no:
		if (esVocal(letra)){//si es una vocal
			while (!pila.esVacia()){//revertimos la pila y la ponemos en la cola doble
				dcola.pon_final(pila.cima());
				pila.desapila();
			}
			dcola.pon_final(letra);
		}
		else{//si es consonante, seguimos leyendo(rellenando la pila)
			pila.apila(letra);
		}

	}
	
	//lo que quede por invertir de la pila, lo metemos al reves en la doble cola.
	while (!pila.esVacia()){//revertimos la pila y la ponemos en la cola doble
		dcola.pon_final(pila.cima());
		pila.desapila();
	}

	//ahora recorremos la doble cola para que el mensaje este lo que hay en la doble cola
	Lista<char>::Iterator inicio = mensaje.begin();
	Lista<char>::Iterator final = mensaje.end();
	while (inicio != final && !dcola.esVacia()){
		inicio.set(dcola.primero());
		dcola.quita_ppio();
		inicio.next();
	}

}


// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	Lista<char>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem();
		it.next();
	}
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();    // Esta operacion debe ser implementada como
	// un nuevo metodo de Lista
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}