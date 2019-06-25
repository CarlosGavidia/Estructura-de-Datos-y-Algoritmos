#ifndef __FORO_H
#define __FORO_H

#include "diccionario.h"
#include "lista.h"
using namespace std;

typedef unsigned int MID;
typedef Lista<MID>::Iterator Turno;
class ENoHayMensaje{};
class EMIDDuplicado{};
class Mensaje{
public:
	Mensaje(MID id, const string &r, const string &a, const string &c,const Turno& turno);
	const MID id()const;
	const string &remitente()const;
	const string &asunto()const;
	const string &cuerpo()const;
	Turno &turno();
	bool operator==(const MID&id)const;
	bool operator!=(const MID&id)const;
	bool operator>(const MID&id)const;
	bool operator<(const MID&id)const;
private:
	MID _id;
	string _remitente;
	string _asunto;
	string _cuerpo;
	Turno _turno;
};
class Foro{
public:
	Foro();
	void envia_mensaje( MID id, const string &r, const string &a, const string &c);
	const Mensaje& consulta_mensaje(const MID &id)const;
	void elimina_mensaje(const MID&id);
	Lista<MID>recupera_mensajes(int n)const;
	int numero_mensajes()const;

private:
	Diccionario<MID,Mensaje>_mensajes;
	Lista<MID>_recientes;
	int _numero;
};

#endif // __DICCIO_H