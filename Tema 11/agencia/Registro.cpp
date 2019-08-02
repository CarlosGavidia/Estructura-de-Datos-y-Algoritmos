#include "Registro.h"

Registro::Registro() {};
     
// Tanto la entrada como la salida delegan
// directamente en las operaciones de a�adir y
// borrar en el diccionario
void Registro::entrada(const Cliente& c) {
   _registro.inserta(c,Nada());	 
}
	 
void Registro::salida(const Cliente& c) {
   _registro.borra(c);
}
    
void Registro::huespedes(Lista<Cliente>& hs) const {
	hs = Lista<Cliente>(); // Se inicializa la lista a la lista vac�a
	// Se itera el diccionario, almacenando en hs las claves, en
	// el orden de aparici�n (asumiendo que el diccionario es un
	// �rbol de b�squeda, se obtendr� los clientes ordenados 
	// en orden creciente por nombre)
  typename Diccionario<Cliente,Nada>::ConstIterator i=_registro.cbegin();
  typename Diccionario<Cliente,Nada>::ConstIterator fin=_registro.cend();
   while(i != fin) {
      hs.pon_final(i.clave());
      i.next();		  
   } 
} 	 
