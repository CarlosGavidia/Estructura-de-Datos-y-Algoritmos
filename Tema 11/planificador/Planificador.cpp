#include "Planificador.h"

Planificador::Planificador(): _pids(0) {}

PID Planificador::an_proceso(const string& usuario, const string& descripcion, const string& ruta) {
	 // Se consigue el identificador del nuevo proceso
	PID pid = _pids++;
	 // Se añade al PRINCIPIO de la lista
	_planificacion.pon_ppio(pid);
	 //... por tanto, el iterador que 'apunta' a la posición del proceso 
	 // será el devuelto por 'begin'
	Turno turno = _planificacion.begin();
	 // Se inserta la información del proceso en la tabla de procesos
	_procesos.inserta(pid,InfoProceso(Proceso(usuario, descripcion, ruta), turno));
	return pid;
}

PID Planificador::siguiente() const {
	if (_planificacion.esVacia()) throw ENoHayProceso();
	return _planificacion.ultimo(); //porque aparecen primero los más recientes,
	                                //y porque el planificador da prioridad a los
	                                //más antiguos
}

void Planificador::ejecuta() {
	if (!_planificacion.esVacia()) {
		// El proceso a ejecutar es el más antiguo
		PID pid = _planificacion.ultimo(); 
		 // Se elimina de la lista...
		_planificacion.quita_final();
		 //... y también de la tabla de procesos
		_procesos.borra(pid);
	}
}

const Proceso& Planificador::detalles(PID pid) const {
	Diccionario<PID, InfoProceso>::ConstIterator i = _procesos.cbusca(pid);
	Diccionario<PID, InfoProceso>::ConstIterator f = _procesos.cend();
	if (i != f) {
		return i.valor().proceso();
	}
	else throw ENoHayProceso();
}

/**
 IMPORTANTE: Aquí puede apreciarse la técnica de mantener un
 iterador que 'apunta' al elemento de la lista para permitir
 la eliminación de dicho elemento en tiempo constante. 
*/
void Planificador::termina(PID pid) {
	Diccionario<PID, InfoProceso>::Iterator i = _procesos.busca(pid);
	Diccionario<PID, InfoProceso>::Iterator f = _procesos.end();
	if (i != f) {
		  // El iterador nos permite elminiar el proceso
		  // de la lista de planificación en tiempo constante.
		  // Si no mantuvieramos este iterador (que, al fin
		  // y al cabo, es una abstracción del concepto de
		  // 'puntero'), no tendríamos más remedio que
		  // realizar una búsqueda lineal en la lista,
		  // por lo que la complejidad de la operación
		  // aumentaría en un orden de magnitud: pasaría de
		  // se constante a ser lineal.
		_planificacion.eliminar(i.valor().turno());
		_procesos.borra(pid);
	}
	else throw ENoHayProceso();
}


unsigned int Planificador::num_procesos() const {
	return _planificacion.longitud();
}
