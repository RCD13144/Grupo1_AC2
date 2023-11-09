#include <iostream>
#include "Recurso1.h"
#include "Recurso3.h"
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
            menuCalculadora();
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
void menuCalcEnteros(){
    int decisionOperacion;
    bool salir = false;
    Calculadora<int> calcInt = Calculadora<int>();
    int operador1;
    int operador2;
    Matriz<int> m1 = Matriz<int>();
    Matriz<int> m2 = Matriz<int>();
    int nFilas1;
    int nColumnas1;
    int nFilas2;
    int nColumnas2;
    while(!salir){
        cout << "Calculadora de enteros" << endl;
        cout << "1) Suma de numeros" << endl;
        cout << "2) Resta de numeros" << endl;
        cout << "3) Multiplicacion de numeros" << endl;
        cout << "4) Division de numeros" << endl;
        cout << "5) Suma de matrices" << endl;
        cout << "6) Resta de matrices" << endl;
        cout << "7) Multiplicacion de matrices" << endl;
        cout << "8) Division de matriz y un numero" << endl;
        cout << "9) Multiplicacion de matriz y un numero" << endl;
        cout << "10) Salir" << endl;
        cin >> decisionOperacion;
        switch (decisionOperacion) {
            case 1:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.sumar(operador1, operador2) << endl;
                break;
            case 2:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.restar(operador1, operador2) << endl;
                break;
            case 3:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.multiplicar(operador1, operador2) << endl;
                break;
            case 4:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.dividir(operador1, operador2) << endl;
                break;
            case 5:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcInt.sumar(m1, m2).verMatriz();
                break;
            case 6:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcInt.restar(m1, m2).verMatriz();
                break;
            case 7:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcInt.multiplicar(m1, m2).verMatriz();
                break;
            case 8:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcInt.dividir(m1, operador1).verMatriz();
                break;
            case 9:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcInt.multiplicar(m1,operador1).verMatriz();
                break;
            case 10:
                salir = true;
            default:
                cout << "Opcion invalida" << endl;
        }
    }
}
void menuCalcDouble(){
    bool salir = false;
    int decisionOperacion;
    Calculadora<double> calcDouble = Calculadora<double>();
    double operador1;
    double operador2;
    Matriz<double> m1 = Matriz<double>();
    Matriz<double> m2 = Matriz<double>();
    int nFilas1;
    int nColumnas1;
    int nFilas2;
    int nColumnas2;
    while(!salir){
        cout << "Calculadora de Double" << endl;
        cout << "1) Suma de numeros" << endl;
        cout << "2) Resta de numeros" << endl;
        cout << "3) Multiplicacion de numeros" << endl;
        cout << "4) Division de numeros" << endl;
        cout << "5) Suma de matrices" << endl;
        cout << "6) Resta de matrices" << endl;
        cout << "7) Multiplicacion de matrices" << endl;
        cout << "8) Division de matriz y un numero" << endl;
        cout << "9) Multiplicacion de matriz y un numero" << endl;
        cin >> decisionOperacion;
        switch (decisionOperacion) {
            case 1:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.sumar(operador1, operador2) << endl;
                break;
            case 2:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.restar(operador1, operador2) << endl;
                break;
            case 3:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.multiplicar(operador1, operador2) << endl;
                break;
            case 4:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.dividir(operador1, operador2) << endl;
                break;
            case 5:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcDouble.sumar(m1, m2).verMatriz();
                break;
            case 6:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcDouble.restar(m1, m2).verMatriz();
                break;
            case 7:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcDouble.multiplicar(m1, m2).verMatriz();
                break;
            case 8:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcDouble.dividir(m1, operador1).verMatriz();
                break;
            case 9:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcDouble.multiplicar(m1,operador1).verMatriz();
                break;
            case 10:
                salir = true;
            default:
                cout << "Opcion invalida" << endl;
        }
    }
}
void menuCalculadora(){
    int decisionTipo;
    bool salir = false;
    while(!salir){
        cout << "Bienvenido a la calculadora!" << endl;
        cout << "Con que datos quiere operar?" << endl;
        cout << "1) Tipo entero" << endl;
        cout << "2) Tipo double" << endl;
        cout << "3) Salir";
        cin >> decisionTipo;
        switch (decisionTipo) {
            case 1:
                menuCalcEnteros();
                break;
            case 2:
                menuCalcDouble();
                break;
            case 3:
                salir = true;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }

}
