//Parcial Integrador Yamila
#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
//Ejercicio 1
int promedio(int &nota1, int &nota2, int &nota3)
{
    int promedio;
    promedio = (nota1 + nota2 + nota3)/(3);
    return (promedio);
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int suprimir(Nodo *&cfte, Nodo *&cfin);
void insertarOrdenado(Nodo *&lista, int valor);
void insertar(Nodo *&lista, int valor);
Nodo *buscar(Nodo *lista, int valorBuscado);

void vectorOrdenado(int vec[]) {
    int n;
    int pos = 0;

    do {
        cout << "Ingrese los numeros del lote (ingrese 0 para finalizar): ";
        cin >> n;
        if (n != 0) {
            vec[pos++] = n;
        } else {
            break;
        }
    } while (true);

    // Ordenar el vector usando el método de burbuja
    for (int k = 0; k < pos - 1; k++) {
        for (int j = 0; j < pos - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

//Ejercicio 2.a
Nodo *Lista_Union_Colas(Nodo*frente1, Nodo*final1, Nodo*frente2, Nodo*final2){
    Nodo* lista = nullptr;
    int carga;

    while(frente1 != nullptr){
        carga = suprimir(frente1, final1);
        insertarOrdenado(lista,carga);
    }
    while(frente2 != nullptr){
        carga = suprimir(frente2, final2);
        insertarOrdenado(lista, carga);
    }

    return lista;
}

//2.b
void interseccion_cola_lista(Nodo *lista, Nodo*frente, Nodo*final){

    Nodo* aux = nullptr;
    int carga;

    while(frente != nullptr)
    {
        carga = suprimir(frente, final);
        aux = buscar(lista,carga);
            
        if(aux != nullptr)
            {
            insertar(lista, aux->dato);
            }
    }   

}
//Ejercicio 3 
struct Ballotage{
    int codigo_provincia;
    char codigo_partido;
    int cant_votos;
};

int totalVotos(Ballotage vec[], char partido){
    int n = 49; // sabemos que como maximo hay 48 datos en el vector (24 provincias por 2 partidos)
    int totalVotos={};
    for(int i = 0 ; i < n ; i++){
        if(vec[i].codigo_partido == partido){
            totalVotos =+ vec[i].cant_votos;
        }
    }
    return totalVotos;
}

void promB(Ballotage vec[], char partido)
{   
    int n = 49;
    int totalVotos;
    double totalProv;
    for(int i = 0; i < n; i++){
        if(vec[i].codigo_partido == partido){
            totalVotos += vec[i].cant_votos;
            totalProv++;
        }
    }
    if(totalProv > 0){
        cout << "El promedio final por provincia es " << (totalVotos/totalProv);
    }
    else
    {
        cout << "No hay votos en este partido "<<endl;
    }
}

void mayorVotos(Ballotage vec[])
{
    int n = 49;
    int maxVotos;
    int pos;
    for(int i = 0; i > n; i++){
        if(i == 0 || vec[i].cant_votos > maxVotos){
            maxVotos = vec[i].cant_votos;
            pos = i;
        }
    }
    cout << "La cantidad maxima de votos es de " << vec[pos].cant_votos << "de la provincia "<<vec[pos].codigo_provincia << "del partido " << vec[pos].codigo_provincia <<endl;
}

//Ejercicio 4

struct Vector{
    int cod_cabaña;
    int reservas;
    int cantidad;
    float monto;
};

struct Lista{
    int cod_cabaña;
    char benef;
    int cantidad;
    float monto;
};  

struct Nodo{
    Lista dato;
    Nodo* siguiente;
};

int main(){

    Nodo* lista;
    int pos;
    int cabañas = 100;
    Vector vec[cabañas];

    Nodo* aux = lista; 


    while(aux != nullptr){
        if (aux->dato.benef == 'S'){
            pos = busquedaSecuencial(vec, cabañas , aux->dato.cod_cabaña);
            if(pos != -1)
            {
                vec[pos].cantidad =+ aux->dato.cantidad;
                vec[pos].reservas++;
            }
        }
        aux = aux->siguiente;
        liberar(lista);
    }

}
