#include "BigVector.h"
#include <cmath>
	 
BigVector::BigVector() { }

double BigVector::valorDe(const unsigned long i) const {
	double resul=0;
	if (_vector.contiene(i)){
		resul = _vector.valorPara(i);
	}
	return resul;
}  

void BigVector::ponValor(unsigned long i, double v) {
	_vector.inserta(i, v);
}  
double BigVector::productoEscalar(const BigVector& v) const {
	double resul = 0;	Diccionario<unsigned long, double>::ConstIterator it1 = _vector.cbegin();
	Diccionario<unsigned long, double>::ConstIterator en1 = _vector.cend();
	while (it1 != en1){
		resul += it1.valor()*v.valorDe(it1.clave());
		it1.next();
	}
	return resul;
}
   
