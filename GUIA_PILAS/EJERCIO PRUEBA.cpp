
// Una compañía que ofrece préstamos a sus clientes a pagar en 12 meses, desea
// obtener un listado con los códigos de clientes y los números de las vec
// adeudadas de aquellos clientes que adeuden vec, ordenado por código de
// cliente. Para ello cuenta con un archivo de cobranzas, sin ningún orden, con el
// siguiente diseño:
// Código de cliente (int)
// Número de cuota (1 a 12)
/*
#include <iostream>
#include <fstream>
#include <stdio.h>
#define DIM_BOOLEANA 12
using namespace std;

struct Cliente{
    int Codigo;
    bool vec[DIM_BOOLEANA]{};
};

struct Nodo{
    Cliente dato;
    Nodo *siguiente;
};

struct Cobranzas{
    int CodDeuda;
    int NumCuota;
};
void BuscarInsertar(Nodo *&Lista, Cobranzas dato)
{
    Nodo *Aux,*Antecesor;
    Aux = Lista;

    while(Aux != NULL && Aux->dato.Codigo < dato.CodDeuda)
    {
        Antecesor = Aux;
        Aux = Aux->siguiente;
    }

    if(Aux != NULL && dato.CodDeuda == Aux->dato.Codigo)
    {
        Aux->dato.vec[dato.NumCuota - 1] = true;
    }
    else
    {
        Nodo *Nuevo = new Nodo;
        Nuevo->dato.Codigo = dato.CodDeuda;
        Nuevo->siguiente = Aux;

        for(int i = 0; i < 12; i++)
        {
            if((dato.NumCuota - 1) == i)
            {
                Aux->dato.vec[i] = true;
            }
            else
            {
                Aux->dato.vec[i] = false;
            }
        }

        if(Aux != Lista)
        {
            Antecesor->siguiente = Nuevo;
        }
        else
        {
            Lista = Nuevo;
        }
    }
}

void MostrarListadoDeDeudores(Nodo *lista)
{
    Nodo *Aux = lista;

    while(Aux != NULL)
    {
        cout << "Codigo de cliente: " << Aux->dato.Codigo << endl;

        for(int i = 0; i < 12; i++)
        {
            if(Aux->dato.vec[i] == false)
            {
                cout << "Nro de cuota: " << i + 1 << endl;
            }
        }

        cout << "---------------------------------" << endl;

        Aux = Aux->siguiente;
    }
}

void procesarArchivo(FILE *archivo, Nodo*&lista){
    Cobranzas DeudaAct;
    fread(&DeudaAct , sizeof(Cobranzas) , 1 , archivo);
    while (!feof(archivo)){
        BuscarInsertar(lista, DeudaAct);
        fread(&DeudaAct , sizeof(Cobranzas) , 1 , archivo);
    }
}

int main(){

    FILE *archivo = fopen("Cobranzas.dat" , "rb"); // rb (reading) wb(writing) ab (posicion del ultimo registro) rb+ (leer y modificar los registros)

    if (archivo == NULL){
        cout << "Error al abri el archivo " <<endl;
        return 1;
    } 
    else
    {
        Nodo *lista1 = NULL;
        procesarArchivo(archivo, lista1);
        MostrarListadoDeDeudores(lista1);
    }

    




}













#include <iostream>
#include <stdio.h>

using namespace std;

struct CobranzasDelArchivo
{
    int CodDeCliente,NroDeCuota;
};

struct NodoCliente
{
    int Info;
    bool Cuotas[12];
    NodoCliente *Sgte;
};

void CargaDeDatos(FILE *ArchivoA,NodoCliente *&Lista);
void BuscarInsertar(NodoCliente *&Lista,int Dato,int NroDeCuota);
void MostrarListadoDeDeudores(NodoCliente *Lista);

int main()
{
    FILE *ArchivoA = fopen("Cobranzas.dat","rb");

    if(ArchivoA == NULL)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        NodoCliente *Lista = NULL;

        CargaDeDatos(ArchivoA,Lista);

        cout << "Listado por codigo de cliente con aquellas cuotas que adeudan: " << endl;

        MostrarListadoDeDeudores(Lista);
    }

    return 0;
}

void CargaDeDatos(FILE *ArchivoA,NodoCliente *&Lista)
{
    CobranzasDelArchivo C;

    fread(&C,sizeof(CobranzasDelArchivo),1,ArchivoA);

    while(!feof(ArchivoA))
    {
        BuscarInsertar(Lista,C.CodDeCliente,C.NroDeCuota);
        fread(&C,sizeof(CobranzasDelArchivo),1,ArchivoA);
    }
}

void BuscarInsertar(NodoCliente *&Lista,int Dato,int NroDeCuota)
{
    NodoCliente *Aux,*Antecesor;
    Aux = Lista;

    while(Aux != NULL && Aux->Info < Dato)
    {
        Antecesor = Aux;
        Aux = Aux->Sgte;
    }

    if(Aux != NULL && Dato == Aux->Info)
    {
        Aux->Cuotas[NroDeCuota - 1] = true;
    }
    else
    {
        NodoCliente *Nuevo = new NodoCliente;
        Nuevo->Info = Dato;
        Nuevo->Sgte = Aux;

        for(int i = 0; i < 12; i++)
        {
            if(NroDeCuota - 1 == i)
            {
                Nuevo->Cuotas[i] = true;
            }
            else
            {
                Nuevo->Cuotas[i] = false;
            }
        }

        if(Aux != Lista)
        {
            Antecesor->Sgte = Nuevo;
        }
        else
        {
            Lista = Nuevo;
        }
    }
}

void MostrarListadoDeDeudores(NodoCliente *Lista)
{
    NodoCliente *Aux = Lista;

    while(Aux != NULL)
    {
        cout << "Codigo de cliente: " << Aux->Info << endl;

        for(int i = 0; i < 12; i++)
        {
            if(Aux->Cuotas[i] == false)
            {
                cout << "Nro de cuota: " << i + 1 << endl;
            }
        }

        cout << "---------------------------------" << endl;

        Aux = Aux->Sgte;
    }
}

*/




