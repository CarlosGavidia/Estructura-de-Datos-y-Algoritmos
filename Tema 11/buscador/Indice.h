#ifndef __INDICE_H

#include "diccionario.h"
#include "lista.h"
#include <string>
using namespace std;

class Indice {
  public:	
    /**
	  Se crea un índice vacío
	*/
    Indice();
	/**
	  Se recupera la lista de documentos asociados con un término
	  @param term El término 
	  @return La lista de identificadores documentos que contienen el término
	*/
    const Lista<unsigned long>& consultar(const string& term) const;
	/**
	  Añade un documento al índice
	  @param docid El identificador del documento a añadir
	  @param contenido Los términos del documento
	*/
    void indexar(unsigned long docid, const Lista<string>& contenido);
  private:
	   /* Indice 'invertido': asocia términos con listas de
	      identificadores de documentos que contienen dichos términos
	   */
    Diccionario<string,Lista<unsigned long>> _indice;  
	   /*
	     Añade el identificador de un documento a la lista
		 de documentos de un término
		 @param docid El identificador del documento
		 @param term El término
	   */
    void indexar(unsigned long docid, const string& term);
	   /*
	     Lista (vacía) que se devuelve cuando se consulta la lista 
		 de documentos asociados a un término que no aparece
		 en el índice
	   */
	const Lista<unsigned long> _NO_RESULTADOS;
};


#endif