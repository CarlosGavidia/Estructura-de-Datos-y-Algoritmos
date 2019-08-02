#ifndef __DOCUMENTOS_H
#define __DOCUMENTOS_H


#include "Documento.h"
#include "diccionario.h"
#include "lista.h"

/**
  Excepción que se levanta cuando se recupera un documento que no
  existe
*/
class EDocumentoNoExiste {};
class Documentos {
public:
	/**
	  Crea una base de documentos vacía
	*/
    Documentos();
	/**
	 Almacena un nuevo documento en la base de documentos
	 @param contenido La lista de términos que aparecen en el documento
	 @return El identificador del documento almacenado
	*/
    unsigned long almacenar(const Lista<string>& contenido);
	/**
	Recupera un documento de la lista de documentos. Si el documento
	no existe, se levanta la excepción EDocumentoNoExiste
	@param id El identificador del documento
	@return El documento recuperado
	*/
    const Documento& recuperar(unsigned long id) const; 
private:
	 /* Contador de documentos: su valor permite asignar
	    un identificador único a cada documento almacenado*/
  unsigned long _ids=0;	
    /* Almacén de documentos */
  Diccionario<unsigned long, Documento> _documentos;
};

#endif