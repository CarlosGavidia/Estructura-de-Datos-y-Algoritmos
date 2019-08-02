#ifndef _INFOPROCESO_H
#define _INFOPROCESO_H

#include "Proceso.h"
#include "lista.h"

/** 
Identificadores de procesos: enteros sin signo
*/
typedef unsigned int PID;
/**
Alias para los iteradores sobre la lista de planificaci�n.
Dichos iteradores se utilizar�n para 'apuntar' a la 
posici�n del proceso en la lista desde la tabla de procesos.
*/
typedef Lista<PID>::Iterator Turno;

/**
Clase utilizada para almacenar la informaci�n de los procesos:
aparte de los detalles, se almacena un iterador, que 'apunta'
a la posici�n del proceso en la lista. Esto permitir� 
mejorar la complejidad de la operaci�n de eliminaci�n
-eliminaci�n en tiempo constante, en lugar de en tiempo
lineal
*/
class InfoProceso {
public:
	/**
	 Operaci�n de creaci�n
	*/
	InfoProceso(const Proceso& proceso, const Turno& turno);
	/**
	Recuperaci�n de los detalles del proceso
	*/
	const Proceso& proceso() const;
	/**
	Recuperaci�n del iterador que apunta a la posici�n
	del proceso en la lista de planificaci�n
	*/
	Turno& turno();
private:
	 /** Detalles */
  Proceso _proceso;
     /** Posici�n en la lista */
  Turno _turno;    
};

#endif