#ifndef __INDICE_H

#include "diccionario.h"
#include "lista.h"
#include <string>
using namespace std;

class Indice {
  public:	
    /**
	  Se crea un �ndice vac�o
	*/
    Indice();
	/**
	  Se recupera la lista de documentos asociados con un t�rmino
	  @param term El t�rmino 
	  @return La lista de identificadores documentos que contienen el t�rmino
	*/
    const Lista<unsigned long>& consultar(const string& term) const;
	/**
	  A�ade un documento al �ndice
	  @param docid El identificador del documento a a�adir
	  @param contenido Los t�rminos del documento
	*/
    void indexar(unsigned long docid, const Lista<string>& contenido);
  private:
	   /* Indice 'invertido': asocia t�rminos con listas de
	      identificadores de documentos que contienen dichos t�rminos
	   */
    Diccionario<string,Lista<unsigned long>> _indice;  
	   /*
	     A�ade el identificador de un documento a la lista
		 de documentos de un t�rmino
		 @param docid El identificador del documento
		 @param term El t�rmino
	   */
    void indexar(unsigned long docid, const string& term);
	   /*
	     Lista (vac�a) que se devuelve cuando se consulta la lista 
		 de documentos asociados a un t�rmino que no aparece
		 en el �ndice
	   */
	const Lista<unsigned long> _NO_RESULTADOS;
};


#endif