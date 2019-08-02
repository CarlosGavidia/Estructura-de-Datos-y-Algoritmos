#include "Agencia.h"

#include<iostream>
using namespace std;

/* Alias para el tipo de los iteradores del diccionario _alojamientos */
typedef Diccionario<Cliente, Hotel>::Iterator tRefCliente;
/* Alias para el tipo de los iteradores constantes del diccionario _alojamientos */
typedef Diccionario<Cliente, Hotel>::ConstIterator tCRefCliente;
/* Alias para el tipo de los iteradores constantes del diccionario _hoteles */
typedef Diccionario<Hotel, Registro>::ConstIterator tCRefHotel;


Agencia::Agencia() {}

void Agencia::aloja(const Cliente& cliente, const Hotel& hotel) {
    /* Antes de alojarlo, hay que desalojarlo, por si estuviera ya alojado 
	   en otro hotel*/
   desaloja(cliente);
    /* Se obtiene un iterador que apunta a la entrada del hotel en
	   el diccionario _hoteles (en caso de que el hotel no est� all�,
	   previamente lo almacena, por lo que el iterador siempre hace
	   referencia a una entrada v�lida) */
   tRefHotel i = registroHotel(hotel);	
     /* Se registra el cliente en el hotel */
   i.valor().entrada(cliente);
     /* Se almacena el alojamiento del cliente */
   _alojamientos.inserta(cliente,i.clave());
}  

void Agencia::desaloja(const Cliente& cliente) {
   tRefCliente i = _alojamientos.busca(cliente);
   tRefCliente fin = _alojamientos.end();
   if (i != fin) { // El cliente est� alojado
	        // Dado que el cliente est� alojado, deber�
	        // existir una entrada para el hotel en el que 
	        // est� alojado en _hoteles. Por tanto,
	        // 'busca(i.valor())' siempre devolver�
	        // un iterador a dicha entrada v�lida. 
	        // El valor devuelto por dicho iterador ser�
	        // el registro de clientes del hotel: por tanto,
	        // habr� que sacar de all� al cliente
	   _hoteles.busca(i.valor()).valor().salida(cliente);
	       // Para finalizar, el cliente debe eliminarse de
	       // _alojamientos
	   _alojamientos.borra(cliente);
   }	
}

void Agencia::huespedes(const Hotel& hotel, Lista<Cliente>& hs) {
   hs = Lista<Cliente>();
      // Se obtiene un iterador que apunta a la entrada para
      // el hotel en _hoteles, almacenando all� el hotel
      // previamente en caso de que no estuviera
   tRefHotel i = registroHotel(hotel);	
      // Se delega la formaci�n de la lista en el registro de clientes 
   i.valor().huespedes(hs);
}

const Hotel& Agencia::alojamiento(const Cliente& cliente) const {
   tCRefCliente i = _alojamientos.cbusca(cliente);
   tCRefCliente fin = _alojamientos.cend();
   if (i != fin) {  // El cliente est� alojado
	   return  i.valor(); 
   }
   else throw EClienteNoAlojado();  // El cliente no est� alojado: error
}

void Agencia::listado_hoteles(Lista<Hotel>& listado) const {
	// Antes que nada, se inicializa el listado a la lista vac�a.
   listado = Lista<Hotel>();
    // Ahora se va iterando el diccionario _hoteles, almacenando en el listado
    // sus claves (que son los hoteles). Asumiendo que el diccionario est�
    // soportado por un �rbol de b�squeda, el listado estar� ordenado en
    // orden ascendente por nombre. 
   tCRefHotel i = _hoteles.cbegin();
   tCRefHotel fin = _hoteles.cend();
   while(i != fin) { 
	   listado.pon_final(i.clave());
	   i.next();
   } 
}  

tRefHotel Agencia::registroHotel(const Hotel& hotel) {
     tRefHotel i = _hoteles.busca(hotel);
     tRefHotel fin = _hoteles.end();
	 if (i == fin) { // El hotel no est� en _hoteles
		    //Por tanto, se inserta, con un registro
		    //vac�o...
		 _hoteles.inserta(hotel,Registro());
		    //... y se obtiene un iterador a la
		    // entrada asociada al mismo (que ahora
		    // s� que va a existir)
		 i = _hoteles.busca(hotel);
	 }
	   // Como consecuencia, se puede asegurar
	   // que el iterador devuelto apunta a la
	   // entrada del hotel en _hoteles
	 return i;
}
