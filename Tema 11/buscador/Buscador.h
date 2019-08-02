#ifndef __BUSCADOR_H
#define __BUSCADOR_H

#include "Documentos.h"
#include "Indice.h"
#include "lista.h"
#include <string>
using namespace std;

class Buscador {
public:
	 /**
	   Crea un buscador vacío
	 */
	 Buscador();
	 /**
	   Indexa un documento cuyo contenido viene dado por una lista de palabras (términos)
	   @param doc La lista de términos que aparecen en el documento
	 */
     void indexar(const Lista<string>& doc);	
	 /**
	 Recupera todos aquellos documentos que contengan un término dado
	 @param term El término de búsqueda
	 @return Una lista con los identificadores de los documentos encontrados
	 */
     const Lista<unsigned long>& buscar(const string& term) const;
	 /**
	 Devuelve la lista de términos que aparecen en un documento (si el documento
	 no existe levanta la excepción EDocumentoNoExiste)
	 @param docid El identificador del documento
	 @return Una lista con los términos del documento
	 */
     const Lista<string>& consultar(unsigned int docid) const;	 
private:
	  /* Almacén de documentos */
   Documentos _documentos;
     /* Indice invertido: asocia cada término con los documentos que lo contienen*/
   Indice _indice;   
};

#endif