#include "Planificador.h"

Planificador::Planificador(): _pids(0) {}

PID Planificador::an_proceso(const string& usuario, const string& descripcion, const string& ruta) {
	 // Se consigue el identificador del nuevo proceso
	PID pid = _pids++;
	 // Se a�ade al PRINCIPIO de la lista
	_planificacion.pon_ppio(pid);
	 //... por tanto, el iterador que 'apunta' a la posici�n del proceso 
	 // ser� el devuelto por 'begin'
	Turno turno = _planificacion.begin();
	 // Se inserta la informaci�n del proceso en la tabla de procesos
	_procesos.inserta(pid,InfoProceso(Proceso(usuario, descripcion, ruta), turno));
	return pid;
}

PID Planificador::siguiente() const {
	if (_planificacion.esVacia()) throw ENoHayProceso();
	return _planificacion.ultimo(); //porque aparecen primero los m�s recientes,
	                                //y porque el planificador da prioridad a los
	                                //m�s antiguos
}

void Planificador::ejecuta() {
	if (!_planificacion.esVacia()) {
		// El proceso a ejecutar es el m�s antiguo
		PID pid = _planificacion.ultimo(); 
		 // Se elimina de la lista...
		_planificacion.quita_final();
		 //... y tambi�n de la tabla de procesos
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
 IMPORTANTE: Aqu� puede apreciarse la t�cnica de mantener un
 iterador que 'apunta' al elemento de la lista para permitir
 la eliminaci�n de dicho elemento en tiempo constante. 
*/
void Planificador::termina(PID pid) {
	Diccionario<PID, InfoProceso>::Iterator i = _procesos.busca(pid);
	Diccionario<PID, InfoProceso>::Iterator f = _procesos.end();
	if (i != f) {
		  // El iterador nos permite elminiar el proceso
		  // de la lista de planificaci�n en tiempo constante.
		  // Si no mantuvieramos este iterador (que, al fin
		  // y al cabo, es una abstracci�n del concepto de
		  // 'puntero'), no tendr�amos m�s remedio que
		  // realizar una b�squeda lineal en la lista,
		  // por lo que la complejidad de la operaci�n
		  // aumentar�a en un orden de magnitud: pasar�a de
		  // se constante a ser lineal.
		_planificacion.eliminar(i.valor().turno());
		_procesos.borra(pid);
	}
	else throw ENoHayProceso();
}


unsigned int Planificador::num_procesos() const {
	return _planificacion.longitud();
}
