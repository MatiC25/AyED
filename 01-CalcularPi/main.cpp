//Calcular pi
#include <iostream>
#include <iomanip>
using namespace std; 
int main()
 {
    int i , n;
    
    double pi , denominador;
    
    pi=0; n=1; i=1;   
    
    while (pi <= 0.785398 || pi >= 0.7853982999999){
        denominador=(2*i-1);// 2*i-1 formula de numeros impares 
        pi=pi+n*(1/denominador); //Sumatoria del anterior 
        n = n*(-1); //Alternación de signo al realizar cada suma 
        i++; 
    }
     cout<<"El numero de pi aproximado es de: "<< setprecision(7)<< pi*4; // Setprecision sirve para asignar un numero de digitos especificos
     // Pi por 4 ya que la serie de Leibniz da como resultado pi/4
    
    return 0;
    }
