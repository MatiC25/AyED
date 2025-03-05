//Ejercicio 1 Listas

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std; 

struct Nodo{
        
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
void dup(Nodo *&pila){
    Nodo *aux = pila;
    int valorTope = pila->dato;
    int a = 0;
   


    if (pila != NULL){
        a = pop(pila);
        push(pila,a);
        push(pila,a);
    }else{
        cout << "No se pudo duplicar, la pila esta vacia: "<<endl;
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
        push( pila, n );
    }
    
    
    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son (antes de duplicar) : "<< endl;

    Mostrar(pila);

    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son (despues de duplicar) : "<< endl;
    dup(pila);
    Mostrar(pila);

    cout<<endl;


    cout<< "El tamaño de la pila es de: " << sizeof(pila);

    
    
    return 0; 
}
 