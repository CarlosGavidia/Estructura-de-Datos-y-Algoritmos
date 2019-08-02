#ifndef _INFOPROCESO_H
#define _INFOPROCESO_H

#include "Proceso.h"
#include "lista.h"

/** 
Identificadores de procesos: enteros sin signo
*/
typedef unsigned int PID;
/**
Alias para los iteradores sobre la lista de planificación.
Dichos iteradores se utilizarán para 'apuntar' a la 
posición del proceso en la lista desde la tabla de procesos.
*/
typedef Lista<PID>::Iterator Turno;

/**
Clase utilizada para almacenar la información de los procesos:
aparte de los detalles, se almacena un iterador, que 'apunta'
a la posición del proceso en la lista. Esto permitirá 
mejorar la complejidad de la operación de eliminación
-eliminación en tiempo constante, en lugar de en tiempo
lineal
*/
class InfoProceso {
public:
	/**
	 Operación de creación
	*/
	InfoProceso(const Proceso& proceso, const Turno& turno);
	/**
	Recuperación de los detalles del proceso
	*/
	const Proceso& proceso() const;
	/**
	Recuperación del iterador que apunta a la posición
	del proceso en la lista de planificación
	*/
	Turno& turno();
private:
	 /** Detalles */
  Proceso _proceso;
     /** Posición en la lista */
  Turno _turno;    
};

#endif