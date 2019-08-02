#ifndef _PROCESO_H
#define _PROCESO_H
#include <string>
using namespace std;

/**
 Detalles del proceso
*/
class Proceso {
public:
	/**
	 Operación de creación
	*/
   Proceso(const string& usuario, const string& descripcion, const string& ruta);
    /** 
	 Operaciones de consulta
	*/
   const string& usuario() const;	
   const string& descripcion() const;	
   const string& ruta() const;	
private:
  string _usuario;       // Nombre del propietario
  string _descripcion;  // Descripción del proceso
  string _ruta;         // Ruta del ejecutable  
};

#endif