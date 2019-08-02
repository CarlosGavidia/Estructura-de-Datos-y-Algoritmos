#ifndef __DOCUMENTO_H

#include "lista.h"
#include <string>

using namespace std;

class Documento {
   public:
     /**
	    Creación de un documento
		@param id El identificador del documento
		@param contenido El contenido del documento
	 */
     Documento(unsigned long id, const Lista<string>& contenido);
     /**
	    Consulta del identificador del documento
		@return El identificador único del documento
	 */
     unsigned long id() const;
     /**
	    Consulta del contenido del documento
		@return La lista de palabras del documento
	 */
     const Lista<string>& contenido() const;
   private:
       // Contenido
     Lista<string> _contenido;
	   // ID
     unsigned long _id;	 
};

#endif
