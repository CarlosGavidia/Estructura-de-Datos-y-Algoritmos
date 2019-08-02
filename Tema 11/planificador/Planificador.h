#ifndef _PLANIFICADOR_H
#define _PLANIFICADOR_H

#include "InfoProceso.h"
#include "diccionario.h"
#include <string>
using namespace std;


/**
 Excepción que se levanta cuando se trata de consultar los
 datos de un proceso que no existe.
*/
class ENoHayProceso {};

class Planificador {
public:
   /**
     Creación de un planificador de procesos vacío
   */
   Planificador();
   /**
     Añade un proceso al sistema.
	 @param usuario El propietario del proceso
	 @param descripcion Una descripción del proceso
	 @param ruta La ruta del ejecutable del proceso
	 @eturn El identificador del proceso creado
   */
   PID an_proceso(const string& usuario, const string& descripcion, const string& ruta);
   /**
    Devuelve el identificador del primer proceso en espera de ejecución.
	Levanta la excepción ENoHayProceso si no hay procesos en el sistema
	@return El identificado del proceso
   */
   PID siguiente() const;
   /**
    Realiza las modificaciones necesarias en el planificador asociadas con
	la ejecución del siguiente proceso
   */
   void ejecuta();
   /**
    Consulta los detalles de un proceso.
	En caso de que el proceso no exista, levanta la excepción ENoHayProceso
	@param pid El identificador del proceso
	@return Los detalles del proceso
   */
   const Proceso& detalles(PID pid) const;
   /**
    Elimina un proceso del sistema
	@param pid El identificador del proceso a eliminar
   */
   void termina(PID pid);
   /**
   Devuelve el número de procesos que están esperando en el sistema
   @return Número de procesos en el sistema
   */
   unsigned int num_procesos() const;
private:
	 /** Tabla de procesos, que asocia identificadores con la
	     información necesaria */
   Diccionario<PID, InfoProceso> _procesos;
   /** Lista con los identificadores de procesos que están pendientes
       de ejecución. Los procesos en espera estarán ordenados 
	   por orden de llegada -los más recientes al principio, los 
	   más antiguos al final */
   Lista<PID> _planificacion;
   /** Contador para asignar identificadores de procesos
   */
   unsigned int _pids;
};

#endif