//Ejercicio 6 Capicua
/*
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std; 

struct Nodo{
    char dato;
    Nodo *siguiente;
};

void push(Nodo *&pila, char n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo-> dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;  

    cout << "Se ha agregado el elemento ["<<n<< "] correctamente a la pila "<<endl;
}

int pop(Nodo *&pila){
    char valor = pila->dato;
    Nodo *aux_elim = pila; 
    pila = pila->siguiente;
    delete aux_elim;
    return valor;
}


bool Capicua(string palabra){
    Nodo *pila = NULL; 
    int dim = palabra.size();
    int i = 0;
    
    for(int i=0; i<dim; i++){
        push(pila, palabra[i]);
    }

    for (int i = 0; i <(dim && palabra[i] == pop(pila)); i++){
        cout << palabra[i] << " es igual a " << pop(pila) <<endl;

    }
    return i == dim; 

}

int main(){
    string palabra;
    int dim = 0;
    Nodo *pila;
    cout <<"Inserte la palabra que quiera saber si es capicua: "<<endl;
    cin >> palabra;
   
    if (Capicua(palabra)){
        cout << palabra <<" es capicua papa: "<<endl;
    }
    else{
        cout << palabra << " no es capicua forro: "<<endl;
    }
   

    return 0;
}
*/

#include <iostream>
#include <string.h>

using namespace std;

struct Nodo {
    char dato;
    Nodo* siguiente;
};

void push(Nodo*& pila, char n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Se ha agregado el elemento [" << n << "] correctamente a la pila" << endl;
}

char pop(Nodo*& pila) {
    if (pila == nullptr) {
        cerr << "La pila está vacía." << endl;
        return '\0';  // Carácter nulo para indicar un error
    }

    char valor = pila->dato;
    Nodo* aux_elim = pila;
    pila = pila->siguiente;
    delete aux_elim;
    return valor;
}

bool Capicua(string palabra) {
    Nodo* pila = nullptr;
    int dim = palabra.size();
    int i = 0;

    for (int i = 0; i < dim; i++) {
        push(pila, palabra[i]);
    }

    for (int i = 0; i < dim; i++) {
        if (palabra[i] != pop(pila)) {
            return false;
        }
    }
    return true;
}

int main() {
    string palabra;
    cout << "Inserte la palabra que quiera saber si es capicua: " << endl;
    cin >> palabra;

    if (Capicua(palabra)) {
        cout << palabra << " es capicua." << endl;
    }
    else {
        cout << palabra << " no es capicua." << endl;
    }

    return 0;
}
