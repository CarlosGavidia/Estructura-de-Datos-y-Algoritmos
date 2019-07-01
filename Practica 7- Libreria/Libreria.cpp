#include "Libreria.h"
using namespace std;
typedef Diccionario<Libro,int>::ConstIterator tCLibro;
typedef Diccionario<Libro,int>::Iterator tLibro;
Libreria::Libreria(): _numLibros(0){}
	void Libreria::an_libro(const Libro &l, int n){
		tLibro ini=_libros.busca(l);
		tLibro fin=_libros.end();
		if (ini!=fin){
			ini.valor()=ini.valor()+n;
		}
		else{
			_libros.inserta(l,n);
			_numLibros++;
		}
		
	}
	void Libreria::comprar(const Libro &l){
		tLibro ini=_libros.busca(l);
		tLibro fin=_libros.end();
		if (ini == fin){//libro no existe
		throw ELibroNoExiste();
		}
		else if (ini.clave() == l){
			if (ini.valor() == 0){
				throw ENoHayEjemplares();
			}
			else{
				ini.setVal(ini.valor() - 1);
			}
		}
	}
	bool Libreria::esta_libro(const Libro &l)const{
		bool encontrado=false;
		tCLibro ini=_libros.cbusca(l);
		tCLibro fin=_libros.cend();
		if (ini!=fin)
			encontrado=true;
		return encontrado;
	}
	void Libreria::elim_libro(const Libro &l){
		tLibro ini=_libros.busca(l);
		tLibro fin=_libros.end();
		if (ini!=fin){
			_libros.borra(l);
			_numLibros--;
		}
		
	}
	int Libreria::num_ejemplares(const Libro &l)const{
		int n=0;
		tCLibro ini=_libros.cbusca(l);
		tCLibro fin=_libros.cend();
		if (ini!=fin){
			n=ini.valor();
		}
		else{//error si no esta dado de alta el libro
			throw ELibroNoExiste();
		}
		return n;
	}
	int Libreria::num_libros()const{
		return numLibros();
	}
	const int Libreria::numLibros()const{
		return _numLibros;
	}
