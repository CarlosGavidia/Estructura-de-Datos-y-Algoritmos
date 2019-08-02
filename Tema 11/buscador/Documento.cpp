#include "Documento.h"

Documento::Documento(unsigned long id, const Lista<string>& contenido):
     _id(id), _contenido(contenido) {}
 
unsigned long Documento::id() const {
     return _id;	
}

const Lista<string>& Documento::contenido() const {
     return _contenido;	
}
 