#ifndef __RIO_H
#define __RIO_H

#include "Pantano.h"
#include "diccionario.h"
#include <string>


/**
 Excepci�n que se levanta cuando se trata de acceder
 a un pantano que no existe.
*/
class EPantanoNoExiste {};

/**
Excepci�n que se levanta cuando se trata de dar de
alta un pantano que ya existe
*/
class EPantanoDuplicado {};

class Rio {
public:

	/**
	 Crea un r�o sin ning�n pantano
	*/
	Rio();
	/**
	  Comprueba si el r�o contiene ya un pantano con un nombre dado.
	  @param pantano Nombre del pantano
	  @return true si el r�o contiene el pantano dado; false en otro caso
	*/
	bool contiene_pantano(const string& pantano) const;

	/**
	Inserta un nuevo pantano con una capacidad m�xima y un volumen inicial.
	Si el pantano ya existe, se levanta la excepci�n EPantanoDuplicado
	@param pantano Nombre del pantano
	@param cmax Capacidad m�xima
	@param vol Volumen inicialmente embalsado
	*/
	void insertar_pantano(const string& pantano, float cmax, float vol);

	/**
	Embalsa un cierto volumen en un pantano del r�o. 
	Si el pantano no existe, se levante la excepci�n EPantanoNoExiste
	Nunca se supera la capacidad m�ximad el pantano (el volumen sobrante se
	ignora)
	Si el volumen es negativo, el volumen total del pantano se decrementa
	@param pantano Nombre del pantano
	@param vol Volumen a embalsar
	*/
	void embalsar(const string& pantano, float vol);


	/**
	Consulta el volumen embalsado en un pantano.
	Si el pantano no existe, se levante la excepci�n EPantanoNoExiste
	@param pantano Nombre del pantano
	@return Volumen embalsado en el pantano
	*/
	float embalsado_pantano(const string& pantano) const;

	/**
	Consulta el total del volumen embalsado en el r�o.
	@return Volumen total embalsado (suma de los vol�menes embalsados en los embalses)
	*/
	float embalsado_total() const;

	/**
	Permite acceder por nombre a un pantano del r�o.
	Si el pantano no existe, se levante la excepci�n EPantanoNoExiste
	@param pantano Nombre del pantano
	@return Una referencia al pantano
	*/
	Pantano& buscar_pantano(const string& pantano);

	/**
	Permite acceder por nombre a un pantano del r�o.
	Si el pantano no existe, se levante la excepci�n EPantanoNoExiste
	@param pantano Nombre del pantano
	@return Una referencia constante al pantano
	*/
	const Pantano& buscar_pantano(const string& pantano) const;

private:
	Diccionario<string, Pantano> _pantanos;
};



#endif // !__RIO_H
