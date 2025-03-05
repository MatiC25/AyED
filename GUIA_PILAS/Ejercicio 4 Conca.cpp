//EJERCICIO 4
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

    cout << "Se ha agregado el elemento ["<<n<< "] correctamente a la pila: "<< "["<< &pila <<"]"<<endl;
}

void pop(Nodo *&pila){
    int valor = pila->dato;
    Nodo *aux_elim = pila; 
    pila = pila->siguiente;
    delete aux_elim;
}

void concatenear(Nodo *&pila, Nodo*&pila2){
    Nodo *conca = pila;

    while (conca !=NULL){
        push (pila2, conca->dato);
        conca = conca->siguiente;
    }

    
}
void Mostrar(Nodo *&pila){
    Nodo *aux = pila;
    int elemento =1; 

    while (aux != NULL){
        cout << "["<< elemento++ << "]" <<"ELEMENTO: "<< aux -> dato <<endl;
        aux = aux ->siguiente;
    }
}
int main(){
    int n, dim=0; 
    Nodo *pila = NULL;
    Nodo *pila2 = NULL;
    Nodo *pila3 = NULL;

    cout << "Digite la cantidad de elementos que quiere en la pilas: " <<endl;
    cin >>dim;
    for(int i=0 ; i<dim; i++){
        cout << "Digite el dato del elemento (PILA 1): "<<endl;
        cin >> n;
        push(pila, n);
    }
    for(int i=0 ; i<dim; i++){
        cout << "Digite el dato del elemento (PILA 2): "<<endl;
        cin >> n;
        push(pila2, n);
    }
    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son : "<< endl;

    Mostrar(pila);
    cout << "------------------------------------------"<<endl;
    concatenear(pila, pila2);
    Mostrar(pila2);

    return 0;
}