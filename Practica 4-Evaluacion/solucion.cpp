#include "diccionario.h"
#include "lista.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
public:
	string alumno;
	int nota;
	Puntuacion(const string& nombre, int puntuacion) : alumno(nombre), nota(puntuacion) {}
};

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	
	Diccionario <string, int> alumnos;
	//Recorremos la lista bien
	Lista<string>::ConstIterator it1 = bien.cbegin();
	while (it1 != bien.cend()){
		Diccionario<string, int> ::Iterator al1 = alumnos.busca(it1.elem());
		if (al1 == alumnos.end()){
			alumnos.inserta(it1.elem(), 1);
		}
		else{
			al1.valor()++;
		}
		it1.next();
	}
	//Recorremos la lista mal
	Lista<string>::ConstIterator it2 = mal.cbegin();
	while (it2 != mal.cend()){
		Diccionario<string, int> ::Iterator al2 = alumnos.busca(it2.elem());
		if (al2 == alumnos.end()){
			alumnos.inserta(it2.elem(), -1);
		}
		else{
			al2.valor()--;
		}
		it2.next();
	}
	//metemos los alumnos disitntos de 0 en la listado
	Diccionario<string, int>::ConstIterator a = alumnos.cbegin();
	while (a != alumnos.cend()){
		if (a.valor() != 0){
			Puntuacion p = Puntuacion(a.clave(), a.valor());
			listado.pon_final(p);
		}
		a.next();
	}

}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
	while (i != e) {
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
	string comienzo;
	while (cin >> comienzo) {
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal, listado);
		imprimePuntuaciones(listado);
	}
	return 0;
}