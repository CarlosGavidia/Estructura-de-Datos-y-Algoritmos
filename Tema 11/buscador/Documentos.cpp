#include "Documentos.h"

Documentos::Documentos() {}

unsigned long Documentos::almacenar(const Lista<string>& contenido) {
	  // Se almacena un nuevo documento en el almacén. Su identificador
	  // vendrá dado por el valor de _ids
  _documentos.inserta(_ids, Documento(_ids,contenido));
     // Se incrementa el valor de _ids. De esta forma, se asegura que
     // cada documento almacenado tiene un identificador único
  return _ids++;	   
}	

const Documento& Documentos::recuperar(unsigned long id) const {
  Diccionario<unsigned long, Documento>::ConstIterator idoc = _documentos.cbusca(id);	
  Diccionario<unsigned long, Documento>::ConstIterator ifin = _documentos.cend();
  if (idoc != ifin) {  // Existe un documento con identificador 'id'
	   return idoc.valor();  
  }  
  else throw EDocumentoNoExiste(); // No existe tal documento
}

	