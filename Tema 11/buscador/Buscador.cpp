#include "Buscador.h"

#include <string>
using namespace std;


Buscador::Buscador() {}

void Buscador::indexar(const Lista<string>& doc) {
	   // Se almacena el documento en la base de documentos,
	   // obteniendo, como resultado, su identificador
	unsigned int docid = _documentos.almacenar(doc); 
	   // Se indexa el documento
   _indice.indexar(docid,doc);	
}	

const Lista<unsigned long>& Buscador::buscar(const string& term) const {
	return _indice.consultar(term); 
}

const Lista<string>& Buscador::consultar(unsigned int docid) const {
	return _documentos.recuperar(docid).contenido();
}	 

