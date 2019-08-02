#include "ConfederacionHidrografica.h"
#include <algorithm>
using namespace std;
    

ConfederacionHidrografica::ConfederacionHidrografica() {}  

void ConfederacionHidrografica::insertar_rio(const string&rio ) {
    if (_rios.contiene(rio)) throw ERioDuplicado();
    else _rios.inserta(rio,Rio());		 
} 


void ConfederacionHidrografica::insertar_pantano(const string& rio, const string& pantano, const float cmax, const float vol ) {
   busca_rio(rio).insertar_pantano(pantano, cmax, vol);
}
     
void ConfederacionHidrografica::embalsar(const string& rio, const string& pantano, const float vol) {
   busca_rio(rio).embalsar(pantano, vol);
}

float ConfederacionHidrografica::embalsado_pantano(const string& rio, const string& pantano) const {
	return busca_rio(rio).embalsado_pantano(pantano);
}

float ConfederacionHidrografica::embalsado_cuenca(const string& rio) const {
	return busca_rio(rio).embalsado_total();
}

void ConfederacionHidrografica::transvasar(const string& rio_origen, const string& pantano_origen, 
	                                       const string& rio_destino, const string& pantano_destino, float vol) {
   if (vol < 0) transvasar(rio_destino, pantano_destino, rio_origen, pantano_origen, -vol);
   else {
     Pantano& p_origen = busca_rio(rio_origen).buscar_pantano(pantano_origen);
	 Pantano& p_destino = busca_rio(rio_destino).buscar_pantano(pantano_destino);
	 if (vol + p_destino.vol() > p_destino.cmax())
		 vol = p_destino.cmax() - p_destino.vol();
	 if (vol > p_origen.vol())
	      vol = p_origen.vol();
	 p_origen.pon_vol(p_origen.vol() - vol);
	 p_destino.pon_vol(p_destino.vol() + vol);
    }
}

Rio& ConfederacionHidrografica::busca_rio(const string& rio) {
   Diccionario<string, Rio>::Iterator irio = _rios.busca(rio);
   Diccionario<string, Rio>::Iterator ifin = _rios.end();
   if (irio != ifin) {
	   return irio.valor();
   }
  else throw ERioNoExiste();
}


const Rio& ConfederacionHidrografica::busca_rio(const string& rio) const {
	Diccionario<string, Rio>::ConstIterator irio = _rios.cbusca(rio);
	Diccionario<string, Rio>::ConstIterator ifin = _rios.cend();
	if (irio != ifin) {
		return irio.valor();
	}
	else throw ERioNoExiste();
}

