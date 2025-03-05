#include<iostream>
#include<fstream>

using namespace std;

int main(){
//datos nombres
const int socios1{8},articulos1{5};
string socios{},articulos{};
string clientela[socios1]{};
string mercancia[articulos1]{};

ifstream nombres;
nombres.open("Nombres.txt");
if (!nombres)
{
    cout<<"No abre el archibo nombres";
    return 1;
}
//carga de datos string
for (int i = 0; i < socios1; i++)
{
    nombres>>clientela[i];
}
for (int i = 0; i < articulos1; i++)
{
    nombres>>mercancia[i];
}

nombres.close();

//datos numericos
double peso{},distancia{};
int cliente{},producto{};
const int fila{8},columna{5};
double m[fila][columna]{}; //matiz para peso
double dist[fila][columna]{}; //matriz para kilometors
int entregas[columna]{};

ifstream datos;
datos.open("Datos.txt");
if (!datos)
{
    cout<<"No abre el archibo datos";
    return 1;
}
//carga datos numericos

while (datos)
{
    datos>>cliente>>producto>>peso>>distancia;

        m[cliente][producto] +=peso; //matiz para peso
        dist[cliente][producto] += distancia; //matriz para kilometors
        (entregas[producto])++; //entregas
        
}
datos.close();


cout<<endl;

//ejercicio 1 
double kilomay{13000};
//Muestro la tabala

for (int i = 0; i < fila; i++)
{
    for (int j = 0; j < columna; j++)
    {
        cout<<"["<<m[i][j]<<"]";
        
    }
    cout<<endl;
}
cout<<endl;
for (int i = 0; i < fila; i++){
    for (int j = 0; j < columna; j++){
        cout<<"["<<dist[i][j]<<"km]";
        
    }
    cout<<endl;
}



//ejercicio 2 

//Muestro los nombres y productos
//mostrar los kilometros
for (int i = 0; i < fila; i++)
{
    for (int j = 0; j < columna; j++)
    {
        cout<<endl;
        if (m[i][j] > kilomay)
        {
          cout<<"Los clientes con mas de 13000 kilos trasportados son: "<<clientela[i]<<endl;
            cout<<"Con el producto: "<<mercancia[j]<<endl;
            cout<<"Con un recorrido total de: "<<dist[i][j]<<endl;
        } 
        cout<<endl;
    }
    cout<<endl;
}

//ejercicio 3

int mayor{};
for (int i = 0; i < fila; i++)
{
    if (entregas[i]>entregas[mayor])
    {
        mayor = i;
    }
    
    
}
cout<<"el producto con mas entregas fue: "<<entregas[mayor]<<endl;

int fmay{},maycol{};
for (int i = 0; i < fila; i++)
{
    for (int j = 0; j < columna; j++)
    {
        if ( dist[i][j] > dist[fmay][maycol])
        {
           fmay = i;
           maycol = j;
        } 
    }
}


    cout<<"El producto con mayor kilometros recorridos es "<<mercancia[maycol]<<" con "<<dist[fmay][maycol]<<" kilometros"<<endl;
    
    return 0;
}
/*  */