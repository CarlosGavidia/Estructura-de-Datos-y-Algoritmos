#include "indice.h"

Indice::Indice() {}
const Lista<unsigned long>& Indice::consultar(const string& term) const {
    Diccionario<string,Lista<unsigned long>>::ConstIterator iterm = _indice.cbusca(term);
	Diccionario<string, Lista<unsigned long>>::ConstIterator ifin= _indice.cend();
	if (iterm != ifin) { // El término está en el indice: se devuelve su lista
	    return iterm.valor();  	
	}
	else return _NO_RESULTADOS; // El término no aparece en el índice: se devuelve 
	                            // la lista vacía
}
void Indice::indexar(unsigned long docid, const Lista<string>& contenido) {
    Lista<string>::ConstIterator icontenido= contenido.cbegin();
    Lista<string>::ConstIterator ifincontenido= contenido.cend();
	  // Para cada término en el documento, debe añadirse el
	  // id del documento a la lista de documentos para el término
	while(icontenido != ifincontenido) {
	   indexar(docid,icontenido.elem());
       icontenido.next();	   
	}  	
}
void Indice::indexar(unsigned long docid, const string& term) {
	Diccionario<string, Lista<unsigned long>>::Iterator iterm = _indice.busca(term);
	Diccionario<string, Lista<unsigned long>>::Iterator ifin = _indice.end();
	if (iterm == ifin) { 
		//El término NO está en el índice: se añade
		//asociándole una lista que contiene únicamente 
		//el identificador del documento
	    Lista<unsigned long> ldoc;
        ldoc.pon_ppio(docid);
        _indice.inserta(term,ldoc);		
	}
	else {
		   //El término está en el índice: se añade
		   //el id del documento a su lista
        iterm.valor().pon_final(docid);		
	}
}