/*Se dispone del archivo binario G06E02.bin que contiene una lista no ordenada de órdenes de
compras. Las mismas tienen los siguientes campos: id es un entero con un número que no se
repite en ninguna otra orden. Cliente es un string que se guarda en el archivo binario con un
largo de 8 caracteres. Producto también es string y se guarda con largo 10. Cantidad es un
entero con la cantidad pedida de ese producto por el cliente.
a. Se debe leer el archivo y cargar dos listas, la primera ordenada por cliente y a igualdad de
cliente por producto (siempre ascendente). La otra por id (también ascendente). Luego de
cargar las listas se mostrarán ambas por pantalla.
b. La lista ordenada por id está pensada para consultas, por eso luego de cargar las listas el
programa pedirá un id, lo buscará y mostrará todos los datos de la orden de compra
correspondiente o bien informará que no hay ninguna con ese número. El ciclo se corta
cuando se ingresa un id negativo, ya que todos los id correctos son positivos.
c. Luego se pasa al despacho, para eso se pide al operador un nombre de cliente y un
producto, de haber, se eliminan todos los registros correspondientes de AMBAS listas. A
medida que se borran los registros se van mostrando por pantalla los eliminados, y una vez
que se eliminaron todos los que corresponde, se muestran como quedaron ambas listas.
Esto se hace en un ciclo hasta que se ingresa EOF.
Nota: se provee el archivo G06E02.bin y la salida al mostrar las listas por primera vez.*/

#include <iostream>
#include <fstream>
using namespace std;

struct Consultas{

    int id;
    char cliente [8];
    char producto [10];
    int cantidad;

};

ostream& operator << (ostream &os, const Consultas a){
    os << a.id << " \t " << a.cliente << " \t " << a.producto << " \t " << a.cantidad;
    return os;
}

int criterioCliente(Consultas a, Consultas b){

    if(a.cliente == b.cliente){
        return a.producto > b.producto;
    }
    else{
        return a.cliente > b.cliente;
    }
}

int criterioID(Consultas a, Consultas b){
    return a.id > b.id;
}

void leerarchivo(ifstream& archivo, Consultas v[], int dim ){

cout << "Leyendo Archivo..." << endl;
for (int i = 0; i < dim; i++) {
        archivo.read(reinterpret_cast<char*>(&v[i].id), sizeof(int));
        archivo.read(v[i].cliente, sizeof(v[i].cliente));
        archivo.read(v[i].producto, sizeof(v[i].producto));
        archivo.read(reinterpret_cast<char*>(&v[i].cantidad), sizeof(int));
    }
       
}

void mostrarvec(Consultas vec[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "ID: " << vec[i].id <<endl;
        cout << "Cliente: " << vec[i].cliente << endl;
        cout << "Producto: " << vec[i].producto << endl;
        cout << "Cantidad: " << vec[i].cantidad << endl;
        cout << " ------------------------------------- " << endl;
    }
}

int main(){

    ifstream ordenes;
    ordenes.open("G06E02.bin", ios :: binary);
     if (!ordenes){
        cout << "Error al abrir al archivo ordenes: " <<endl;
        return 1;
    }

    ordenes.seekg(0, ios::end); //Longitud del archivo
    int peso = ordenes.tellg();
    ordenes.seekg(0, ios::beg);
    const int dim = (peso/(10 + 8 + 2*sizeof(int)));

    Consultas vecCompras[dim]{};

    leerarchivo(ordenes,vecCompras,dim);
    ordenes.close();

    mostrarvec(vecCompras,dim);



    return 0;
}