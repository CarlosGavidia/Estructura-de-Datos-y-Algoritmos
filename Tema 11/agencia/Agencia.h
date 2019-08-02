#ifndef _AGENCIA_H
#define _AGENCIA_H

#include "Registro.h"
#include "Cliente.h"
#include "Hotel.h"
#include "diccionario.h"

/**
 Este tipo es un 'alias' a los iteradores del diccionario de 
 hoteles a Registros en el hotel
*/
typedef Diccionario<Hotel, Registro>::Iterator tRefHotel;
/**
 Excepci�n que se se levanta cuando se consulta el alojamiento
 de un cliente no alojado
*/
class EClienteNoAlojado {};

class Agencia {
   public:
     /**
	  Creaci�n de una agencia vac�a
	 */
     Agencia();
	 /**
	   Aloja un cliente en un hotel. Si el cliente ya estaba alojado,
	   previamente lo desaloja.
	   En caso de que el hotel no figure en el sistema, la operaci�n
	   lo da de alta previamente a alojar al cliente en el mismo.
	   @param cliente El cliente a alojar
	   @param hotel El hotel donde se va a alojar al cliente
	 */
	 void aloja(const Cliente& cliente, const Hotel& hotel);
	 /**
	 Desaloja a un cliente. Si no estaba alojado en ning�n sitio,
	 la operaci�n no tiene ning�n efecto.
	 @param cliente El cliente a desalojar
	 */
	 void desaloja(const Cliente& cliente);
	 /**
	 Consulta el hotel en el que est� alojado un cliente. 
	 Si dicho cliente no est� alojado en ning�n sitio, se
	 levanta la excepci�n 'EClienteNoAlojado'
	 @param cliente El cliente cuyo alojamiento quiere consultarse
	 @return El hotel en el que se aloja el cliente
	 */
	 const Hotel& alojamiento(const Cliente& cliente) const;
	 /**
	 Rellena una lista de huespedes alojados en un hotel,
	 ordenada en orden creciente por nombre.
	 Si el hotel no est� dado de alta en el sistema, lo da de alta
	 (en este caso, la lista devuelta ser� la lista vac�a)
	 @param cliente El hotel cuyos huespedes quiere recuperarse
	 @param hs La lista resultante de la operaci�n
	 */
	 void huespedes(const Hotel& hotel, Lista<Cliente>& hs);
	 /**
	 Rellena una lista de todos los hoteles dados de alta en 
	 el sistema.
	 @param listado La lista resultante de la operaci�n
	 */
     void listado_hoteles(Lista<Hotel>& listado) const;  	
    private:
         /* Diccionario que permite mantener, para cada cliente
		 alojado, en qu� hotel se est� alojando*/
		Diccionario<Cliente, Hotel> _alojamientos;
		/* Diccionario que permite mantener, para cada hotel,
		   el conjunto de clientes registrados en el mismo
		   (dichos conjuntos se representan mediante la clase
		   Registro) */
		Diccionario<Hotel, Registro> _hoteles;
		/* Dado un hotel, devuelve un iterador que
		   hace referencia a la entrada de dicho hotel
		   en _hoteles.
		   En caso de que el hotel no aparezca en
		   _hoteles, previamente lo almacena con
		   un registro vac�o. */
		tRefHotel registroHotel(const Hotel& hotel);
};

#endif;