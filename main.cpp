#include <iostream>
#include "Recurso1.h"
using namespace std;
void menuCalculadora();
int main() {

    int decision;
    cout<<"Que quieres hacer"<<endl;
    cin>>decision;
    switch(decision){
        case 1:
            cout<<"Recurso 1"<<endl;
            break;
        case 2:
            cout<<"Recurso 2"<<endl;
            break;
        case 3:
            cout<<"Recurso 3"<<endl;
            break;
        case 4:
            cout<<"Recurso 4"<<endl;
            break;
        case 5:
            cout<<"Recurso 5"<<endl;
            break;
        default:
            cout<<"Opcion erronea"<<endl;
            break;
    }
    return 0;


}
void menuCalculadora(){
    int decisionTipo;
    cout << "Bienvenido a la calculadora!" << endl;
    cout << "Con que datos quiere operar?" << endl;
    cout << "1) Tipo entero" << endl;
    cout << "2) Tipo double" << endl;
    switch (decisionTipo) {
        case 1:

    }
}
