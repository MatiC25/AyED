#include<iostream>

using namespace std;

int main (){
    int a{},e{},i{},o{},u{};
    string tex;

    cout<<"decime el texto: ";
    getline(cin,tex);

for (char letra: tex)
{
    switch (letra)
    {
    case 'a' : a++;break;
    case 'e' : e++;break;
    case 'i' : i++;break;
    case 'o' : o++;break;
    case 'u' : u++;break;
    }
}
cout<<"a: "<<a<<" e: "<<e<<" i: "<<i<<" o: "<<o<<" u: "<<u;

    return 0;
}
