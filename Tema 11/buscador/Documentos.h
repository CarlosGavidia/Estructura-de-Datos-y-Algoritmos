#ifndef __DOCUMENTOS_H
#define __DOCUMENTOS_H


#include "Documento.h"
#include "diccionario.h"
#include "lista.h"

/**
  Excepci�n que se levanta cuando se recupera un documento que no
  existe
*/
class EDocumentoNoExiste {};
class Documentos {
public:
	/**
	  Crea una base de documentos vac�a
	*/
    Documentos();
	/**
	 Almacena un nuevo documento en la base de documentos
	 @param contenido La lista de t�rminos que aparecen en el documento
	 @return El identificador del documento almacenado
	*/
    unsigned long almacenar(const Lista<string>& contenido);
	/**
	Recupera un documento de la lista de documentos. Si el documento
	no existe, se levanta la excepci�n EDocumentoNoExiste
	@param id El identificador del documento
	@return El documento recuperado
	*/
    const Documento& recuperar(unsigned long id) const; 
private:
	 /* Contador de documentos: su valor permite asignar
	    un identificador �nico a cada documento almacenado*/
  unsigned long _ids=0;	
    /* Almac�n de documentos */
  Diccionario<unsigned long, Documento> _documentos;
};

#endif