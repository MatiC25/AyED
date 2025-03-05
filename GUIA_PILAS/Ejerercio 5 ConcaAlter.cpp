//Ejercico 5

#include <iostream>
#include <stdlib.h>
#include <string.h>
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


void insertar(Nodo*&lista, int n){
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *aux = lista;
    Nodo *aux2;

    while ((aux != NULL) && (aux->dato < n)){
        aux2 = aux;
        aux = aux -> siguiente;
    }
    if (lista == aux){
        lista = nuevo_nodo;
    }
    else{
        aux2 -> siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux;

}

int eliminar(Nodo *&lista, int n){
    int valor = lista->dato;
    if (lista != NULL){
        Nodo *aux;
        Nodo *anterior = NULL;
        aux = lista;

        while ((aux != NULL) && (aux -> dato != n)){
            anterior = aux; 
            aux = aux -> siguiente;
        }
        if(aux == NULL){
            cout<< "El elemento no existe"<<endl;
        }
        else if(anterior == NULL){
            lista = lista -> siguiente;
            delete aux;
        }
        else {
            anterior -> siguiente = aux -> siguiente; 
            delete aux; 
        }
    }
    return valor;
}

void concaInter(Nodo*&lista, Nodo*&lista2,Nodo*&lista3, int dim1){
    Nodo *aux = lista2;
    for (int i=0; i<dim1 ; i++){
        int a = eliminar (lista , i);
        insertar(lista3, a);
        for(int j = 1; j<dim1; j++){
            int b = eliminar (lista2, j);
            insertar(lista3, b);
        }        
    }
    while (aux != NULL){
        int c = aux -> dato;
        insertar(lista2, c );
        aux = aux ->siguiente;
    }

}

void Mostrar(Nodo *&lista){
    Nodo *aux = lista;
    int elemento = 1; 

    while (aux != NULL){
        cout << "["<< elemento++ << "]" <<"ELEMENTO: "<< aux -> dato <<endl;
        aux = aux ->siguiente;
    }
}
int main(){
    int n, dim1=0, dim2= 0; 
    Nodo *lista = NULL;
    Nodo *lista2 = NULL;
    Nodo *lista3 = NULL;
    
    cout << "Digite la cantidad de elementos que quiere en la lista 1: " <<endl;
    cin >>dim1;
    for(int i=0 ; i<dim1; i++){
        cout << "Digite el dato del elemento: "<<endl;
        cin >> n;
        insertar(lista, n );
    }

    cout << "Digite la cantidad de elementos que quiere en la lista 2 (la más grande): " <<endl;
    cin >>dim2;
    for(int i=0 ; i<dim2; i++){
        cout << "Digite el dato del elemento: "<<endl;
        cin >> n;
        insertar(lista2, n );
    }
    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son (lista1): "<< endl;

    Mostrar(lista);
    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son (lista2): "<< endl;

    Mostrar(lista2);

    cout<< endl;
    cout << " _________________________________________" <<endl; 
    cout<<endl;
    cout << "Los elementos son (desp de conca): "<< endl;
    concaInter(lista, lista2, lista3, dim1);
    Mostrar(lista2);


    return 0;
}
