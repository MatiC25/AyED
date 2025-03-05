#include <iostream>
#include <fstream>
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"

using namespace std;

struct Cliente{

    int id;
    char cliente[8];
    char producto[10];
    int cantidad;

};

ostream& operator << (ostream &os, const Cliente& a){
    os << a.id << " - " << a.cliente << " - " << a.producto << " - " << a.cantidad;
    return os;
}

int criterio1 (Cliente a, Cliente b){
    return (a.id > b.id) ? 1 : -1;
}

int criterio2 (Cliente a, Cliente b){
    string clienteA(a.cliente);
    string clienteB(b.cliente);
int compareCliente = clienteA.compare(clienteB);
    if(compareCliente != 0){
        return compareCliente;
    }

    string productoA(a.producto);
    string productoB(b.producto);
    
int compareProducto = productoA.compare(productoB);
    if(compareProducto != 0){
        return compareProducto;
    }
    return 0;
}


int main() {
    ifstream archivo;
    archivo.open("G06E02.bin", ios::binary);
    if (!archivo){
        cout << "Error al abrir al archivo: " <<endl;
        return 1;
    }
   

    archivo.seekg(0, ios::end);
    int tamaño = archivo.tellg();
    archivo.seekg(0, ios::beg);

    const int dim = tamaño/((2*sizeof(int))+10+8);
    Cliente v[dim];

    for (int i = 0; i<dim; i++)
    {
    archivo.read(reinterpret_cast<char*>(&v[i].id), sizeof(int));
    archivo.read(v[i].cliente, sizeof(v[i].cliente));
    archivo.read(v[i].producto, sizeof(v[i].producto));
    archivo.read(reinterpret_cast<char*>(&v[i].cantidad), sizeof(int));
    }
    cout<<"---------------------------------------------------------------------";
    cout<<endl;
        for (int i = 0; i < dim; i++) {
        cout << "ID: " << v[i].id << ", Cliente: " << v[i].cliente << ", Producto: " << v[i].producto << ", Cantidad: " << v[i].cantidad << endl;
    }
    cout<<"---------------------------------------------------------------------";
    cout<<endl;

    archivo.close();
    Nodo<Cliente>*lista1 = nullptr;
    Nodo<Cliente>*lista2 = nullptr;

    for (int i=0; i<dim; i++)
    {
        insertar(v[i], lista1 , criterio1);
        insertar(v[i], lista2 , criterio2);
    }

    mostrar(lista1);
    cout << "---------------------------------------"<<endl;
    mostrar(lista2);


    return 0;
}   