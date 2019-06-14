#include <iostream>
#include "dcola.h"
using namespace std;

unsigned int afortunado(unsigned int n, unsigned int m) { //n>=1  m>=2 
	int aux = m;
	DCola<int> d;
	for (int i = 1; i <= n; i++)//rellenamos la doble cola con los numeros
		d.pon_final(i);

	while (n != 1){//cuando solo quede un elemnto en la doble cola
		if (aux == 1){
			d.quita_ppio();
			n--;//habra un elemento menos en nuestra cola doble
			aux = m;//restauramos el valor inicial de aux que es m
		}
		else{
			int numero = d.primero();
			d.quita_ppio();
			d.pon_final(numero);
			aux--;
		}
	}
	return d.primero();//devolvemos el unico elemento que queda
}


int main() {
	int n, m;
	while ((cin >> n)) {
		cin >> m;
		cout << afortunado(n, m) << endl;
	}
	return 0;
}