#include "Proceso.h"

Proceso::Proceso(const string& usuario, const string& descripcion, const string& ruta):
	_usuario(usuario), _descripcion(descripcion), _ruta(ruta) {}

const string& Proceso::usuario() const {
	return _usuario;
}

const string& Proceso::descripcion() const {
	return _descripcion;
}

const string& Proceso::ruta() const {
	return _ruta;
}
