#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    
    // pila vacia, 0 errores: listos para empezar
    Stack<char> s;
	int errors = 0;
    
    while ( ! cin.eof()) {
        char c = cin.get();
		if (c == '(' || c == '[' || c == '<' || c == '{'){
			s.push(c);
		}
		else if (c == ')'){
			if (!s.empty() && s.top() == '(')
				s.pop();
			else
				errors++;
		}

		else if (c == '}'){
			if (!s.empty() && s.top() == '{')
				s.pop();
			else
				errors++;
		}
		else if (c == '>'){
			if (!s.empty() && s.top() == '<')
				s.pop();
			else
				errors++;
		}
		else if (c == ']'){
			if (!s.empty() && s.top() == '[')
				s.pop();
			else
				errors++;
		}
		
		else if (c == '\n'){
			if (s.empty() && (errors == 0)){
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			while (!s.empty()){
				s.pop();
			}
			
			errors = 0;
		}

        // si c es 
        //    - un paréntesis, llave, mayor-que o corchete de apertura, lo apila
        //    - un paréntesis, llave, menor-que o corchete de cierre, 
        //         si cierra bien con el último apilado, desapila el último
        //         y si no, apunta 1 error
        //    - un fin-de-línea, y 
        //         si la pila está vacía y hay 0 errores, muestra YES
        //         y si no, muestra NO
        //         (y en ambos casos vacía la pila y hace errores=0, para la siguiente vuelta)
        //    - todo lo demás, lo ignora
    }
    
    // en los casos de prueba, siempre hay un '\n' como último caracter
    
    return 0;
}
