//EJERCICIO 3 
#include <iostream>
#include <stdlib.h>
using namespace std; 

struct Nodo {
    int dato;
    Nodo *siguiente;

};

void push(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo-> dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;  

    cout << "Se ha agregado el elemento ["<<n<< "] correctamente a la pila "<<endl;
}

int pop(Nodo *&pila){
    int valor = pila->dato;
    Nodo *aux_elim = pila; 
    pila = pila->siguiente;
    delete aux_elim;
    return valor;
}

void Mostrar(Nodo *&pila){
    Nodo *aux = pila;
    int elemento =1; 

    while (aux != NULL){
        cout << "["<< elemento++ << "]" <<"ELEMENTO: "<< aux -> dato <<endl;
        aux = aux ->siguiente;
    }
}

void Rot(Nodo *&pila){
    if (pila == NULL || pila->siguiente == NULL || pila->siguiente->siguiente == NULL) {
        cout << "La pila no tiene suficientes elementos para rotar." << endl;
    }
    else{
        int a = pop(pila);
        int b = pop(pila);
        int c = pop(pila);
        push (pila, b);
        push (pila, a);
        push (pila, c);       
    }
    
}



int main(){
    int n, dim=0; 
    Nodo *pila = NULL;

    cout << "Digite la cantidad de elementos que quiere en la pila: " <<endl;
    cin >>dim;
    for(int i=0 ; i<dim; i++){
        cout << "Digite el dato del elemento: "<<endl;
        cin >> n;
        push(pila, n);
    }
    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son (antes de rotear) : "<< endl;

    Mostrar(pila);

    if (dim>= 3){
        cout<< endl;
        cout << " _________________________________________" <<endl; 
        cout<<endl;
        cout << "Los elementos son (desp de rootear) : "<< endl;

        Rot(pila);
        Mostrar(pila);
    }
    return 0;
}