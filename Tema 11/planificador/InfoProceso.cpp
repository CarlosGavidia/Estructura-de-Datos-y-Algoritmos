#include "InfoProceso.h"

/**
  IMPORTANTE: El iterador debe inicializarse en la lista de inicializaci�n,
  no en el cuerpo del constructor. Si se hicera de la siguiente forma:

   InfoProceso::InfoProceso(const Proceso& proceso, const Turno& turno) :
     _proceso(proceso) {
	   _turno = turno;
	 }

  no funcionar�a, ya que, en este caso, se invocar�a al constructor por defecto
  para 'inicializar' _turno -el constructor por defecto en los iteradores es
  privado.
*/
InfoProceso::InfoProceso(const Proceso& proceso, const Turno& turno) :
	_proceso(proceso), _turno(turno) {}

const Proceso& InfoProceso::proceso() const {
	return _proceso;
}
Turno& InfoProceso::turno() {
	return _turno;
}
