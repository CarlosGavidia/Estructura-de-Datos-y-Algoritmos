#include "Foro.h"
using namespace std;

typedef Diccionario<MID,Mensaje>::ConstIterator tCMensajes;
typedef Diccionario<MID,Mensaje>::Iterator tMensajes;

Mensaje::Mensaje( MID id, const string &r, const string &a, const string &c,const Turno & turno): _id(id),_remitente(r),_asunto(a),_cuerpo(c),_turno(turno){}
const MID Mensaje::id()const{return _id;}
	const string & Mensaje::remitente()const{return _remitente;}
	const string & Mensaje::asunto()const{return _asunto;}
	const string & Mensaje::cuerpo()const{return _cuerpo;}
	Turno& Mensaje::turno() {return _turno;}
	bool Mensaje::operator==(const MID&id)const{return _id==id;}
	bool Mensaje::operator!=(const MID&id)const{return _id!=id;}
	bool Mensaje::operator>(const MID&id)const{return _id>id;}
	bool Mensaje::operator<(const MID&id)const{return _id<id;}


	Foro::Foro(){}
	void Foro::envia_mensaje( MID id, const string &r, const string &a, const string &c){
		tMensajes ini = _mensajes.busca(id);
		tMensajes fin =_mensajes.end();
		if (ini!=fin){//error ya existe
			throw EMIDDuplicado();
		}
		_recientes.pon_ppio(id);
		_mensajes.inserta(id,Mensaje(id,r,a,c,_recientes.begin()));
		_numero++;
	}
	const Mensaje& Foro::consulta_mensaje(const MID &id)const{
		tCMensajes ini = _mensajes.cbusca(id);
		tCMensajes fin =_mensajes.cend();
		if (ini==fin){//error no existe
			throw ENoHayMensaje();
		}
		return ini.valor();
	}
	void Foro::elimina_mensaje(const MID&id){//mejorarlo
		tMensajes ini = _mensajes.busca(id);
		tMensajes fin =_mensajes.end();
		if (ini!=fin){
			_recientes.eliminar(ini.valor().turno());
			_mensajes.borra(id);
			_numero--;
		}
	}
	Lista<MID>Foro::recupera_mensajes(int n)const{
		Lista<MID>mensajes;
		Lista<MID>::ConstIterator it =_recientes.cbegin();
		Lista<MID>::ConstIterator fi =_recientes.cend();
		while (n!=0 && it!=fi){
			mensajes.pon_final(it.elem());
			it.next();
			n--;
		}
		return mensajes;
	}
	int Foro::numero_mensajes()const{
		return _numero;
	}