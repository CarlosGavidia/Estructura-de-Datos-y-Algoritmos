#ifndef _CLIENTE_H
#define _CLIENTE_H

#include <string>
using namespace std;

class Cliente {
public:
	/*
	 Crea un cliente a partir de su nombre
	*/
    Cliente(const string& nombre);
	/*
	 Devuelve el nombre de un cliente
	*/
    const string& nombre() const;
	/*
	 Operaciones necesarias para que los clientes
	 puedan ser claves de diccionarios soportados
	 por árboles de búsqueda
	*/
    bool operator< (const Cliente& c) const;	
	bool operator> (const Cliente& c) const;
	bool operator== (const Cliente& c) const;
	bool operator!= (const Cliente& c) const;
private:
   string _nombre;	
};

#endif