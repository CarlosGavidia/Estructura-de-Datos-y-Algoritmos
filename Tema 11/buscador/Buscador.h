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
	   Crea un buscador vac�o
	 */
	 Buscador();
	 /**
	   Indexa un documento cuyo contenido viene dado por una lista de palabras (t�rminos)
	   @param doc La lista de t�rminos que aparecen en el documento
	 */
     void indexar(const Lista<string>& doc);	
	 /**
	 Recupera todos aquellos documentos que contengan un t�rmino dado
	 @param term El t�rmino de b�squeda
	 @return Una lista con los identificadores de los documentos encontrados
	 */
     const Lista<unsigned long>& buscar(const string& term) const;
	 /**
	 Devuelve la lista de t�rminos que aparecen en un documento (si el documento
	 no existe levanta la excepci�n EDocumentoNoExiste)
	 @param docid El identificador del documento
	 @return Una lista con los t�rminos del documento
	 */
     const Lista<string>& consultar(unsigned int docid) const;	 
private:
	  /* Almac�n de documentos */
   Documentos _documentos;
     /* Indice invertido: asocia cada t�rmino con los documentos que lo contienen*/
   Indice _indice;   
};

#endif