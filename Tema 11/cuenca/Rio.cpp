#include "Rio.h"
#include <algorithm>

Rio::Rio() {}

bool Rio::contiene_pantano(const string& pantano) const {
	return _pantanos.contiene(pantano);
}
void Rio::insertar_pantano(const string& pantano, float cmax, float vol) {
	if (_pantanos.contiene(pantano)) {
		throw EPantanoDuplicado();
	}
	else {
		_pantanos.inserta(pantano, Pantano(cmax, vol));
	}
}
void Rio::embalsar(const string& pantano, float vol) {
	Pantano& p = buscar_pantano(pantano);
	p.pon_vol(max(0.0F, min(p.cmax(), p.vol() + vol)));
}

float Rio::embalsado_pantano(const string& pantano) const {
	return buscar_pantano(pantano).vol();
}

float Rio::embalsado_total() const {
	Diccionario<string, Pantano>::ConstIterator ipantano = _pantanos.cbegin();
	Diccionario<string, Pantano>::ConstIterator ifin = _pantanos.cend();
	float volumen = 0;
	while (ipantano != ifin) {
		volumen += ipantano.valor().vol();
		ipantano.next();
	}
	return volumen;
}

Pantano& Rio::buscar_pantano(const string& pantano) {
	Diccionario<string, Pantano>::Iterator ipantano = _pantanos.busca(pantano);
	Diccionario<string, Pantano>::Iterator ifin = _pantanos.end();
	if (ipantano != ifin)
		return ipantano.valor();
	else throw EPantanoNoExiste();
}

const Pantano& Rio::buscar_pantano(const string& pantano) const {
	Diccionario<string, Pantano>::ConstIterator ipantano = _pantanos.cbusca(pantano);
	Diccionario<string, Pantano>::ConstIterator ifin = _pantanos.cend();
	if (ipantano != ifin)
		return ipantano.valor();
	else throw EPantanoNoExiste();
}
