#ifndef _REGISTRO_H
#define _REGISTRO_H

#include "Cliente.h"
#include "diccionario.h"
#include "lista.h"

class Registro {
public:
	/*
	  Crea un registro vacío
	*/
	Registro(); 
	/*
	  Registra un cliente en el registro (lo añade al registro)
	  @param c El cliente a registrar
	*/
	void entrada(const Cliente& c); 
	/*
	Hace el 'checkout' de un cliente (es decir, lo elimina del registro)
	@param c El cliente que hace el 'checkout'
	*/
	void salida(const Cliente& c);
	/*
	Rellena una lista con los clientes alojados en el hotel
	@param hs La lista a rellenar
	*/
	void huespedes(Lista<Cliente>& hs) const; 
private:
	/* Valor para el diccionario que implementa
	el registro: no es significativo */
	class Nada {};
	/* Registro */
	Diccionario<Cliente, Nada> _registro;
};

#endif


