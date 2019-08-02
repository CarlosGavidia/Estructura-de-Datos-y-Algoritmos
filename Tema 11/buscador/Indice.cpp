#include "indice.h"

Indice::Indice() {}
const Lista<unsigned long>& Indice::consultar(const string& term) const {
    Diccionario<string,Lista<unsigned long>>::ConstIterator iterm = _indice.cbusca(term);
	Diccionario<string, Lista<unsigned long>>::ConstIterator ifin= _indice.cend();
	if (iterm != ifin) { // El t�rmino est� en el indice: se devuelve su lista
	    return iterm.valor();  	
	}
	else return _NO_RESULTADOS; // El t�rmino no aparece en el �ndice: se devuelve 
	                            // la lista vac�a
}
void Indice::indexar(unsigned long docid, const Lista<string>& contenido) {
    Lista<string>::ConstIterator icontenido= contenido.cbegin();
    Lista<string>::ConstIterator ifincontenido= contenido.cend();
	  // Para cada t�rmino en el documento, debe a�adirse el
	  // id del documento a la lista de documentos para el t�rmino
	while(icontenido != ifincontenido) {
	   indexar(docid,icontenido.elem());
       icontenido.next();	   
	}  	
}
void Indice::indexar(unsigned long docid, const string& term) {
	Diccionario<string, Lista<unsigned long>>::Iterator iterm = _indice.busca(term);
	Diccionario<string, Lista<unsigned long>>::Iterator ifin = _indice.end();
	if (iterm == ifin) { 
		//El t�rmino NO est� en el �ndice: se a�ade
		//asoci�ndole una lista que contiene �nicamente 
		//el identificador del documento
	    Lista<unsigned long> ldoc;
        ldoc.pon_ppio(docid);
        _indice.inserta(term,ldoc);		
	}
	else {
		   //El t�rmino est� en el �ndice: se a�ade
		   //el id del documento a su lista
        iterm.valor().pon_final(docid);		
	}
}

