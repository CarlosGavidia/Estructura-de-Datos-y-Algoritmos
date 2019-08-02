#ifndef _HOTEL_H
#define _HOTEL_H

#include <string>
using namespace std;

class Hotel {
public:
	 /* 
	   Crea un hotel a partir de su nombre
	 */
	Hotel(const string& nombre);
	  /*
	    Consulta el nombre
	  */
	const string& nombre() const;
	  /*
	   Operaciones necesarias para que los hoteles
	   puedan ser claves de un diccionario implementado
	   mediante árboles de búsqueda. El orden será
	   por nombre del hotel
	  */
	bool operator< (const Hotel& c) const;
	bool operator> (const Hotel& c) const;
	bool operator== (const Hotel& c) const;
	bool operator!= (const Hotel& c) const;
private:
	string _nombre;
};

#endif