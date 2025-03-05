//EJERCIICIO 2

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
    Nodo *aux = pila; 
    pila = pila->siguiente;
    delete aux;
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

void invertir(Nodo *&pila){
    
    if (pila == nullptr || pila->siguiente == nullptr || pila->siguiente->siguiente == nullptr) {
        cout << "La pila no tiene suficientes elementos para invertir." << endl;
        return;
    }
    int a = pop(pila);
    int b = pop(pila);
    push(pila, a);
    push(pila, b);

    

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
    cout << "Los elementos son (antes de invertir) : "<< endl;

    Mostrar(pila);


    if (dim>=3){
        cout<< endl;
        cout << " _________________________________________" <<endl; 
        cout<<endl;
        cout << "Los elementos son (desp de invertir) : "<< endl;
        invertir(pila);
        Mostrar(pila);
}
    return 0;
}